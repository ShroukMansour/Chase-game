#include <bits/stdc++.h>
#include "Agent.h"
#include "Monster.h"
#include "Room.h"
#include "Player.h"
#include "Game.h"
#include "ChaseMonster.h"
#include "TreasureMonster.h"
#include "RandomMonster.h"
#include  "FixedObject.h"
#include "Props.h"
#include "Treasure.h"

using namespace std;

int main() {
	srand(time(NULL));

	Room *r1 =
			new Room("MERCURY ",
					"All you can see is a larger version of the moon but be careful, you are very close to the SUN!! ");
	Room *r2 =
			new Room("VENUS ",
					"You are now surrounded by thick toxic clouds which may kills you ");
	Room *r3 =
			new Room("MARS ",
					"you see only two colors around you red and blue, blue for water canals and red for volcanoes as THE LARGEST VOLCANOES OF ANY PLANET ARE ON MARS.");
	Room *r4 =
			new Room("JUPITER ",
					"you are in a small boat floating above liquid metals. You can not see the land... Don't waste your time, there is no land here ");
	Room *r5 =
			new Room("URANUS ",
					"you can see a blue light, the blue color is from the methane in the atmosphere which absorbs.");
	Room *r6 =
			new Room("NEPTON ",
					"It's so windy overhere! you are in the planet that has the fastest winds of any planet in the solar system up to 2,100 Km/hr");
	Room *r7 =
			new Room("MOON ",
					"No, It's not covered with cheese. It is covered with dead volcanoes, impact craters, and lava flows.");
	Room *r8 = new Room("PLUTO ",
			"you are on the edge of the solar system. be careful!");
	Room *r9 =
			new Room("SUN ",
					"It is a nearly perfect sphere of hot plasma that generates a magnetic field. you are in the biggest star in the solar system and the most important source of energy in the solar system! ");


	r1->link(r8, "north");
	r1->link(r7, "south");
	r7->link(r4, "south");
	r7->link(r2, "east");
	r7->link(r3, "west");
	r2->link(r5, "east");
	r4->link(r9, "south");
	r3->link(r6, "west");


	Treasure *tr = new Treasure("TimeMachine ",
			" this machine will move you to the EARTH ", r6);


	Player *player1 = new Player("Pinky ", r9);
	Player *player2 = new Player("Brain ", r9);


	FixedObject *f1 = new FixedObject("sea", " the sea will move you from ", r2,
			r3);
	FixedObject *f2 = new FixedObject("disappearing Machine",
			" the disappearing Machine will move you from ", r4, r8);


	RandomMonster *random = new RandomMonster("METEOR",
			"this is a meteor monster that you can't beat ", r1);


	ChaseMonster *chase1 =
			new ChaseMonster("FIRE Monster",
					" this Monster will throw fire on you if it touched you, you will die ",
					r1);
	ChaseMonster *chase2 =
			new ChaseMonster("ALIEN",
					" if this Monster looked at you, it will produce some kind of rays which will kill you ",
					r8);


	TreasureMonster *t =
			new TreasureMonster("el lahw el5afy",
					"  the most danger one  here! You never be able to win before killing it, be careful! ",
					r6);


	Props *p1 = new Props("bomb", "", r8, (Monster*) chase1, (Monster*) chase2);
	Props *p2 = new Props("water", "", r1, (Monster*) chase1,
			(Monster*) chase1);
	Props *p3 = new Props("water", "", r3, (Monster*) chase1,
			(Monster*) chase1);
	Props *p4 = new Props("lazer", "", r6, (Monster*) chase2,
			(Monster*) chase2);
	Props *p5 = new Props("glass", "", r4, (Monster*) t, (Monster*) t);
	Props *p6 = new Props("lazer", "", r5, (Monster*) chase2,
			(Monster*) chase2);

	vector<Agent *> agent;

	agent.push_back(player1);
	agent.push_back(player2);
	agent.push_back(random);
	agent.push_back(chase1);
	agent.push_back(chase2);
	agent.push_back(t);
	cout << "please open :'d am dying here" << endl;
	Game::arrOfAgent(agent);
}
