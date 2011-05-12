// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * mapping.hpp
 * Copyright (C) Andrés Senac 2011 <andres@senac.es>
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

#ifndef IDLYAMI_MAPPING_HPP
#define IDLYAMI_MAPPING_HPP

#include <idlyami/Arguments.hpp>
#include <idlyami/detail/mpl.hpp>

namespace idlyami
{
namespace mapping
{

template< typename T >
struct return_type
{
	typedef T type;
};

template< typename T >
struct arg_type
{
	// Error!
};

template< typename T >
struct arg_type< Arg_IN< T > >
{
	typedef T const& type;
};

#define IDLYAMI_DECLARE_PRIMITIVE( primitive ) \
    template< > \
    struct arg_type< Arg_IN< primitive > > \
    { \
        typedef primitive type; \
    }; \
    /***/

IDLYAMI_DECLARE_PRIMITIVE(float)
IDLYAMI_DECLARE_PRIMITIVE(double)
IDLYAMI_DECLARE_PRIMITIVE(int)
IDLYAMI_DECLARE_PRIMITIVE(char)
IDLYAMI_DECLARE_PRIMITIVE(long)
IDLYAMI_DECLARE_PRIMITIVE(long long)
IDLYAMI_DECLARE_PRIMITIVE(short)
IDLYAMI_DECLARE_PRIMITIVE(unsigned int)
IDLYAMI_DECLARE_PRIMITIVE(unsigned char)
IDLYAMI_DECLARE_PRIMITIVE(unsigned long)
IDLYAMI_DECLARE_PRIMITIVE(unsigned long long)
IDLYAMI_DECLARE_PRIMITIVE(unsigned short)

#undef IDLYAMI_DECLARE_PRIMITIVE

template< typename T >
struct arg_type< Arg_OUT< T > >
{
	typedef T& type;
};

template< typename T >
struct arg_type< Arg_INOUT< T > >
{
	typedef T& type;
};

template< typename T >
struct helper
{
    typedef T type;
    typedef typename arg_type< Arg_IN< type > >::type in_type;
    typedef typename arg_type< Arg_OUT< type > >::type out_type;

    template < typename Parameters >
    static inline void set(Parameters* p, const char* name, in_type t)
    {
    }

    template < typename Parameters >
    static inline void get(Parameters* p, const char* name, out_type t)
    {
    }
};

#define IDLYAMI_DECLARE_PRIMITIVE(primitive, method) \
    template< > \
    struct helper< primitive > \
    { \
        typedef primitive type; \
        typedef arg_type< Arg_IN< type > >::type in_type; \
        typedef arg_type< Arg_OUT< type > >::type out_type; \
        template < typename Parameters > \
        static inline void set(Parameters* p, const char* name, in_type t) \
        { \
            p->set_##method(name, t); \
        } \
        template < typename Parameters > \
        static inline void get(Parameters* p, const char* name, out_type t) \
        { \
        	t = p->get_##method(name); \
        } \
    }; \
    /***/

IDLYAMI_DECLARE_PRIMITIVE(float, float)
IDLYAMI_DECLARE_PRIMITIVE(double, double)
IDLYAMI_DECLARE_PRIMITIVE(int, integer)
IDLYAMI_DECLARE_PRIMITIVE(char, char)
IDLYAMI_DECLARE_PRIMITIVE(long, long)
IDLYAMI_DECLARE_PRIMITIVE(long long, long_long)
IDLYAMI_DECLARE_PRIMITIVE(short, short)
IDLYAMI_DECLARE_PRIMITIVE(unsigned int, int)
IDLYAMI_DECLARE_PRIMITIVE(unsigned char, char)
IDLYAMI_DECLARE_PRIMITIVE(unsigned long, long)
IDLYAMI_DECLARE_PRIMITIVE(unsigned long long, long_long)
IDLYAMI_DECLARE_PRIMITIVE(unsigned short, short)

#undef IDLYAMI_DECLARE_PRIMITIVE

} // mapping
} // idlyami

#endif // IDLYAMI_MAPPING_HPP

