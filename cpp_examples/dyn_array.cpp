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

    int size() const {
        return m_size;
    }

    void resize(int new_sz){
        int* tmp = new int[new_sz];
        for (int idx = 0; idx < std::min(m_size, new_sz); ++idx)
            tmp[idx] = m_data[idx];
        delete[] m_data;
        m_data = tmp;
        m_size = new_sz;
    }

    int* data() {
        // m_data = nullptr;
        // m_data[0] = 3;
        // *(m_data+0) = 3;
        return m_data;
    }

    const int* data() const {
        return m_data;
    }

    // Parameterized constructor
    // Параметризованный конструктор
    DynArrayInt(int sz){
        init(sz);
    }

    // Another parameterized constructor
    // Другой параметризованный конструктор
    DynArrayInt(const int* data, int sz){
        init(sz);
        for (int idx = 0; idx < sz; ++idx)
            m_data[idx] = data[idx];
    }

    // Default constructor
    // Конструктор по умолчанию
    // DynArrayInt(){
    //     m_data = nullptr;
    //     m_size = 0;
    // }
    // Order of the init is not as initializer list
    // but as in struct/class field order
    DynArrayInt() : m_data(nullptr), m_size(0)
    {}

    // Copy constructor
    // Конструктор копий
    // (Копирующий конструктор)
    DynArrayInt(const DynArrayInt& src) : DynArrayInt(src.data(), src.size())
    {}

    // DynArrayInt(const DynArrayInt& src){
    //     init(src.size());
    //     for (int idx = 0; idx < m_size; ++idx)
    //         m_data[idx] = src.data()[idx];
    // }

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

    const DynArrayInt const_arr(3);
    // const_arr.size();
    // const_arr.data()[0] = 42;

    DynArrayInt arr(3);
    DynArrayInt default_arr;

    DynArrayInt arr_copy(arr.data(), arr.size());
    // DynArrayInt arr2(arr);
    DynArrayInt arr2 = arr; // Call to copy constructor

    // default_arr = arr; // Assignment operator

    return 0;
}
