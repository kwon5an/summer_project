#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
#include <string>
using namespace std;

class Player : public Character {
private:
    int ultimateCooldown;
    int healCooldown;

public:
    Player(const string& name, int hp);

    void basicAttack(Character& target);
    void skill2(Character& target);         // 치명타 공격
    void ultimateSkill(Character& target);  // 궁극기
    void heal();                            // 회복

    void reduceCooldowns();  // 턴마다 쿨타임 감소


    bool canUseUltimate() const;
    bool canUseHeal() const;

    void printStatus() const override;
};

#endif
