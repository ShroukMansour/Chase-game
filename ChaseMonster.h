#include "Monster.h"
#include "Room.h"

class ChaseMonster: public Monster {
public:
	ChaseMonster(string n, string d, Room * startingRoom);
	int bfs();
	bool act();
};

