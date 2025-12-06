#include <iostream>
#include <chrono>

int main(){
    const int N = 100000;
    char* dyn_str = nullptr;
    auto start = std::chrono::high_resolution_clock::now();
    for (int i=0; i < N; ++i){
        char* tmp = new char[i+1];
        for (int j=0; j<i; ++j)
            tmp[j] = dyn_str[j];
        tmp[i] = '0';
        delete[] dyn_str;
        dyn_str = tmp;
    }
    auto end = std::chrono::high_resolution_clock::now();
    delete[] dyn_str;

    auto microseconds = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Execution time [dyn]: " << microseconds.count() << " microseconds" << std::endl;

    start = std::chrono::high_resolution_clock::now();
    char stat_str[N];
    for (int i=0; i < N; ++i){
        stat_str[i] = '0';
    }
    end = std::chrono::high_resolution_clock::now();
    microseconds = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Execution time [stat]: " << microseconds.count() << " microseconds" << std::endl;
    return 0;
}
