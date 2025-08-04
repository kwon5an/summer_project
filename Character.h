#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
using namespace std;

class Character {
protected:
    string name;
    int hp;
    int maxHp;

public:
    Character(const string& name, int hp);
    virtual ~Character() = default;

    virtual void takeDamage(int damage);
    virtual void heal(int amount); // Character의 heal은 amount 인자를 받음

    bool isAlive() const;
    string getName() const;
    int getHP() const;
    int getMaxHP() const;

    virtual void printStatus() const = 0; // 순수 가상 함수
};

#endif