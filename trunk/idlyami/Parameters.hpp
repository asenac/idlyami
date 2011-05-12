// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * Parameters.hpp
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

#ifndef IDLYAMI_PARAMETERS_HPP
#define IDLYAMI_PARAMETERS_HPP

#include <string>
#include <idlyami/yami_forward.hpp>

namespace idlyami
{

class Parameters
{
public:
    Parameters(yami::core::parameters* core);
    Parameters(yami::parameters* impl);
    virtual ~Parameters();

    void set_boolean(const std::string & name, bool value);
    void set_boolean(const char * name, bool value);

    bool get_boolean(const std::string & name) const;
    bool get_boolean(const char * name) const;

    void set_integer(const std::string & name, int value);
    void set_integer(const char * name, int value);

    int get_integer(const std::string & name) const;
    int get_integer(const char * name) const;

    void set_long_long(const std::string & name, long long value);
    void set_long_long(const char * name, long long value);

    long long get_long_long(const std::string & name) const;
    long long get_long_long(const char * name) const;

    void set_double_float(const std::string & name, double value);
    void set_double_float(const char * name, double value);

    double get_double_float(const std::string & name) const;
    double get_double_float(const char * name) const;

    void set_string(const std::string & name, const std::string & value);
    void set_string(const char * name, const char * value);

    void set_string_shallow(const std::string & name, const char * value,
            std::size_t value_length);
    void set_string_shallow(const char * name, std::size_t name_length,
            const char * value, std::size_t value_length);

    std::string get_string(const std::string & name) const;
    std::string get_string(const char * name) const;

    const char
            * get_string(const std::string & name, std::size_t & length) const;
    const char * get_string(const char * name, std::size_t & length) const;

    void set_binary(const std::string & name, const void * value,
            std::size_t value_length);
    void set_binary(const char * name, const void * value,
            std::size_t value_length);

    void set_binary_shallow(const std::string & name, const void * value,
            std::size_t value_length);
    void set_binary_shallow(const char * name, std::size_t name_length,
            const void * value, std::size_t value_length);

    const void
            * get_binary(const std::string & name, std::size_t & length) const;
    const void * get_binary(const char * name, std::size_t & length) const;

    void set_boolean_array(const std::string & name, const bool * values,
            std::size_t array_length);
    void set_boolean_array(const char * name, const bool * values,
            std::size_t array_length);

    void set_boolean_array_shallow(const std::string & name,
            const bool * values, std::size_t array_length);
    void set_boolean_array_shallow(const char * name, const bool * values,
            std::size_t array_length);

    bool
            * get_boolean_array(const std::string & name, std::size_t & length) const;
    bool
            * get_boolean_array(const char * name, std::size_t & array_length) const;

    void set_integer_array(const std::string & name, const int * values,
            std::size_t array_length);
    void set_integer_array(const char * name, const int * values,
            std::size_t array_length);

    void set_integer_array_shallow(const std::string & name,
            const int * values, std::size_t array_length);
    void set_integer_array_shallow(const char * name, const int * values,
            std::size_t array_length);

    int * get_integer_array(const std::string & name,
            std::size_t & array_length) const;
    int * get_integer_array(const char * name, std::size_t & array_length) const;

    void set_long_long_array(const std::string & name,
            const long long * values, std::size_t array_length);
    void set_long_long_array(const char * name, const long long * values,
            std::size_t array_length);

    void set_long_long_array_shallow(const std::string & name,
            const long long * values, std::size_t array_length);
    void set_long_long_array_shallow(const char * name,
            const long long * values, std::size_t array_length);

    long long * get_long_long_array(const std::string & name,
            std::size_t & array_length) const;
    long long * get_long_long_array(const char * name,
            std::size_t & array_length) const;

    void set_double_float_array(const std::string & name,
            const double * values, std::size_t array_length);
    void set_double_float_array(const char * name, const double * values,
            std::size_t array_length);

    void set_double_float_array_shallow(const std::string & name,
            const double * values, std::size_t array_length);
    void set_double_float_array_shallow(const char * name,
            const double * values, std::size_t array_length);

    double * get_double_float_array(const std::string & name,
            std::size_t & array_length) const;
    double * get_double_float_array(const char * name,
            std::size_t & array_length) const;

    void
            create_string_array(const std::string & name,
                    std::size_t array_length);
    void create_string_array(const char * name, std::size_t array_length);

    void set_string_in_array(const std::string & name, std::size_t index,
            const std::string & value);
    void set_string_in_array(const char * name, std::size_t index,
            const char * value);

    std::size_t get_string_array_length(const std::string & name) const;
    std::size_t get_string_array_length(const char * name) const;

    std::string
            get_string_in_array(const std::string & name, std::size_t index) const;
    std::string get_string_in_array(const char * name, std::size_t index) const;

    const char * get_string_in_array(const std::string & name,
            std::size_t index, std::size_t & length) const;
    const char * get_string_in_array(const char * name, std::size_t index,
            std::size_t & length) const;

    void
            create_binary_array(const std::string & name,
                    std::size_t array_length);
    void create_binary_array(const char * name, std::size_t array_length);

    void set_binary_in_array(const std::string & name, std::size_t index,
            const void * value, std::size_t value_length);
    void set_binary_in_array(const char * name, std::size_t index,
            const void * value, std::size_t value_length);

    std::size_t get_binary_array_length(const std::string & name) const;
    std::size_t get_binary_array_length(const char * name) const;

    const void * get_binary_in_array(const std::string & name,
            std::size_t index, std::size_t & length) const;
    const void * get_binary_in_array(const char * name, std::size_t index,
            std::size_t & length) const;

    yami::core::parameters * create_nested_parameters(const std::string & name);

    yami::core::parameters
            * get_nested_parameters(const std::string & name) const;
    yami::core::parameters * get_nested_parameters(const char * name) const;

    void lock(const std::string & name, long long key);
    void lock(const char * name, long long key);

    void unlock(const std::string & name, long long key);
    void unlock(const char * name, long long key);

    bool is_locked(const std::string & name) const;
    bool is_locked(const char * name) const;

    std::size_t size() const;

    yami::parameters* get_impl();

protected:
    yami::parameters* m_impl;
};

} // idlyami

#endif // IDLYAMI_PARAMETERS_HPP
