// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * Request.hpp
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

#ifndef IDLYAMI_REQUEST_HPP
#define IDLYAMI_REQUEST_HPP

#include <idlyami/yami_forward.hpp>

namespace idlyami
{

class Object;
class Parameters;

class Request
{
public:
	Request(const char * name, Object * stub);
	virtual ~Request();

	void send();
	void send_oneway();

	Parameters * get_parameters();
	Parameters * get_reply();

protected:
	Object * m_stub;
	yami::parameters * m_request;
	Parameters * m_parameters;
	Parameters * m_reply;
};

} // idlyami

#endif // IDLYAMI_REQUEST_HPP

