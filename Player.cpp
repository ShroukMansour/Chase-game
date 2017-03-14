#include "Player.h"
#include "Room.h"
#include "Props.h"
#include "FixedObject.h"
#include "Treasure.h"

Player::Player(string n, Room* startingRoom) {
	name = n;
	curRoom = startingRoom;
	curRoom->enter(this);
	curRoom->enterPlayer(this);
}
void Player::takeProp(string p) {
	Props * c = curRoom->getProp(p);
	if (c != NULL) {
		propsOfPlayer.push_back(c);
		c->setCurRoomOfProb(NULL);
	} else
		cout << "This prop does not exist is this room \n";
}
void Player::leaveProp(string p) {
	for (int i = 0; i < (int) propsOfPlayer.size(); i++) {
		if (propsOfPlayer[i]->getName() == p) {
			curRoom->setProps(propsOfPlayer[i]);
			propsOfPlayer.erase(propsOfPlayer.begin() + i);
			return;
		}
	}
	cout << "You don't carry this prop from the first place\n";

}
bool Player::actByProps() {
	int numberOfDeadMonsters = 0, numberOfMonsters =
			curRoom->getArrOfMonsters().size();
	if (curRoom->getArrOfMonsters().size()) {
		cout << "there exist monster or more in this room check your props to kill them\n\n";
		for (int i = 0; i < (int) propsOfPlayer.size(); i++) {
			propsOfPlayer[i]->setCurRoomOfProb(curRoom);
			numberOfDeadMonsters += propsOfPlayer[i]->act();
		}
		if (numberOfDeadMonsters != numberOfMonsters) {
			vector <Monster*> nonkilled = curRoom->getArrOfMonsters();
			cout << "You couldn't beaten the following monsters: ";
			curRoom->printerNonKilledMonsters();
			if (curRoom->getFixedObj() != NULL) {
				if (curRoom->getFixedObj()->act() == false)
					return false;
				else
					actByProps();
			}
			else {
				cout << " \nsorry the helping stuff could'nt save you \n" ;
				return  false ;
			}
		}
	}
	else {

	}
	return true;
}
bool Player::act() {
	cout << endl <<"--->>>> "<< name << ", it's your turn, you are in the "
			<< curRoom->getName() << curRoom->getDescription() << "\n";
	curRoom->leave(this);
	curRoom->printOccupants();
	curRoom->enter(this);
	if (actByProps() == false )
		return false;
	while (true) {
		cout << "You only can take 3 props.\n";
		cout << "tell us if you want to leave a prop or take a prop\n\n";
		string choiceOfleaving, choiceOfTaking;
		printPropsPlayer();
		while (true) {
			cout << "Do. you want to leave a prop?\n";
			cout << "Enter yes or no.\n\n";
			cin >> choiceOfleaving;
			if (choiceOfleaving == "yes") {
				if (!printPropsPlayer())
					break;
				cout << " Enter the prop you want to leave\n";
				printPropsPlayer();
				string leaveprop;
				cin >> leaveprop;
				leaveProp(leaveprop);
			} else
				break;
		}
		bool flag = 0;
		while (true) {
			cout << "Do you want to take a prop? \n";
			cout << "Enter yes or no.\n\n";
			cin >> choiceOfTaking;
			if (propsOfPlayer.size() == 3 && choiceOfTaking == "yes") {
				cout << "You can't take any prop because you are already full "
						"if you want to ,then you have to leave a prop\n ";
				flag = 1;
				break;
			}
			if (choiceOfTaking == "yes") {
				cout
						<< "Enter the prop you want to take from the following choices and it might be no props so dont get angry if there is't :D and good luck :D \n";
				if (!curRoom->printProps())
					break;
				string takeprop;
				cin >> takeprop;
				takeProp(takeprop);
			} else
				break;
			cout << printPropsPlayer()
					<< " Do you want to take more props from this room? \n";

		}
		if (!flag) {
			cout << "We appreciate your choices :D please go on :D \n\n";
			break;
		}
	}
	while (true) {
		curRoom->printLinked();
		cout
				<< "\nEnter the room you want to go in or just quit and then you will lose the game and the others will continue\n\n";
		string direction;
		cin >> direction;
		if (direction == "quit") {
			curRoom->leave(this);
			curRoom->leavePlayer(this);
			return false;
		}
		if ((direction != "north" && direction != "south" && direction != "east"
				&& direction != "west") || curRoom->getLinked(direction) == NULL) {
			cout << "\nplease enter a correct direction\n";
			continue;
		} else {
			curRoom->leave(this);
			curRoom->leavePlayer(this);
			curRoom = curRoom->getLinked(direction);
			cout << "\nyou moved to " << direction << " and you are in "
					<< curRoom->getName() << "...\n\n\n";
			curRoom->enter(this);
			curRoom->enterPlayer(this);
			if (actByProps() == false)
				return false;
			if (curRoom->getTreasure() != NULL) {
				cout << getName() << " " ;
				curRoom->getTreasure()->act();
			}
		}
		break;
	}
	return true;
}
bool Player::printPropsPlayer() {
	if (!propsOfPlayer.size()) {
		cout
				<< "you dont carry any prop from the first place to leave , please go on and tell us . \n\n";
		return false;
	} else {
		if (propsOfPlayer.size() == 1)
			cout << "you carry one prop and it's : ";
		else
			cout << "The props you carry are  : ";
		for (int i = 0; i < (int) propsOfPlayer.size(); i++) {
			cout << propsOfPlayer[i]->getName();
			if (i + 2 < (int) propsOfPlayer.size())
				cout << " , ";
			else if (i + 2 == (int) propsOfPlayer.size())
				cout << " and ";
		}
		cout << " .\n\n";
	}
	return true;
}
