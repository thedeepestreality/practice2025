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

    // void fit_in_box() {
    //     std::cout << "Cat is in a box (again)\n";
    // }

    int spy_data;
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
    c1.spy_data = 42;
    Dog g;
    Cat c2;
    c2.spy_data = 43;
    Platypus p;
    Animal* animals[] = {&c1, &g, &c2, &p};
    for (Animal* animal: animals){
        animal->roar();
        // Cat* c_ptr = reinterpret_cast<Cat*>(animal);
        Cat* c_ptr = dynamic_cast<Cat*>(animal);
        if (c_ptr != nullptr)
            std::cout << "cat spy data: " << c_ptr->spy_data << '\n';
        else
            std::cout << "Dis is not a cat\n";
        // type1 x;
        // type2 y = (type2)x;
    }

    // Animal a = Cat();
    // a.roar();

    const Animal &a_ref = Cat();
    a_ref.roar();

    return 0;
}
