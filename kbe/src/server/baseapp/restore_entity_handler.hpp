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

#ifndef __RESTORE_ENTITY_HANDLER__
#define __RESTORE_ENTITY_HANDLER__

#include "helper/debug_helper.hpp"
#include "cstdkbe/cstdkbe.hpp"

namespace KBEngine{

class Base;
class EntityMailbox;

class RestoreEntityHandler : public Task
{
	struct RestoreData
	{
		ENTITY_ID id;
		bool creatingCell;
		bool processed;
		SPACE_ID spaceID;
		EntityMailbox* cell;
	};

public:
	RestoreEntityHandler(Mercury::NetworkInterface & networkInterface);
	~RestoreEntityHandler();
	
	bool process();
	
	void pushEntity(ENTITY_ID id);

	/** 
		某个baseapp上的space恢复了cell， 判断当前baseapp是否有相关entity需要恢复cell
	*/
	void onRestoreSpaceCellFromOtherBaseapp(COMPONENT_ID baseappID, COMPONENT_ID cellappID, 
		SPACE_ID spaceID, ENTITY_ID spaceEntityID, ENTITY_SCRIPT_UID utype, bool destroyed);
private:
	Mercury::NetworkInterface & networkInterface_;
	std::vector<RestoreData> entities_;
	bool inProcess_;

	std::vector<RestoreData> restoreSpaces_;
	std::vector<RestoreData> ohterRestoredSpaces_;

	// space创建好cell后广播给其他baseapp
	bool broadcastOtherBaseapps_;

	uint64 tickReport_;

	std::vector<SPACE_ID> spaceIDs_;
};


}
#endif
