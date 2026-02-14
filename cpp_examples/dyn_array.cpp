#include <iostream>

struct DynArrayInt{
private:
    int* m_data;
    int m_size;
public:
    void init(int sz);
    void deinit(){
        delete[] m_data;
        m_data = nullptr;
        m_size = 0;
    }

    int size(){
        return m_size;
    }

    int* data(){
        return m_data;
    }

    DynArrayInt(int sz){
        init(sz);
    }

    ~DynArrayInt(){
        std::cout << "Destructor\n";
        deinit();
    }
};

void DynArrayInt::init(int sz){
    m_size = sz;
    m_data = new int [m_size];
}

// void init(DynArrayInt& arr, int size){
//     arr.size = 3;
//     arr.data = new int [arr.size];
// }

// void deinit(DynArrayInt& arr){
//     delete[] arr.data;
//     arr.data = nullptr;
// }

struct A{
    int x;
};

// Classes have private access by default
class B{
    int x;
};

int main(){
    A a;
    a.x = 2;
    B b;
    // b.x = 3; // error
    {
        DynArrayInt arr(3);
        // init(arr, 3);
        // arr.init(3);
        // arr.size = 50000;
        for (int i = 0; i < arr.size(); ++i)
            arr.data()[i] = i;
        // arr.deinit();
    }
    std::cout << "Outside scope\n";
    return 0;
}
