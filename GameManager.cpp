#include "GameManager.h"
#include <iostream>
using namespace std;

GameManager::GameManager(const string& playerName) {
    monsterCount = 1;
    turn = 1;
    player = new Player(playerName, 100);
    monster = new Monster("Monster1", 50, 10, 25, 3);
}

GameManager::~GameManager() {
    delete player;
    delete monster;
}

void GameManager::StartGame() {
    cout << "게임 시작!\n";
    while (true) {
        cout << "\n===== [Turn " << turn << "] =====\n";
        PrintStatus();

        PlayerTurn();
        if (IsGameover()) break;

        MonsterTurn();
        if (IsGameover()) break;

        turn++;
    }
}

void GameManager::PlayerTurn() {
    int skill;
    while (true) {
        cout << "플레이어의 턴입니다. 스킬을 선택하세요:\n";
        cout << "1. 기본 공격\n";
        cout << "2. 스킬 (치명타 공격)\n";
        cout << "3. 궁극기\n";
        cout << "4. 힐\n";
        cout << ">> ";
        cin >> skill;

        if (skill < 1 || skill > 4) {
            cout << "잘못된 선택입니다. 다시 시도하세요.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        switch (skill) {
        case 1:
            player->basicAttack(*monster);
            break;
        case 2:
            player->skill2(*monster);
            break;
        case 3:
            player->ultimateSkill(*monster);
            break;
        case 4:
            player->heal();
            break;
        }

        player->reduceCooldowns();
        break;
    }
}

void GameManager::MonsterTurn() {
    cout << "몬스터의 턴입니다.\n";
    int damage = monster->performAction();
    player->takeDamage(damage);
    monster->decreaseCooldown();
}

void GameManager::PrintStatus() {
    cout << "[현재 상태]\n";
    player->printStatus();
    monster->printStatus();
}

bool GameManager::IsGameover() {
    if (!player->isAlive()) {
        cout << "플레이어가 패배했습니다. 게임 종료.\n";
        return true;
    }

    if (!monster->isAlive()) {
        cout << "몬스터를 처치했습니다!\n";
        delete monster;
        monsterCount++;
        monster = new Monster("Monster" + to_string(monsterCount), 50 + monsterCount * 10, 10 + monsterCount * 2, 25 + monsterCount * 2, 3);
        cout << monster->getName() << "이/가 새로 등장했습니다!\n";
    }

    return false;


}
