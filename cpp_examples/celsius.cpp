#include <iostream>

int main(){
    int fahrenheit = 0;
    std::cout << "Fahrenheit = ";
    std::cin >> fahrenheit;
    double celsius = (fahrenheit - 32.0) * 5.0/9.0;
    std::cout << "Celsius = " << celsius << '\n';
    if (celsius > 40)
        std::cout << "Hot!\n";
    else if (celsius > 20)
        std::cout << "Good!\n";
    else
        std::cout << "Cold!\n";
    return 0;
}
