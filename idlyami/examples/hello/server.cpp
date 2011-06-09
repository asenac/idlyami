// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * server.cpp
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

#include "helloC.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
    idlyami::ORB orb;
    orb.add_listener("tcp://localhost:5678");

    idlyami::POA poa(&orb, "my_poa_id");

    MyModule_MyInterface_i impl;

    poa.register_servant("my_object_id", &impl);

    char c;
    std::cin >> c;

}
