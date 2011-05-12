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
    idlyami::stub::Arg_IN< int > _a(__request, "a", a);
    idlyami::stub::Arg_INOUT< int > _b(__request, "b", b);
    idlyami::stub::Arg_OUT< int > _c(__request, "c", c);
    // idlyami::stub::Return< int > __result;

    __request.send();

    // return __result.value();
}

static MyModule::MyInterface::_my_operation_t::handler_t ___MyModule__MyInterface__my_operation(&MyModule::MyInterface::my_operation);
static const char *__MyModule__MyInterface__name[] = {"a", "b", "c"};
static idlyami::OperationEntry __MyModule__MyInterface[] = {{"my_operation", &___MyModule__MyInterface__my_operation, __MyModule__MyInterface__name},{NULL, NULL, NULL}};

MyModule::MyInterface_s::MyInterface_s() : idlyami::Servant(__MyModule__MyInterface)
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
