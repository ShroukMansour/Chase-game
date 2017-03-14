#ifndef PLAYER_H
#define PLAYER_H
#include "Agent.h"
#include "Props.h"

class Game;

class Player: public Agent {
private:
	vector<Props*> propsOfPlayer;

public:
	Player(string n, Room *startingRoom);
	bool act();
	bool actByProps();
	void takeProp(string p);
	void leaveProp(string p);
	bool printPropsPlayer();
};

#endif // PLAYER_H
