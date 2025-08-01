#include <iostream>
#include <string>
#include "GameManager.h"
using namespace std;

int main() {
    string name;
    cout << "플레이어 이름을 입력하세요: ";
    getline(cin, name);

    GameManager game(name);
    game.StartGame();

    return 0;
}
