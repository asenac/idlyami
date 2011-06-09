// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * debug.hpp
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

#ifndef IDLYAMI_DEBUG_HPP
#define IDLYAMI_DEBUG_HPP

#ifdef IDLYAMI_DEBUG
#include <iostream>
#include <unistd.h>
#define DEBUG_MSG( X, Y ) \
std::X << getpid() << ":" <<__FILE__ << ":" <<__LINE__ << ":" << __FUNCTION__ << ": " << Y << std::endl;

#define DEBUG_ERROR( E ) \
    DEBUG_MSG(cerr, E)

#define DEBUG_VERB( L, M ) \
    if(L <= IDLYAMI_DEBUG) \
        DEBUG_MSG(cout, M)

#else
#define DEBUG_MSG( X, Y )
#define DEBUG_ERROR( E )
#define DEBUG_VERB( M, L )
#endif

#endif // IDLYAMI_DEBUG_HPP

