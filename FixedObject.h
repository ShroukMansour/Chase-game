#ifndef FixedObject_H
#define FixedObject_H
#include "Game.h"
#include "Player.h"
#include "Object.h"

class Room;
class FixedObject: public Object {
private:
	Room *curRoom;
	Room *newRoom;
public:
	bool act();
	FixedObject(string n, string d, Room *curRoo, Room* newRoo);
	string getName();
	string getdescription();
};

#endif // FixedObject_H
