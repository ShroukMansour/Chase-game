#include "Room.h"
#include "Props.h"
#include "Treasure.h"
#include "Agent.h"
#include "Game.h"
#include "Player.h"
#include "Monster.h"

using namespace std;
Room::Room() {
	name = "";
	description = "";
	fixedObj = NULL;
	treasureOfRoom = NULL;
	memset(dir, 0, sizeof dir);
}
Room::Room(string n, string d) {
	name = n;
	description = d;
	fixedObj = NULL;
	treasureOfRoom = NULL;
	memset(dir, 0, sizeof dir);
}
string Room::getName() {
	return name;
}
string Room::getDescription() {
	return description;
}

void Room::link(Room *r, string d) {
	if (d == "north") {
		dir[0] = r;
		r->dir[1] = this;
	}
	if (d == "south") {
		dir[1] = r;
		r->dir[0] = this;
	}
	if (d == "east") {
		dir[2] = r;
		r->dir[3] = this;
	}
	if (d == "west") {
		dir[3] = r;
		r->dir[2] = this;
	}

}
void Room::printLinked() {
	cout << "there is an exit to:\n ";
	if (dir[0] != NULL)
		cout << "the north (" << dir[0]->getName() << ")\n";
	if (dir[1] != NULL)
		cout << "the south (" << dir[1]->getName() << ")\n";
	if (dir[2] != NULL)
		cout << "the east (" << dir[2]->getName() << ")\n";
	if (dir[3] != NULL)
		cout << "the west (" << dir[3]->getName() << ")\n";
}
Room*Room::getLinked(string d) {
	if (d == "north" && dir[0] != NULL)
		return dir[0];
	if (d == "south" && dir[1] != NULL)
		return dir[1];
	if (d == "east" && dir[2] != NULL)
		return dir[2];
	if (d == "west" && dir[3] != NULL)
		return dir[3];
	return NULL;
}

void Room::enter(Agent *a) {
	occupants.push_back(a);
	a->setCurRoom(this);
}
void Room::leave(Agent *a) {
	for (int i = 0; i < (int) occupants.size(); i++) {
		if (occupants[i] == a)
			occupants.erase(occupants.begin() + i);
	}
}
void Room::enterPlayer(Player * p) {
	arrOfPlayers.push_back(p);
}
void Room::leavePlayer(Player *a) {
	for (int i = 0; i < (int) arrOfPlayers.size(); i++) {
		if (arrOfPlayers[i] == a)
			arrOfPlayers.erase(arrOfPlayers.begin() + i);
	}
}
void Room::enterMonster(Monster * p) {
	arrOfMonsters.push_back(p);
}
void Room::leaveMonster(Monster *a) {
	for (int i = 0; i < (int) arrOfMonsters.size(); i++) {
		if (arrOfMonsters[i] == a)
			arrOfMonsters.erase(arrOfMonsters.begin() + i);
	}
}
void Room::printOccupants() {
	bool flag = 0;
	cout << "you see ";
	for (int i = 0; i < (int) occupants.size(); i++) {
		if (occupants[i] != NULL) {
			cout << occupants[i]->getName() << occupants[i]->getDescription()
					<< "..\n";
			flag = 1;
		}
	}
	if (flag == 0)
		cout << "no other creatures here\n\n";

}
bool Room::printProps() {
	if (!arrOfProps.size()) {
		cout << "sorry there isn't any props in this room to choose\n\n";
		return false;
	} else {
		if (arrOfProps.size() == 1)
			cout << "One prop exists in the room and it's : ";
		else
			cout << "The props on this room are : ";
		for (int i = 0; i < (int) arrOfProps.size(); i++) {
			cout << arrOfProps[i]->getName();
			if (i + 2 < (int) arrOfProps.size())
				cout << " , ";
			else if (i + 2 == (int) arrOfProps.size())
				cout << " and ";

		}
		cout << " .\n\n";
	}
	return true;

}
void Room::setProps(Props * p) {
	arrOfProps.push_back(p);
}
Props* Room::getProp(string p) {
	for (int i = 0; i < (int) arrOfProps.size(); i++) {
		if (arrOfProps[i]->getName() == p) {
			Props* prop = arrOfProps[i];
			arrOfProps.erase(arrOfProps.begin() + i);
			return prop;
		}
	}
	return NULL;
}
void Room::setFixedobj(FixedObject * f) {
	fixedObj = f;
}
FixedObject* Room::getFixedObj() {
	return fixedObj;
}
vector<Monster *> Room::getArrOfMonsters() {
	return arrOfMonsters;
}
void Room::setTreasure(Treasure *t) {
	treasureOfRoom = t;
}
Treasure* Room::getTreasure() {
	return treasureOfRoom;
}
bool Room::checkForPlayers() {
	return ((int) arrOfPlayers.size() > 0);
}
void Room::printerNonKilledMonsters() {
	for (int i = 0; i < arrOfMonsters.size(); i++) {
		cout << arrOfMonsters[i]->getName();
		if (i + 2 < arrOfMonsters.size())
			cout << " , ";
		else if (i + 2 == arrOfMonsters.size())
			cout << " and ";
	}
	cout << " .\n\n" ;
}
