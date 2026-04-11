#include <iostream>
#include <vector>
#include <list>

int main(){
    const int SZ = 5;
    int arr[SZ] = {1, 2, 3, 4, 5};
    for (int* ptr = arr; ptr < arr + SZ; ++ptr)
        std::cout << *ptr << ' ';
    std::cout << '\n';

    std::vector<int> vec = {1, 2, 3, 4, 5};
    // for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
    for (auto it = vec.begin(); it != vec.end(); ++it){
        int val = *it;
        std::cout << val << ' ';
    }
    std::cout << '\n';

    for (const int& val: vec)
        std::cout << val << ' ';
    std::cout << '\n';

    std::list<int> lst = {1, 2, 3, 4 ,5};

    for (int val: lst)
        std::cout << val << ' ';
    std::cout << '\n';

    // int* dyn_arr = new int [3];
    // dyn_arr[0] = 1;
    // dyn_arr[1] = 2;
    // dyn_arr[2] = 3;
    // int* ptr = arr;
    for (int val: arr)
        std::cout << val << ' ';
    std::cout << '\n';

    return 0;
}