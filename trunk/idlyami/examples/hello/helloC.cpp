// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * helloC.cpp
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

#include "helloC.hpp"

MyModule::MyInterface::MyInterface()
{
}

MyModule::MyInterface::~MyInterface()
{
}

MyModule::MyInterface_c::MyInterface_c(idlyami::ORB* orb,
        const std::string& target_endpoint, const std::string& poa_id,
        const std::string& servant_id) :
    idlyami::Object(orb, target_endpoint, poa_id, servant_id)
{
}

MyModule::MyInterface_c::~MyInterface_c()
{
}

void MyModule::MyInterface_c::my_operation(int a, int& b, int& c)
{
    idlyami::Request __request("my_operation", this);
    idlyami::stub::Arg_IN<int> _a(__request, "a", a);
    idlyami::stub::Arg_INOUT<int> _b(__request, "b", b);
    idlyami::stub::Arg_OUT<int> _c(__request, "c", c);

    __request.send();
}

void MyModule::MyInterface_c::my_second_operation(float a, float& b, float& c)
{
    idlyami::Request __request("my_second_operation", this);
    idlyami::stub::Arg_IN<float> _a(__request, "a", a);
    idlyami::stub::Arg_INOUT<float> _b(__request, "b", b);
    idlyami::stub::Arg_OUT<float> _c(__request, "c", c);

    __request.send();
}
void MyModule::MyInterface_c::my_third_operation(const std::string& a,
        std::string& b, std::string& c)
{
    idlyami::Request __request("my_third_operation", this);
    idlyami::stub::Arg_IN<std::string> _a(__request, "a", a);
    idlyami::stub::Arg_INOUT<std::string> _b(__request, "b", b);
    idlyami::stub::Arg_OUT<std::string> _c(__request, "c", c);

    __request.send();
}
void MyModule::MyInterface_c::my_oneway_operation(const std::string& a, int b,
        float c)
{
    idlyami::Request __request("my_oneway_operation", this);
    idlyami::stub::Arg_IN<std::string> _a(__request, "a", a);
    idlyami::stub::Arg_IN<int> _b(__request, "b", b);
    idlyami::stub::Arg_IN<float> _c(__request, "c", c);

    __request.send_oneway();
}

static MyModule::MyInterface::_my_operation_t::handler_t
        ___MyModule__MyInterface__my_operation(
                &MyModule::MyInterface::my_operation);
static const char *__MyModule__MyInterface_my_operation_name[] =
{ "a", "b", "c" };

static MyModule::MyInterface::_my_second_operation_t::handler_t
        ___MyModule__MyInterface__my_second_operation(
                &MyModule::MyInterface::my_second_operation);
static const char *__MyModule__MyInterface_my_second_operation_name[] =
{ "a", "b", "c" };

static MyModule::MyInterface::_my_third_operation_t::handler_t
        ___MyModule__MyInterface__my_third_operation(
                &MyModule::MyInterface::my_third_operation);
static const char *__MyModule__MyInterface_my_third_operation_name[] =
{ "a", "b", "c" };

static MyModule::MyInterface::_my_oneway_operation_t::handler_t
        ___MyModule__MyInterface__my_oneway_operation(
                &MyModule::MyInterface::my_oneway_operation);
static const char *__MyModule__MyInterface_my_oneway_operation_name[] =
{ "a", "b", "c" };

static idlyami::OperationEntry __MyModule__MyInterface[] =
{
{ "my_operation", &___MyModule__MyInterface__my_operation,
        __MyModule__MyInterface_my_operation_name },
{ "m_second_operation", &___MyModule__MyInterface__my_second_operation,
        __MyModule__MyInterface_my_second_operation_name },
{ "m_third_operation", &___MyModule__MyInterface__my_third_operation,
        __MyModule__MyInterface_my_third_operation_name },
{ "m_oneway_operation", &___MyModule__MyInterface__my_oneway_operation,
        __MyModule__MyInterface_my_oneway_operation_name },
{ NULL, NULL, NULL } };

MyModule::MyInterface_s::MyInterface_s() :
    idlyami::Servant(__MyModule__MyInterface)
{
}

MyModule::MyInterface_s::~MyInterface_s()
{
}

#include <iostream>

void MyModule_MyInterface_i::my_operation(int a, int& b, int& c)
{
    // TODO add your code here
    std::cout << "my_operation" << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;

    b = 15;
    c = 100;
}

void MyModule_MyInterface_i::my_second_operation(float a, float& b, float& c)
{
}
void MyModule_MyInterface_i::my_third_operation(const std::string& a,
        std::string& b, std::string& c)
{
}
void MyModule_MyInterface_i::my_oneway_operation(const std::string& a, int b,
        float c)
{
}
