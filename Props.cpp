#include "Props.h"
#include "Monster.h"

Props::Props(string n, string d, Room* r,Monster* m1, Monster* m2) {
	name = n;
	descripion = d;
	curRoomOfProb = r;
	curRoomOfProb->setProps(this);
	monstersOfProps.push_back(m1);
	monstersOfProps.push_back(m2);
}
bool Props::act() {
	bool deadMonster = 0;
	vector<Monster *> arrOfMonsters = curRoomOfProb->getArrOfMonsters();
	for (int j = 0; j < (int)arrOfMonsters.size(); j++) {
		for (int i = 0; i < (int)monstersOfProps.size(); i++) {
			if (monstersOfProps[i]->getName() == arrOfMonsters[j]->getName()) {
				cout << "bravo you just killed the " << monstersOfProps[i]->getName() << " monster\n by one of your props and its " <<this->getName();
				cout << "you lost this prop now :D but you saved your ass :D \n\n";
				curRoomOfProb->leave(monstersOfProps[i]);
				curRoomOfProb->leaveMonster(monstersOfProps[i]);
				deadMonster = 1;
				break;
			}
		}
	}
	return deadMonster;
}

void Props::setCurRoomOfProb(Room *r) {
	curRoomOfProb = r;
}

string Props::getName() {
	return name;
}

string Props::getDescription() {
	return descripion;
}
Props::~Props() {
//dtor
}

