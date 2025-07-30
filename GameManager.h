#include <iostream>
#include <string>
#include "character.h"
#include "Player.h"
#include "Monster.h"
#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

using namespace std;

class GameManager {
private:
	Player* player;
	Monster* monster;
	int monsterCount;
	int turn;

public:
	GameManager(const string& PlyerName);
	~GameManager();

	void StartGame();
	void PlayerTurn();
	void MonsterTurn();
	void PrintStatus();
	bool IsGameover();
};

#endif GAMEMANAGER_H
