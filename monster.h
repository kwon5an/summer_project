#ifndef MONSTER_H
#define MONSTER_H

#include "Character.h"
#include <string>
using namespace std;

class Monster : public Character {
public:
    Monster(const string& name, int hp, int baseDamage, int ultDamage, int ultCooldown);

    int performAction();     // 공격 결정 및 데미지 반환
    void decreaseCooldown(); // 쿨타임 감소

    void printStatus() const override;

protected:
    int baseAttackDamage;
    int ultimateAttackDamage;
    int ultimateCooldownMax;
    int ultimateCooldownCurrent;
};

#endif
