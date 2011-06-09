// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * Servant.cpp
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

#include "Servant.hpp"
#include "Operation.hpp"
#include "ServerRequest.hpp"

using namespace idlyami;

Servant::Servant(OperationEntry* entries)
{
    OperationEntry* current = entries;

    while(current && current->name)
    {
        m_operations_map.insert(std::make_pair(current->name,
                current->handler));

        m_parameters_map.insert(std::make_pair(current->name,
                current->parameters));
        current++;
    }
}

Servant::~Servant()
{
}

void Servant::invoke(ServerRequest * request)
{
    operations_map_t::iterator it = m_operations_map.find(request->get_operation());

    if(it != m_operations_map.end())
    {
        it->second->do_call(this, request, m_parameters_map[request->get_operation()]);
    }
}
