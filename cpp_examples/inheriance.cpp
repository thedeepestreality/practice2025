#include <iostream>

struct Animal {
    virtual void roar() const = 0;
    // {
    //     std::cout << "Abstract animal roar\n";
    // }
};

void Animal::roar() const {
    std::cout << "Abstract animal roar\n";
}

struct Cat : Animal {
    void roar() const override {
        std::cout << "Meow!\n";
    }
};

struct Dog : Animal {
    void roar() const override {
        std::cout << "Wuf!\n";
    }
};

struct Platypus : Animal {
    void roar() const override {
        Animal::roar();
        std::cout << "Unknown platypus sounds\n";
    }
};

int main(){
    std::cout << sizeof(Animal) << '\n';
    Cat c1;
    Dog g;
    Cat c2;
    Platypus p;
    Animal* animals[] = {&c1, &g, &c2, &p};
    for (Animal* animal: animals)
        animal->roar();

    // Animal a = Cat();
    // a.roar();

    const Animal &a_ref = Cat();
    a_ref.roar();

    return 0;
}
