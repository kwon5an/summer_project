#include <iostream>
#include <string>
#include <ctime> // srand(), time() 사용을 위해 추가
#include <cstdlib> // srand() 사용을 위해 추가
#include "GameManager.h"
using namespace std;

int main() {
    // 난수 생성기 초기화: 프로그램 시작 시 한 번만 호출
    srand(static_cast<unsigned int>(time(nullptr)));

    string name;
    cout << "플레이어 이름을 입력하세요: ";
    getline(cin, name); // 공백을 포함한 이름 입력 가능

    GameManager game(name);
    game.StartGame();

    return 0;
}