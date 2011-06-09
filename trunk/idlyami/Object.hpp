// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * Object.hpp
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

#ifndef IDLYAMI_OBJECT_HPP
#define IDLYAMI_OBJECT_HPP

#include <string>

namespace idlyami
{
class ORB;

class Object
{
public:
    Object(ORB* orb, const std::string& target_endpoint,
            const std::string& poa_id,
            const std::string& servant_id);
    virtual ~Object();

    ORB* get_orb();
    const std::string& get_endpoint();
    const std::string& get_poa_id();
    const std::string& get_servant_id();

protected:

    ORB* m_orb;
    std::string m_target_endpoint;
    std::string m_poa_id;
    std::string m_servant_id;
};
} // idlyami

#endif // IDLYAMI_OBJECT_HPP

