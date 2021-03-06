/*
This source file is part of KBEngine
For the latest info, see http://www.kbengine.org/

Copyright (c) 2008-2012 KBEngine.

KBEngine is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

KBEngine is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.
 
You should have received a copy of the GNU Lesser General Public License
along with KBEngine.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef KBE_BASE_REMOTE_METHOD_HPP
#define KBE_BASE_REMOTE_METHOD_HPP


#include "helper/debug_helper.hpp"
#include "cstdkbe/cstdkbe.hpp"	
#include "entitydef/remote_entity_method.hpp"

namespace KBEngine{

class BaseRemoteMethod : public RemoteEntityMethod
{
	/** 子类化 将一些py操作填充进派生类 */
	INSTANCE_SCRIPT_HREADER(BaseRemoteMethod, RemoteEntityMethod)	
public:
	BaseRemoteMethod(MethodDescription* methodDescription, 
						EntityMailboxAbstract* mailbox);

	~BaseRemoteMethod();

	static PyObject* tp_call(PyObject* self, 
			PyObject* args, PyObject* kwds);
private:

};

}
#endif
