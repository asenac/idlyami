// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * ServerRequest.cpp
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

#include "ServerRequest.hpp"
#include "Parameters.hpp"
#include <yami4-cpp/incoming_message.h>

using namespace idlyami;

ServerRequest::ServerRequest(yami::incoming_message& msg)
: m_msg(new yami::incoming_message(msg)), m_parameters(0), m_reply(0)
{
    const yami::parameters& parameters = m_msg->get_parameters();

    m_operation = parameters.get_string("operation");
    m_isoneway = parameters.get_boolean("isoneway");

    m_parameters = new Parameters(parameters.get_nested_parameters("parameters"));
    m_reply = new Parameters(new yami::core::parameters());
}

ServerRequest::~ServerRequest()
{
    delete m_parameters;
    delete m_reply;
}

const std::string& ServerRequest::get_poa_id() const
{
    return m_msg->get_object_name();
}

const std::string& ServerRequest::get_servant_id() const
{
    return m_msg->get_message_name();
}

const std::string& ServerRequest::get_operation() const
{
    return m_operation;
}

Parameters* ServerRequest::get_parameters()
{
    return m_parameters;
}

Parameters* ServerRequest::get_reply()
{
    return m_reply;
}

bool ServerRequest::is_oneway() const
{
    return m_isoneway;
}

void ServerRequest::send_reply()
{
    m_msg->reply(*m_reply->get_impl());
}
