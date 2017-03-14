#include "RandomMonster.h"

RandomMonster::RandomMonster(string n, string d, Room* startingRoom) {
	name = n;
	description = d;
	curRoom = startingRoom;
	curRoom->enter(this);
	curRoom->enterMonster(this);
}

bool RandomMonster::act() {
	int n = rand() % 4;
	string direction;
	switch (n) {
	case 0:
		direction = "north";
		break;
	case 1:
		direction = "south";
		break;
	case 2:
		direction = "west";
		break;
	case 3:
		direction = "east";
		break;
	}
	if (curRoom->getLinked(direction) != NULL) {
		curRoom->leave(this);
		curRoom->leaveMonster(this);
		curRoom = curRoom->getLinked(direction);
		curRoom->enter(this);
		curRoom->enterMonster(this);
	}

	return true;
}
