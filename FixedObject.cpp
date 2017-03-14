#include "FixedObject.h"
#include "Room.h"

FixedObject::FixedObject(string n, string d, Room *curRoo, Room *newRoo) {
	name = n;
	description = d;
	curRoom = curRoo;
	curRoom->setFixedobj(this);
	newRoom = newRoo;
	newRoom->setFixedobj(this);
}
string FixedObject::getName() {
	return name;
}
string FixedObject::getdescription() {
	return description;
}
bool FixedObject::act() {
	cout << "there exist a fixed object in this room and its " << getName()
			<< " " << getdescription() << " " << curRoom->getName() << " to "
			<< newRoom->getName() << endl << endl;
	cout
			<< "if you didnt use it you will die by the monsters do you want to use it ?\n";
	cout << "Enter yes or no\n\n";
	string yourChoice;
	cin >> yourChoice;
	if (yourChoice == "yes") {
		curRoom->leave(Game::getAgent());
		curRoom->leavePlayer((Player*) Game::getAgent());
		newRoom->enter(Game::getAgent());
		newRoom->enterPlayer((Player*) Game::getAgent());
		cout << " and you are in " << newRoom->getName() << "...\n\n\n";
		return true;
	}
	return false;
}
