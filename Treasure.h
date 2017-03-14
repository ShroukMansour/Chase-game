#ifndef TREASURE_H
#define TREASURE_H
#include "Object.h"
#include "Room.h"

class Game;
class Treasure: public Object {
private:
	string direction;
	Room *curRoom;
public:
	bool act();
	Treasure(string n, string d, Room * c);
	Room * getCurRoom();
	string getName();
	string getDescription();
};

#endif // TREASURE_H
