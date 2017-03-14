#ifndef RANDOM_MONSTER
#define RANDOM_MONSTER

#include "Monster.h"

class RandomMonster: public Monster {
public:
	RandomMonster(string n, string d, Room* startingRoom);
	bool act();
};

#endif
