// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * adapted.hpp
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

#ifndef IDLYAMI_ADAPTED_HPP
#define IDLYAMI_ADAPTED_HPP

namespace idlyami
{
namespace adapted
{

template< typename T >
struct size
{
    static const unsigned int value = 0;
};

template< typename T, unsigned int index >
struct at
{
    /*
    static inline type& call(T& t)
    {
        return t.a;
    }
    */
};

template< typename T, unsigned int index >
struct name
{
    /*
    static inline const char* call()
    {
        return "name";
    }
    */
};

} // adapted
} // idlyami

#endif // IDLYAMI_ADAPTED_HPP

