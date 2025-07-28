#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"  // Character 클래스 상속받기 위해 포함
#include <string>

class Player : public Character {
private:
    int ultimateCooldown;  // 궁극기 쿨타임
    int healCooldown;      // 힐 쿨타임

public:
    Player(const std::string& name, int hp);

    void basicAttack(Character& target);
    void skill2(Character& target);     // 치명타 공격
    void ultimateSkill(Character& target); // 궁극기 (쿨타임 있음)
    void heal();                        // 힐 (쿨타임 있음)

    void reduceCooldowns();  // 쿨타임 1씩 줄이기 (턴마다 호출)

    bool canUseUltimate() const;
    bool canUseHeal() const;
};

#endif
