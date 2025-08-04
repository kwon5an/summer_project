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
    void skill2(Character& target);          // 치명타 공격

    bool ultimateSkill(Character& target);  // 궁극기
    bool heal();                             // 인자 없는 힐 (쿨타임 적용)

    void heal(int amount); // Character의 heal을 Player에서도 명시적으로 사용하겠다고 선언

    void reduceCooldowns();  // 턴마다 쿨타임 감소


    bool canUseUltimate() const;
    bool canUseHeal() const;

    int getUltimateCooldown() const;
    int getHealCooldown() const;

    void printStatus() const override;

    void increaseMaxHP(int amount);
    void healToFull();
    void resetUltimateCooldown();
};

#endif