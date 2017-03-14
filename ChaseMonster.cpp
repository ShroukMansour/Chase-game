#include "ChaseMonster.h"

ChaseMonster::ChaseMonster(string n, string d, Room * startingRoom) {
	name = n;
	description = d;
	curRoom = startingRoom;
	curRoom->enter(this);
	curRoom->enterMonster(this);
}
int ChaseMonster::bfs() {
	string dx[] = { "east", "north", "south", "west" };
	int level = 0;
	map<Room *, int> visit;
	queue<Room*> q;
	q.push(curRoom);
	while (!q.empty()) {
		int sz = q.size();
		while (sz--) {
			Room* currentRoom = q.front();
			visit[currentRoom] = 1;
			q.pop();
			if (currentRoom->checkForPlayers())
				return level;
			for (int i = 0; i < 4; i++) {
				if (currentRoom->getLinked(dx[i])
						&& !visit[currentRoom->getLinked(dx[i])])
					q.push(currentRoom->getLinked(dx[i]));
			}
		}
		level++;
	}
	return 1000;

}
bool ChaseMonster::act() {
	string dx[] = { "east", "north", "south", "west" };
	int mx = 1001, check = -1;
	for (int i = 0; i < 4; i++) {
		if (mx > bfs() && curRoom->getLinked(dx[i]) != NULL) {
			mx = bfs();
			check = i;
		}
	}
	if (check != -1) {
		curRoom->leave(this);
		curRoom->leaveMonster(this);
		curRoom = curRoom->getLinked(dx[check]);
		curRoom->enter(this);
		curRoom->enterMonster(this);
	}
	return true;;
}
