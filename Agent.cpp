#include "Agent.h"
#include "Room.h"

Agent::Agent(string n, string d, Room * startingRoom) {
	name = n;
	description = d;
	curRoom = startingRoom;
	curRoom->enter(this);
}
void Agent::setCurRoom(Room* r) {
	curRoom = r;
}
string Agent::getName() {
	return name;
}

string Agent::getDescription() {
	return description;
}
Room* Agent::getCurRoom() {
	return curRoom;
}
Agent::Agent() {
	name = "";
	description = "";
	curRoom = NULL;
}

Agent::~Agent() {
	delete curRoom;
}
