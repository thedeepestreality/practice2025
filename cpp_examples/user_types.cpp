#include <iostream>

union Dummy{
    int x;
    double y;
    bool z;
};

struct Person{
    char name[32];
    int age;
};

enum DayOfWeek{
    Monday,
    Tuesday,
    Wendesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
};

// void turnLight(bool state){

// }

enum class SwitchState{
    On = 10,
    Off
};

void turnLight(SwitchState state){

}

// // dir = -1 -> counter-clockwise
// // dir = 0 -> stop
// // dir = 1 -> clockwise
// void motorRun(int dir){

// }

enum class Direction{
    CounterClockwise = -1,
    Stop = 0,
    Clockwise = 1
};

void motorRun(Direction dir){

}

struct Bytes{
    unsigned char b1;
    unsigned char b2;
    unsigned char b3;
    unsigned char b4;
};

struct BitField{
    unsigned char b1 : 1;
    unsigned char b2 : 1;
    unsigned char b3 : 1;
    unsigned char b4 : 1;
    unsigned char b5 : 1;
    unsigned char b6 : 1;
    unsigned char b7 : 1;
    unsigned char b8 : 1;
};

struct PseudoClass {
    int x;
    int func(){
        x = 10;
        return x*2;
    }
};

int main(){
    Dummy d;
    d.x = 2;
    d.y = 1.5;

    // turnLight(true);
    turnLight(SwitchState::On);
    motorRun(Direction::CounterClockwise);
    Direction dir = Direction::Stop;
    int dir_int = (int)dir;

    int val = 260;
    // Bytes int_val = *(Bytes*)&val;
    Bytes int_val = *reinterpret_cast<Bytes*>(&val);
    std::cout << (int)int_val.b1 << ' ' << (int)int_val.b2 << '\n';

    BitField bf = *reinterpret_cast<BitField*>(&int_val.b1);
    std::cout << (int) bf.b1 << ' ' << (int) bf.b2 << ' ' << (int) bf.b3 << '\n';
    return 0;
}
