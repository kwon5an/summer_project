#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "Player.h"
#include "Monster.h"
// #include <set> // 불필요한 헤더 제거
#include <vector>
#include <string>

using namespace std;

class GameManager {
private:
    Player* player;
    Monster* monster;
    int monsterCount;
    int turn;

    // 이벤트 턴 저장용
    vector<int> eventTurns;

    // 이벤트 관련 함수들
    void GenerateEarlyEventTurns();
    bool ShouldTriggerRandomEvent();
    void TriggerRandomEvent(); // 실제 이벤트 효과 함수
    void CheckEventTurn(); // 이 함수는 private으로 두는 것이 GameManager의 역할에 더 적합

public:
    GameManager(const string& playerName);
    ~GameManager();

    void StartGame();
    void PlayerTurn();
    void MonsterTurn();
    void PrintStatus();
    bool IsGameover();
};

#endif