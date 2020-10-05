#pragma once
#include "Room.h"
#include "ObjManager.h"

class RoomManager : public SingleTone<RoomManager>
{
public:
	std::vector<Room*> room;

	ObjManager* objectManager = OBJMANAGER->GetObjectManager();
	int RNumber = 0;
public:
	RoomManager();
	~RoomManager();

	void SoloRoomMatch(int id);
private:

};

