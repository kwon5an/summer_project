#include "Character.h"
#include <iostream>

Character::Character(const std::string& name, int hp)
    : name(name), hp(hp), maxHp(hp) {
}

void Character::takeDamage(int damage) {
    hp -= damage;
    if (hp < 0) hp = 0;
    std::cout << name << " takes " << damage << " damage. (HP: " << hp << "/" << maxHp << ")\n";
}

void Character::heal(int amount) {
    hp += amount;
    if (hp > maxHp) hp = maxHp;
    std::cout << name << " heals for " << amount << ". (HP: " << hp << "/" << maxHp << ")\n";
}

bool Character::isAlive() const {
    return hp > 0;
}

std::string Character::getName() const {
    return name;
}

int Character::getHP() const {
    return hp;
}

int Character::getMaxHP() const {
    return maxHp;
}