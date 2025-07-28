#include "Player.h"
#include <iostream>
using namespace std;


Player::Player(const std::string& name, int hp)
    : Character(name, hp), ultimateCooldown(0), healCooldown(0) {
}

void Player::basicAttack(Character& target) {
    int damage = 10;
    std::cout << getName() << "이/가 기본공격을 사용했습니다!\n";
    target.takeDamage(damage);
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
