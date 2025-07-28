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

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
