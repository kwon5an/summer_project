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
    virtual void heal(int amount);

    bool isAlive() const;
    string getName() const;
    int getHP() const;
    int getMaxHP() const;

    // 상태 출력
    virtual void printStatus() const = 0; // 순수가상함수
};

#endif
