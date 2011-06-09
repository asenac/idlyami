// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * Request.cpp
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

#include "Request.hpp"
#include "Object.hpp"
#include "ORB.hpp"
#include "Parameters.hpp"
#include <yami4-cpp/parameters.h>
#include <yami4-cpp/agent.h>

#include "debug.hpp"

using namespace idlyami;

Request::Request(const char * name, Object * stub) : m_stub(stub),
    m_request(new yami::parameters()), m_parameters(0), m_reply(0)
{
    m_request->set_string("operation", name);
    m_parameters = new Parameters(
            m_request->create_nested_parameters("parameters"));
}

Request::~Request()
{
    delete m_request;
    delete m_parameters;
    delete m_reply;
}

void Request::send()
{
    m_request->set_boolean("isoneway", false);

    yami::agent * agent = m_stub->get_orb()->get_agent();

    std::auto_ptr<yami::outgoing_message> om(
            agent->send(m_stub->get_endpoint(), m_stub->get_poa_id(),
                    m_stub->get_servant_id(), *m_request));

    om->wait_for_completion();

    m_reply = new Parameters(om->extract_reply());
}

void Request::send_oneway()
{
    m_request->set_boolean("isoneway", true);

    yami::agent * agent = m_stub->get_orb()->get_agent();

    agent->send_one_way(m_stub->get_endpoint(), m_stub->get_poa_id(),
            m_stub->get_servant_id(), *m_request);
}

Parameters * Request::get_parameters()
{
    return m_parameters;
}

Parameters * Request::get_reply()
{
    return m_reply;
}
