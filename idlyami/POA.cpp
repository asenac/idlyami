// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * POA.cpp
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

#include "POA.hpp"
#include "ORB.hpp"
#include "Servant.hpp"
#include "ServerRequest.hpp"
#include <yami4-cpp/incoming_message.h>
#include <yami4-cpp/agent.h>

#include "debug.hpp"

using namespace idlyami;

namespace idlyami
{
class POAFunctor
{
public:
    POAFunctor(POA* poa) : m_poa(poa) {}

    void operator()(yami::incoming_message& msg)
    {
        DEBUG_VERB(0, "new incoming message");
        DEBUG_VERB(0, "poa_id: " << msg.get_object_name());
        DEBUG_VERB(0, "servant_id: " << msg.get_message_name());

        ServerRequest * request = 0;
        try {
            request = new ServerRequest(msg);
            m_poa->enqueue_request(request);
        } catch (const std::exception& e)
        {
            // Malformed message
            DEBUG_ERROR(e.what());

            delete request;
        }

        // msg is no longer available
    }

protected:
    POA* m_poa;
};
} // idlyami

POA::POA(ORB* orb, const std::string& poa_id) :
    m_orb(orb), m_id(poa_id), m_functor(new POAFunctor(this))
{
    m_orb->get_agent()->register_object(poa_id, *m_functor);
}

POA::~POA()
{
    m_orb->get_agent()->unregister_object(m_id);

    delete m_functor;
}

void POA::register_servant(const std::string& servant_id, Servant* servant)
{
    m_active_object_map.insert(std::make_pair(servant_id, servant));
}

void POA::enqueue_request(ServerRequest* request)
{
    // TODO implement some thread policies

    DEBUG_VERB(0, "processing request!");

    active_object_map_t::iterator it = m_active_object_map.find(request->get_servant_id());

    if(it != m_active_object_map.end())
    {
        try {
            DEBUG_VERB(0, "servant found!");

            it->second->invoke(request);
        } catch(...)
        {
            // TODO set exception into the reply
            DEBUG_ERROR("exception catched!");
        }

        if(!request->is_oneway())
        {
            DEBUG_VERB(0, "sending reply!");
            request->send_reply();
        }
    }

    delete request;

    DEBUG_VERB(0, "request processed!");
}
