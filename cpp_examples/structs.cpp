#include <iostream>
#include <fstream>

#pragma pack(1)
struct Dummy{
    char c;
    int i;
    // double d;
};
#pragma pop

int main(){
    std::cout << sizeof(Dummy) << '\n';
    // std::ofstream out("out.bd", std::ios::binary);
    // Dummy d;
    // // out << d.c << d.i;
    // // out.write((char*)&d.c, 1);
    // // out.write((char*)&d.i, 4);
    // out.write((char*)&d, sizeof(d));

    return 0;
}
