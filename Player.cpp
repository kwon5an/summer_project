#include "Player.h"
#include <iostream>
#include <cstdlib>  // rand()
#include <ctime>    // time()
using namespace std;

Player::Player(const std::string& name, int hp)
    : Character(name, hp), ultimateCooldown(0), healCooldown(0) {
    srand(std::time(nullptr));  // 치명타 확률용 시드 초기화
}

void Player::basicAttack(Character& target) {
    int damage = 10;
    cout << getName() << "이/가 기본공격을 사용했습니다!\n";
    target.takeDamage(damage);
}

void Player::skill2(Character& target) {
    cout << getName() << "이/가 강화 스킬을 사용했습니다!!(치명타)\n";
    int critChance = std::rand() % 100;  // 0~99
    int damage = (critChance < 30) ? 30 : 15;  // 30% 확률로 치명타
    if (critChance < 30)
        cout << "치명타 적중!!\n";
    else
        cout << "적중 실패!.\n";
    target.takeDamage(0);
}

void Player::ultimateSkill(Character& target) {
    if (canUseUltimate()) {
        cout << getName() << "이/가 궁극기를 사용했습니다!!\n";
        target.takeDamage(50);
        ultimateCooldown = 5;  // 쿨타임 5턴
    }
    else {
        cout << "궁극기는 아직 쿨타임입니다! (" << ultimateCooldown << " 만큼 턴이 남았습니다.).\n";
    }
}

void Player::heal() {
    if (canUseHeal()) {
        int healAmount = (getMaxHP() - getHP()) * 0.5;  // 깎인 체력의 50% 회복
        if (healAmount <= 0) healAmount = 0;
        cout << getName() << "이/가 체력을 회복하였습니다!" << healAmount << " 만큼 체력 회복!!\n";
        Character::heal(healAmount);
        healCooldown = 3;  // 쿨타임 4턴
    }
    else {
        cout << "힐 스킬은 아직 쿨타임입니다!!(" << healCooldown << " 만큼 남았습니다!).\n";
    }
}

void Player::reduceCooldowns() {
    if (ultimateCooldown > 0) ultimateCooldown--;
    if (healCooldown > 0) healCooldown--;
}

bool Player::canUseUltimate() const {
    return ultimateCooldown == 0;
}

bool Player::canUseHeal() const {
    return healCooldown == 0;
}
