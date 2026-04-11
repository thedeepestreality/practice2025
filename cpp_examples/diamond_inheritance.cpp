#include <iostream>

struct Animal {
    double weight;
};

struct FurryAnimal : virtual Animal {
    double fur_length;
};

struct WaterAnimal : virtual Animal {
    double max_depth;
};

struct Platypus : FurryAnimal, WaterAnimal {
    int egg_count;
};

int main(){
    Platypus p;
    p.egg_count = 3;
    p.weight = 20.0;
    return 0;
}

// Platypus (without virtual inheritance):
// |weight|fur_length|weight|max_depth|egg_count|
// |   FurrynAnimal  |   WaterAnimal  | Platypus|

// Platypus (with virtual inheritance):
// |weight|fur_length| max_depth |egg_count|
// |   FurrynAnimal  |WaterAnimal| Platypus|

//          |Animal|
//         /        \
//        /          \
//       /            \
// [FurryAnimal]    [WaterAnimal]
//       \           /
//        \         /
//         \       /
//         [Platypus]