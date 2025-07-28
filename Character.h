#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
using namespace std;

class Character {
protected:
    std::string name;
    int hp;
    int maxHp;

public:
    Character(const string& name, int hp);
    virtual ~Character() = default;

    // 공통 기능
    virtual void takeDamage(int damage);
    virtual void heal(int amount);

    // 상태 정보
    bool isAlive() const;
    string getName() const;
    int getHP() const;
    int getMaxHP() const;

    // 각 캐릭터의 행동 - 오버라이딩 예상
    virtual void printStatus() const = 0;
};

#endif
