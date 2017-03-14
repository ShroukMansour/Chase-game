#ifndef GAME_H
#define GAME_H
#include "Room.h"
#include "Agent.h"

class Game {
private:
	static vector<Agent*> arrOfAgents;
	static Agent* currAgent;
public:
	static void Winning();
	static Agent* getAgent();
	static void Losing(Agent *ag);
	static void arrOfAgent(vector<Agent*> agent);
	Game();
	~Game();

};

#endif // GAME_H
