// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * any.hpp
 * Andrés Senac 2011 <andres@senac.es>
 *
 * idlyami is free software: you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * idlyami is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef IDLYAMI_ANY_HPP
#define IDLYAMI_ANY_HPP

// Extracted from EMF4CPP
// http://code.google.com/p/emf4cpp/

#include <stdexcept>
#include <string>

namespace idlyami
{
namespace detail
{
typedef ptrdiff_t type_id_t;

// Type identifier class
template< typename T >
struct type_id
{
    static type_id_t id()
    {
        static char c;
        return reinterpret_cast< type_id_t > (&c);
    }
};
} // detail

// Poor man's any class
struct any
{
    struct bad_any_cast: std::runtime_error
    {
        bad_any_cast() :
            std::runtime_error("any::bad_any_cast: failed conversion.")
        {
        }
    };

    any() :
        store_(0)
    {
    }

    template< typename T >
    any(T const& a)
    {
        store_ = new holder< T > (a);
    }

    any(any const& a) :
        store_(a.store_->copy())
    {
    }

    ~any()
    {
        delete store_;
    }

    any& operator=(any const& a)
    {
        delete store_;
        store_ = a.store_->copy();
        return *this;
    }

    template< typename T >
    any& operator=(T const& t)
    {
        delete store_;
        store_ = new holder< T > (t);
        return *this;
    }

    void swap(any& a)
    {
        holder_base* tmp = store_;
        store_ = a.store_;
        a.store_ = tmp;
    }

    bool empty() const
    {
        return store_ == 0;
    }

    detail::type_id_t type() const
    {
        if (!store_)
            return 0;
        return store_->type__id();
    }

    template< typename T >
    static T&
    any_cast(any const& a)
    {
        if (detail::type_id< T >::id() != a.type())
            throw bad_any_cast();

        return dynamic_cast< holder< T >* > (a.store_)->v_;
    }

    template< typename T >
    static T&
    is_a(any const& a)
    {
        return detail::type_id< T >::id() == a.type();
    }

    // Inner classes
    struct holder_base
    {
        virtual ~holder_base()
        {
        }

        virtual detail::type_id_t type__id() const = 0;
        virtual holder_base* copy() const = 0;
    };

    template< typename T >
    struct holder: holder_base
    {
        holder(T const& v) :
            v_(v)
        {
        }

        detail::type_id_t type__id() const
        {
            return detail::type_id< T >::id();
        }

        holder_base* copy() const
        {
            return new holder< T > (v_);
        }

        // Value
        T v_;
    };

    // storage
    holder_base* store_;
};

} // idlyami

#endif // IDLYAMI_ANY_HPP

