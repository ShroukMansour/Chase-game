#ifndef AGENT_H
#define AGENT_H
#include "Room.h"

class Props;
class Game;
class Agent {
protected:
	Room *curRoom;
	string name;
	string description;

public:
	virtual bool act() = 0;
	Agent(string n, string d, Room * startingRoom);
	virtual ~Agent();
	Agent();
	string getName();
	string getDescription ();
	void setCurRoom (Room* r);
	Room* getCurRoom ();

};

#endif // AGENT_H
