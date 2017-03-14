#include "Game.h"

Game::Game() {
}

vector<Agent*> Game::arrOfAgents = vector<Agent*>();
Agent* Game::currAgent = NULL;

void Game::Winning() {
	exit(0);
}
void Game::arrOfAgent(vector<Agent*> agent) {
	arrOfAgents = agent;
	cout << "Welcome!\n\n";
	int c = 0;
	while (c != 2) {
		for (int i = 0; i < (int) agent.size(); i++) {
			currAgent = agent[i];
			bool ok = agent[i]->act();
			if (!ok) {
				Game::Losing(agent[i]);
				c++;
			}
		}
		agent.clear();
		agent = arrOfAgents;
	}
	cout << "The game has ended and nobody won  good luck in the next time .\n";
	exit(0);
}

void Game::Losing(Agent *ag) {
	if (ag->getName() == "Brain " || ag->getName() == "Pinky ")
		cout << ag->getName() << " sorry you lost sir ,Good luck next time -_-\n";
	else
		cout << "you have be beaten by " << ag->getName() <<"becaue he got the appropriate prop to kill you\n\n" ;
	for (int i = 0; i < (int) arrOfAgents.size(); i++) {
		if (arrOfAgents[i]->getName() == ag->getName()) {
			arrOfAgents.erase(arrOfAgents.begin() + i);
			return;
		}
	}
}

Game::~Game() {

}

Agent* Game::getAgent() {
	return currAgent;
}
