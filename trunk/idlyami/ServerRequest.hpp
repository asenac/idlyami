// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * ServerRequest.hpp
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

#ifndef IDLYAMI_SERVERREQUEST_HPP
#define IDLYAMI_SERVERREQUEST_HPP

#include <string>
#include <idlyami/yami_forward.hpp>

namespace idlyami
{
class Parameters;

class ServerRequest
{
public:
    ServerRequest(yami::incoming_message& msg);
    virtual ~ServerRequest();

    const std::string& get_poa_id() const;
    const std::string& get_servant_id() const;
    const std::string& get_operation() const;

    Parameters* get_parameters();
    Parameters* get_reply();

    bool is_oneway() const;

    void send_reply();

protected:
    yami::incoming_message* m_msg;
    std::string m_operation;
    bool m_isoneway;

    Parameters* m_parameters;
    Parameters* m_reply;
};

} // idlyami

#endif // IDLYAMI_SERVERREQUEST_HPP

