// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * Skel.hpp
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

#ifndef IDLYAMI_SKEL_HPP
#define IDLYAMI_SKEL_HPP

#include <idlyami/ServerRequest.hpp>
#include <idlyami/Parameters.hpp>
#include <idlyami/mapping.hpp>

namespace idlyami
{
namespace skel
{

template< typename T >
struct Arg_IN
{
    typedef typename idlyami::mapping::arg_type< idlyami::Arg_IN< T > >::type type;

    T m_val;

    Arg_IN(ServerRequest& req, const char * name)
    {
        mapping::helper< T >::get(req.get_parameters(), name, m_val);
    }

    type val()
    {
        return m_val;
    }

    ~Arg_IN()
    {
    }
};

template< typename T >
struct Arg_OUT
{
    typedef typename idlyami::mapping::arg_type< idlyami::Arg_OUT< T > >::type type;

    ServerRequest& m_req;
    const char * m_name;
    T m_val;

    Arg_OUT(ServerRequest& req, const char * name)
    : m_req(req), m_name(name)
    {
    }

    type val()
    {
        return m_val;
    }

    ~Arg_OUT()
    {
        mapping::helper< T >::set(m_req.get_reply(), m_name, m_val);
    }
};

template< typename T >
struct Arg_INOUT
{
    typedef typename idlyami::mapping::arg_type< idlyami::Arg_INOUT< T > >::type type;

    ServerRequest& m_req;
    const char * m_name;
    T m_val;

    Arg_INOUT(ServerRequest& req, const char * name)
    : m_req(req), m_name(name)
    {
        mapping::helper< T >::get(req.get_parameters(), name, m_val);
    }

    type val()
    {
        return m_val;
    }

    ~Arg_INOUT()
    {
        mapping::helper< T >::set(m_req.get_reply(), m_name, m_val);
    }
};

template< typename T >
struct skel_type
{
    // Error!
};

template< typename T >
struct skel_type< idlyami::Arg_IN< T > >
{
    typedef Arg_IN< T > type;
};

template< typename T >
struct skel_type< idlyami::Arg_OUT< T > >
{
    typedef Arg_OUT< T > type;
};

template< typename T >
struct skel_type< idlyami::Arg_INOUT< T > >
{
    typedef Arg_INOUT< T > type;
};

} // skel
} // idlyami

#endif // IDLYAMI_SKEL_HPP

