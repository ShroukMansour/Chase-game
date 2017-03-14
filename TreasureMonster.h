#ifndef TREASURE_MONSTER
#define TREASURE_MONSTER

#include "Monster.h"

class TreasureMonster: public Monster {
public:
	TreasureMonster(string n, string d, Room * startingRoom);
	bool act();
};

#endif
