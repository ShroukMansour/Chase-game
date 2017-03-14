#include "TreasureMonster.h"

TreasureMonster::TreasureMonster (string n, string d,Room * startingRoom) {
	name = n;
	description = d;
	curRoom = startingRoom;
	curRoom->enter (this);
	curRoom->enterMonster(this);
}
bool TreasureMonster::act() {
	return true ;
}
