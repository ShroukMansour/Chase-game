#ifndef PROPS
#define PROPS

#include "Object.h"
#include "Room.h"
class Player;

class Props: public Object {
private:
	string name, descripion;
	vector<Monster *> monstersOfProps;
	Room *curRoomOfProb;
public:
	Props();
	virtual ~Props();
	string getName();
	string getDescription();
	void setCurRoomOfProb(Room* r);
	Props(string n, string d, Room* r, Monster* m1, Monster* m2);
	bool act();
};

#endif
