// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * Stub.hpp
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

#ifndef IDLYAMI_STUB_HPP
#define IDLYAMI_STUB_HPP

#include <idlyami/Request.hpp>
#include <idlyami/Parameters.hpp>
#include <idlyami/mapping.hpp>

namespace idlyami
{
namespace stub
{

template< typename T >
struct Arg_IN
{
    typedef typename idlyami::mapping::arg_type< idlyami::Arg_IN< T > >::type type;

    Arg_IN(Request& req, const char * name, type value)
    {
        mapping::helper< T >::set(req.get_parameters(), name, value);
    }

    ~Arg_IN()
    {
    }
};

template< typename T >
struct Arg_OUT
{
    typedef typename idlyami::mapping::arg_type< idlyami::Arg_OUT< T > >::type type;

    Request& m_req;
    const char * m_name;
    type m_val;

    Arg_OUT(Request& req, const char * name, type value)
    : m_req(req), m_name(name), m_val(value)
    {
    }

    ~Arg_OUT()
    {
        mapping::helper< T >::get(m_req.get_reply(), m_name, m_val);
    }
};

template< typename T >
struct Arg_INOUT
{
    typedef typename idlyami::mapping::arg_type< idlyami::Arg_INOUT< T > >::type type;

    Request& m_req;
    const char * m_name;
    type m_val;

    Arg_INOUT(Request& req, const char * name, type value)
    : m_req(req), m_name(name), m_val(value)
    {
        mapping::helper< T >::set(req.get_parameters(), name, value);
    }

    ~Arg_INOUT()
    {
        mapping::helper< T >::get(m_req.get_reply(), m_name, m_val);
    }
};

} // stub
} // idlyami

#endif // IDLYAMI_STUB_HPP

