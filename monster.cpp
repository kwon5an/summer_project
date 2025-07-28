// summer_project.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "Monster.h"
#include <iostream>
#include <random> // 랜덤 함수 사용을 위해 추가
using namespace std;

// Monster 생성자: Character의 생성자를 호출하여 name과 hp를 초기화합니다.
// 그 다음 Monster 고유의 멤버 변수들을 초기화합니다.

Monster::Monster(const string& name, int hp, int baseDamage, int ultDamage, int ultCooldown)
    : Character(name, hp), // Character 클래스의 생성자 호출
    baseAttackDamage(baseDamage),
    ultimateAttackDamage(ultDamage),
    ultimateCooldownMax(ultCooldown),
    ultimateCooldownCurrent(0) { // 시작 시 쿨타임은 0 또는 지정 값으로 초기화
}

int Monster::performAction() {
    if (ultimateCooldownCurrent == 0) {
        // 궁극기 사용
        cout << getName() << "이(가) 궁극기를 사용합니다! (" << ultimateAttackDamage << " 피해)" << std::endl;
        ultimateCooldownCurrent = ultimateCooldownMax; // 궁극기 사용 후 쿨타임 초기화
        return ultimateAttackDamage;
    }
    else {
        // 기본 공격
        cout << getName() << "이(가) 기본 공격을 합니다! (" << baseAttackDamage << " 피해)" << std::endl;
        return baseAttackDamage;
    }
}

void Monster::decreaseCooldown() {
    if (ultimateCooldownCurrent > 0) {
        ultimateCooldownCurrent--;
    }
}
int main()
{

}
