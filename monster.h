#ifndef MONSTER_H
#define MONSTER_H

#include "Character.h" // Character 클래스를 상속받기 위해 포함
#include <string>

class Monster : public Character { // Character 클래스 상속
public:
    // 생성자: Character 생성자를 호출하고 몬스터 고유의 속성을 초기화
    Monster(const std::string& name, int hp, int baseDamage, int ultDamage, int ultCooldown);

    // 몬스터의 턴 행동 (스킬 사용). Character 클래스에는 없는 Monster 고유의 기능
    int performAction(); // 몬스터가 가하는 피해량을 반환

    // 쿨타임 감소. Character 클래스에는 없는 Monster 고유의 기능
    void decreaseCooldown();

private:
    int baseAttackDamage;
    int ultimateAttackDamage;
    int ultimateCooldownMax; // 궁극기 최대 쿨타임
    int ultimateCooldownCurrent; // 궁극기 현재 쿨타임
};

#endif