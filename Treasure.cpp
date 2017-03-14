#include "Treasure.h"
#include "Game.h"

Treasure::Treasure(string n, string d, Room * c) {
	name = n;
	description = d;
	curRoom = c;
	curRoom->setTreasure(this);
}
bool Treasure::act() {
	cout << "Congratulation you win the whole game and you got to the treasure that it's\n";
	cout << getName() << "\n" << getDescription();
	Game::Winning();
	return true;
}
Room * Treasure::getCurRoom() {
	return curRoom;
}
string Treasure::getName() {
	return name;
}
string Treasure::getDescription() {
	return description ;
}
