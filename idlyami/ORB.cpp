// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * ORB.cpp
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

#include "ORB.hpp"
#include <yami4-cpp/agent.h>

using namespace idlyami;

ORB::ORB() : m_agent(new yami::agent())
{
}

ORB::~ORB()
{
    delete m_agent;
}

yami::agent * ORB::get_agent()
{
	return m_agent;
}

std::string ORB::add_listener(const std::string & listener)
{
    return m_agent->add_listener(listener);
}
