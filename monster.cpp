#include "Monster.h"
#include <iostream>
using namespace std;

Monster::Monster(const string& name, int hp, int baseDamage, int ultDamage, int ultCooldown)
    : Character(name, hp),
    baseAttackDamage(baseDamage),
    ultimateAttackDamage(ultDamage),
    ultimateCooldownMax(ultCooldown),
    ultimateCooldownCurrent(0) {
}

int Monster::performAction() {
    if (ultimateCooldownCurrent == 0) {
        cout << name << "이/가 궁극기를 사용합니다! (" << ultimateAttackDamage << " 피해)\n";
        ultimateCooldownCurrent = ultimateCooldownMax;
        return ultimateAttackDamage;
    }
    else {
        cout << name << "이/가 기본 공격을 합니다! (" << baseAttackDamage << " 피해)\n";
        return baseAttackDamage;
    }
}

void Monster::decreaseCooldown() {
    if (ultimateCooldownCurrent > 0) {
        ultimateCooldownCurrent--;
    }
}

// 추가: 몬스터 궁극기 현재 쿨타임을 가져오는 함수 구현
int Monster::getUltimateCooldownCurrent() const {
    return ultimateCooldownCurrent;
}

void Monster::printStatus() const {
    cout << name << " (몬스터) HP: " << hp << "/" << maxHp << "\n";

    // 추가: 몬스터 궁극기 쿨타임 표시
    if (ultimateCooldownCurrent == 0) {
        cout << " [궁극기 사용 가능!]\n";
    }
    else {
        cout << " [궁극기 쿨타임: " << ultimateCooldownCurrent << "턴]\n";
    }
}

