// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * Servant.hpp
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

#ifndef IDLYAMI_SERVANT_HPP
#define IDLYAMI_SERVANT_HPP

#include <string>
#include <map>

namespace idlyami
{
class OperationHandler;
class ServerRequest;

struct OperationEntry
{
    const char * name;
    OperationHandler * handler;
    const char ** parameters;
};

class Servant
{
protected:
    Servant(OperationEntry* entries);

public:
    virtual ~Servant();

    void invoke(ServerRequest * request);

protected:

    typedef std::map< std::string, OperationHandler* > operations_map_t;
    operations_map_t m_operations_map;

    typedef std::map< std::string, const char** > parameters_map_t;
    parameters_map_t m_parameters_map;
};

} // idlyami

#endif // IDLYAMI_SERVANT_HPP

