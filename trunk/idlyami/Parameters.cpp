// -*- mode: c++{} c-basic-style: "bsd"{} c-basic-offset: 4{} -*-
/*
 * Parameters.cpp
 * Andrés Senac 2011 <andres@senac.es>
 *
 * idlyami is free software: you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * idlyami is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY{} without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "Parameters.hpp"
#include <yami4-cpp/parameters.h>

using namespace idlyami;

Parameters::Parameters(yami::core::parameters* core)
: m_impl(new yami::parameters(core))
{
}

Parameters::Parameters(yami::parameters* impl)
: m_impl(impl)
{
}

Parameters::~Parameters()
{
    delete m_impl;
}
yami::parameters* Parameters::get_impl() { return m_impl; }

void Parameters::set_boolean(const std::string & name, bool value)
{
    m_impl->set_boolean(name, value);
}
void Parameters::set_boolean(const char * name, bool value)
{
    m_impl->set_boolean(name, value);
}

bool Parameters::get_boolean(const std::string & name) const
{
    return m_impl->get_boolean(name);
}
bool Parameters::get_boolean(const char * name) const
{
    return m_impl->get_boolean(name);
}

void Parameters::set_integer(const std::string & name, int value)
{
    m_impl->set_integer(name, value);
}
void Parameters::set_integer(const char * name, int value)
{
    m_impl->set_integer(name, value);
}

int Parameters::get_integer(const std::string & name) const
{
    return m_impl->get_integer(name);
}
int Parameters::get_integer(const char * name) const
{
    return m_impl->get_integer(name);
}

void Parameters::set_long_long(const std::string & name, long long value)
{
    m_impl->set_long_long(name, value);
}
void Parameters::set_long_long(const char * name, long long value)
{
    m_impl->set_long_long(name, value);
}

long long Parameters::get_long_long(const std::string & name) const
{
    return m_impl->get_long_long(name);
}
long long Parameters::get_long_long(const char * name) const
{
    return m_impl->get_long_long(name);
}

void Parameters::set_double_float(const std::string & name, double value)
{
    m_impl->set_double_float(name, value);
}
void Parameters::set_double_float(const char * name, double value)
{
    m_impl->set_double_float(name, value);
}

double Parameters::get_double_float(const std::string & name) const
{
    return m_impl->get_double_float(name);
}
double Parameters::get_double_float(const char * name) const
{
    return m_impl->get_double_float(name);
}

void Parameters::set_string(const std::string & name, const std::string & value)
{
    m_impl->set_string(name, value);
}
void Parameters::set_string(const char * name, const char * value)
{
    m_impl->set_string(name, value);
}

void Parameters::set_string_shallow(const std::string & name, const char * value,
        std::size_t value_length)
{
    m_impl->set_string_shallow(name, value, value_length);
}
void Parameters::set_string_shallow(const char * name, std::size_t name_length,
        const char * value, std::size_t value_length)
{
    m_impl->set_string_shallow(name, value, value_length);
}

std::string Parameters::get_string(const std::string & name) const
{
    return m_impl->get_string(name);
}
std::string Parameters::get_string(const char * name) const
{
    return m_impl->get_string(name);
}

const char * Parameters::get_string(const std::string & name, std::size_t & length) const
{
    return m_impl->get_string(name, length);
}
const char * Parameters::get_string(const char * name, std::size_t & length) const
{
    return m_impl->get_string(name, length);
}

void Parameters::set_binary(const std::string & name, const void * value,
        std::size_t value_length)
{
    m_impl->set_binary(name, value, value_length);
}
void Parameters::set_binary(const char * name, const void * value, std::size_t value_length)
{
    m_impl->set_binary(name, value, value_length);
}

void Parameters::set_binary_shallow(const std::string & name, const void * value,
        std::size_t value_length)
{
    m_impl->set_binary_shallow(name, value, value_length);
}
void Parameters::set_binary_shallow(const char * name, std::size_t name_length,
        const void * value, std::size_t value_length)
{
    m_impl->set_binary_shallow(name, value, value_length);
}

const void * Parameters::get_binary(const std::string & name, std::size_t & length) const
{
    return m_impl->get_binary(name, length);
}
const void * Parameters::get_binary(const char * name, std::size_t & length) const
{
    return m_impl->get_binary(name, length);
}

void Parameters::set_boolean_array(const std::string & name, const bool * values,
        std::size_t array_length)
{
    m_impl->set_boolean_array(name, values, array_length);
}
void Parameters::set_boolean_array(const char * name, const bool * values,
        std::size_t array_length)
{
    m_impl->set_boolean_array(name, values, array_length);
}

void Parameters::set_boolean_array_shallow(const std::string & name, const bool * values,
        std::size_t array_length)
{
    m_impl->set_boolean_array_shallow(name, values, array_length);
}
void Parameters::set_boolean_array_shallow(const char * name, const bool * values,
        std::size_t array_length)
{
    m_impl->set_boolean_array_shallow(name, values, array_length);
}

bool * Parameters::get_boolean_array(const std::string & name, std::size_t & length) const
{
    return m_impl->get_boolean_array(name, length);
}
bool * Parameters::get_boolean_array(const char * name, std::size_t & array_length) const
{
    return m_impl->get_boolean_array(name, array_length);
}

void Parameters::set_integer_array(const std::string & name, const int * values,
        std::size_t array_length)
{
    m_impl->set_integer_array(name, values, array_length);
}
void Parameters::set_integer_array(const char * name, const int * values,
        std::size_t array_length)
{
    m_impl->set_integer_array(name, values, array_length);
}

void Parameters::set_integer_array_shallow(const std::string & name, const int * values,
        std::size_t array_length)
{
    m_impl->set_integer_array(name, values, array_length);
}
void Parameters::set_integer_array_shallow(const char * name, const int * values,
        std::size_t array_length)
{
    m_impl->set_integer_array_shallow(name, values, array_length);
}

int * Parameters::get_integer_array(const std::string & name, std::size_t & array_length) const
{
    return m_impl->get_integer_array(name, array_length);
}
int * Parameters::get_integer_array(const char * name, std::size_t & array_length) const
{
    return m_impl->get_integer_array(name, array_length);
}

void Parameters::set_long_long_array(const std::string & name, const long long * values,
        std::size_t array_length)
{
    m_impl->set_long_long_array(name, values, array_length);
}
void Parameters::set_long_long_array(const char * name, const long long * values,
        std::size_t array_length)
{
    m_impl->set_long_long_array(name, values, array_length);
}

void Parameters::set_long_long_array_shallow(const std::string & name,
        const long long * values, std::size_t array_length)
{
    m_impl->set_long_long_array_shallow(name, values, array_length);
}
void Parameters::set_long_long_array_shallow(const char * name, const long long * values,
        std::size_t array_length)
{
    m_impl->set_long_long_array_shallow(name, values, array_length);
}

long long * Parameters::get_long_long_array(const std::string & name,
        std::size_t & array_length) const
{
    return m_impl->get_long_long_array(name, array_length);
}
long long * Parameters::get_long_long_array(const char * name, std::size_t & array_length) const
{
    return m_impl->get_long_long_array(name, array_length);
}

void Parameters::set_double_float_array(const std::string & name, const double * values,
        std::size_t array_length)
{
    m_impl->set_double_float_array(name, values, array_length);
}
void Parameters::set_double_float_array(const char * name, const double * values,
        std::size_t array_length)
{
    m_impl->set_double_float_array(name, values, array_length);
}

void Parameters::set_double_float_array_shallow(const std::string & name,
        const double * values, std::size_t array_length)
{
    m_impl->set_double_float_array_shallow(name, values, array_length);
}
void Parameters::set_double_float_array_shallow(const char * name, const double * values,
        std::size_t array_length)
{
    m_impl->set_double_float_array_shallow(name, values, array_length);
}

double * Parameters::get_double_float_array(const std::string & name,
        std::size_t & array_length) const
{
    return m_impl->get_double_float_array(name, array_length);
}
double * Parameters::get_double_float_array(const char * name, std::size_t & array_length) const
{
    return m_impl->get_double_float_array(name, array_length);
}

void Parameters::create_string_array(const std::string & name, std::size_t array_length)
{
    m_impl->create_string_array(name, array_length);
}
void Parameters::create_string_array(const char * name, std::size_t array_length)
{
    m_impl->create_string_array(name, array_length);
}

void Parameters::set_string_in_array(const std::string & name, std::size_t index,
        const std::string & value)
{
    m_impl->set_string_in_array(name, index, value);
}
void Parameters::set_string_in_array(const char * name, std::size_t index,
        const char * value)
{
    m_impl->set_string_in_array(name, index, value);
}

std::size_t Parameters::get_string_array_length(const std::string & name) const
{
    return m_impl->get_string_array_length(name);
}
std::size_t Parameters::get_string_array_length(const char * name) const
{
    return m_impl->get_string_array_length(name);
}

std::string Parameters::get_string_in_array(const std::string & name, std::size_t index) const
{
    return m_impl->get_string_in_array(name, index);
}
std::string Parameters::get_string_in_array(const char * name, std::size_t index) const
{
    return m_impl->get_string_in_array(name, index);
}

const char * Parameters::get_string_in_array(const std::string & name, std::size_t index,
        std::size_t & length) const
{
    return m_impl->get_string_in_array(name, index, length);
}
const char * Parameters::get_string_in_array(const char * name, std::size_t index,
        std::size_t & length) const
{
    return m_impl->get_string_in_array(name, index, length);
}

void Parameters::create_binary_array(const std::string & name, std::size_t array_length)
{
    m_impl->create_binary_array(name, array_length);
}
void Parameters::create_binary_array(const char * name, std::size_t array_length)
{
    m_impl->create_binary_array(name, array_length);
}

void Parameters::set_binary_in_array(const std::string & name, std::size_t index,
        const void * value, std::size_t value_length)
{
    m_impl->set_binary_in_array(name, index, value, value_length);
}
void Parameters::set_binary_in_array(const char * name, std::size_t index,
        const void * value, std::size_t value_length)
{
    m_impl->set_binary_in_array(name, index, value, value_length);
}

std::size_t Parameters::get_binary_array_length(const std::string & name) const
{
    return m_impl->get_binary_array_length(name);
}
std::size_t Parameters::get_binary_array_length(const char * name) const
{
    return m_impl->get_binary_array_length(name);
}

const void * Parameters::get_binary_in_array(const std::string & name, std::size_t index,
        std::size_t & length) const
{
    return m_impl->get_binary_in_array(name, index, length);
}
const void * Parameters::get_binary_in_array(const char * name, std::size_t index,
        std::size_t & length) const
{
    return m_impl->get_binary_in_array(name, index, length);
}

yami::core::parameters * Parameters::create_nested_parameters(const std::string & name)
{
    return m_impl->create_nested_parameters(name);
}

yami::core::parameters * Parameters::get_nested_parameters(const std::string & name) const
{
    return m_impl->get_nested_parameters(name);
}
yami::core::parameters * Parameters::get_nested_parameters(const char * name) const
{
    return m_impl->get_nested_parameters(name);
}

void Parameters::lock(const std::string & name, long long key)
{
    m_impl->lock(name, key);
}
void Parameters::lock(const char * name, long long key)
{
    m_impl->lock(name, key);
}

void Parameters::unlock(const std::string & name, long long key)
{
    m_impl->unlock(name, key);
}
void Parameters::unlock(const char * name, long long key)
{
    m_impl->unlock(name, key);
}

bool Parameters::is_locked(const std::string & name) const
{
    return m_impl->is_locked(name);
}
bool Parameters::is_locked(const char * name) const
{
    return m_impl->is_locked(name);
}

std::size_t Parameters::size() const
{
    return m_impl->size();
}
