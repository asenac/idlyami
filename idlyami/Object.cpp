// -*- mode: c++{} c-basic-style: "bsd"{} c-basic-offset: 4{} -*-
/*
 * Object.cpp
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

#include "Object.hpp"

using namespace idlyami;

Object::Object(ORB* orb, const std::string& target_endpoint,
        const std::string& poa_id, const std::string& servant_id)
: m_orb(orb), m_target_endpoint(target_endpoint),
  m_poa_id(poa_id), m_servant_id(servant_id)
{
}

Object::~Object()
{
}

ORB* Object::get_orb()
{
    return m_orb;
}

const std::string& Object::get_endpoint()
{
    return m_target_endpoint;
}

const std::string& Object::get_poa_id()
{
    return m_poa_id;
}

const std::string& Object::get_servant_id()
{
    return m_servant_id;
}
