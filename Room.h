#ifndef ROOM_H
#define ROOM_H
#include <bits/stdc++.h>
#include "Treasure.h"

class Agent;
class Monster;
class FixedObject;
class Treasure;
class Props;
class Player;
class FixedObject;

using namespace std;

class Room {
private:
	string name;
	string description;
	Room* dir[5];
	FixedObject * fixedObj;
	Treasure *treasureOfRoom;
	vector<Agent*> occupants;
	vector<Monster *> arrOfMonsters;
	vector<Player*> arrOfPlayers;
	vector<Props*> arrOfProps;
public:
	Room(string n, string d);
	string getName();
	string getDescription();
	Room();
	FixedObject* getFixedObj();
	void link(Room *r, string direction);
	Room *getLinked(string direction);
	void printLinked();
	void enter(Agent *a);
	void setFixedobj(FixedObject * f);
	void enterPlayer(Player * p);
	void leavePlayer(Player *a);
	void enterMonster(Monster * p);
	void leaveMonster(Monster *a);
	void leave(Agent *a);
	void printOccupants();
	bool printProps();
	Props *getProp(string p);
	bool checkForPlayers();
	vector<Monster *> getArrOfMonsters();
	void setTreasure(Treasure *t);
	void setProps(Props * p);
	Treasure* getTreasure();
	void printerNonKilledMonsters();

};

#endif // ROOM_H