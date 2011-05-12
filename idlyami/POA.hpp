// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * POA.hpp
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

#ifndef IDLYAMI_POA_HPP
#define IDLYAMI_POA_HPP

#include <string>
#include <map>

namespace idlyami
{
class ORB;
class ServerRequest;
class POAFunctor;
class Servant;

class POA
{
public:
    POA(ORB* orb, const std::string& poa_id);
    virtual ~POA();

    void register_servant(const std::string& servant_id, Servant* servant);

protected:
    ORB* m_orb;
    std::string m_id;
    POAFunctor* m_functor;

    typedef std::map< std::string, Servant* > active_object_map_t;
    active_object_map_t m_active_object_map;

    friend class POAFunctor;

    void enqueue_request(ServerRequest* request);
};

} // idlyami

#endif // IDLYAMI_POA_HPP

