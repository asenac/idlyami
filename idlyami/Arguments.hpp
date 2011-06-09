// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * Arguments.hpp
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

#ifndef IDLYAMI_ARGUMENTS_HPP
#define IDLYAMI_ARGUMENTS_HPP

namespace idlyami
{

template< typename T >
struct Arg_IN
{
    typedef T type;
};

template< typename T >
struct Arg_OUT
{
    typedef T type;
};

template< typename T >
struct Arg_INOUT
{
    typedef T type;
};

} // idlyami

#endif // IDLYAMI_ARGUMENTS_HPP

