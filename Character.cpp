#include "Character.h"
#include <iostream>
using namespace std;

Character::Character(const string& name, int hp)
    : name(name), hp(hp), maxHp(hp) {
}

void Character::takeDamage(int damage) {
    hp -= damage;
    if (hp < 0) hp = 0;

    cout << name << "이/가 " << damage << "의 데미지를 입었습니다. (HP: " << hp << "/" << maxHp << ")\n";
}

void Character::heal(int amount) {
    hp += amount;
    if (hp > maxHp) hp = maxHp;

    cout << name << "이/가 " << amount << "만큼 체력을 회복했습니다. (HP: " << hp << "/" << maxHp << ")\n";
}

bool Character::isAlive() const {
    return hp > 0;
}

string Character::getName() const {
    return name;
}

int Character::getHP() const {
    return hp;
}

int Character::getMaxHP() const {
    return maxHp;
}