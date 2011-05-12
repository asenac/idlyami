// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * ORB.hpp
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

#ifndef IDLYAMI_ORB_HPP
#define IDLYAMI_ORB_HPP

#include <idlyami/yami_forward.hpp>
#include <string>

namespace idlyami
{

class ORB
{
public:
    ORB();
    virtual ~ORB();

    yami::agent * get_agent();

    std::string add_listener(const std::string & listener);

protected:
    yami::agent * m_agent;
};

} // idlyami

#endif // IDLYAMI_ORB_HPP
