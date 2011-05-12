// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * client.cpp
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
#include <iostream>

int main(int argc, char* argv[])
{
    idlyami::ORB orb;

    MyModule::MyInterface_c cl(&orb, "tcp://localhost:5678", "my_poa_id", "my_object_id");

    std::cout << cl.get_endpoint() << std::endl;
    std::cout << cl.get_poa_id() << std::endl;
    std::cout << cl.get_servant_id() << std::endl;

    int a = 10, b = 20, c = 0;

    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;

    for (int i = 0; i < 100; i++)
    {
        cl.my_operation(a, b, c);
        std::cout << a << std::endl;
        std::cout << b << std::endl;
        std::cout << c << std::endl;
    }
}
