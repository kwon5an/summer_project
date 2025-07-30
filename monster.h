#ifndef MONSTER_H
#define MONSTER_H

#include "Character.h" // Character 클래스를 상속받기 위해 포함
#include <string>

using namespace std;

class Monster : public Character {
public:
    // 생성자
    Monster(const string& name, int hp, int baseDamage, int ultDamage, int ultCooldown);

    // performAction 함수를 가상 함수로 선언하여 파생 클래스에서 오버라이딩 가능하게 함
    // virtual 키워드 추가
    virtual int performAction(); // 몬스터가 가하는 피해량을 반환

    void decreaseCooldown();

protected: // 자식 클래스에서 접근할 수 있도록 protected로 변경
    int baseAttackDamage;
    int ultimateAttackDamage;
    int ultimateCooldownMax;
    int ultimateCooldownCurrent;
};

#endif