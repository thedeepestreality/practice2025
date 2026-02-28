#include <iostream>
#include <cstdint>

template <typename Type>
class Vector{
private:
    Type* m_data;
    size_t m_size;
    size_t m_capacity;
public:
    Vector() :
        m_data(new Type[1]),
        m_size(0),
        m_capacity(1)
    {}

    ~Vector(){
        delete[] m_data;
        m_data = nullptr;
    }

    Type& operator[](int idx){
        return m_data[idx];
    }

    void push_back(const Type& val){
        if (m_size < m_capacity){
            m_data[m_size++] = val;
            return;
        }
        m_capacity *= 2;
        Type* tmp = new Type[m_capacity];
        for (size_t idx = 0; idx < m_size; ++idx)
            tmp[idx] = m_data[idx];
        delete[] m_data;
        m_data = tmp;
        m_data[m_size++] = val;
    }

    void print() const{
        for (size_t idx = 0; idx < m_size; ++idx)
            std::cout << m_data[idx] << ' ';
        std::cout << '\n';
    }
};

template<>
class Vector<bool>{
private:
    uint32_t* m_data;
    size_t m_size;
    size_t m_capacity;
public:
    static void set_bit(uint32_t *data, size_t idx, bool val){
        size_t byte_idx = idx / 32;
        size_t bit_idx = idx % 32;
        if (val)
            data[byte_idx] |= (1 << bit_idx);
        else
            data[byte_idx] &= ~(1 << bit_idx);
    }

    ~Vector(){
        delete[] m_data;
        m_data = nullptr;
    }

    Vector() :
        m_data(new uint32_t[1]),
        m_size(0),
        m_capacity(32)
    {}

    void push_back(bool val){
        if (m_size < m_capacity){
            set_bit(m_data, m_size++, val);
            return;
        }
        m_capacity *= 2;
        uint32_t* tmp = new uint32_t[m_capacity / 32];
        for (size_t idx = 0; idx < m_size; ++idx)
            tmp[idx] = m_data[idx];
        delete[] m_data;
        m_data = tmp;
        set_bit(m_data, m_size++, val);
    }

    class VecProxy;

    VecProxy operator[](size_t idx){
        return VecProxy(m_data, idx);
    }

    class VecProxy{
    private:
        uint32_t* m_data;
        size_t m_idx;
    public:
        VecProxy(uint32_t* data, size_t idx) : m_data(data), m_idx(idx)
        {}

        VecProxy& operator=(bool val){
            Vector<bool>::set_bit(m_data, m_idx, val);
            return *this;
        }

        operator bool(){
            size_t byte_idx = m_idx / 32;
            size_t bit_idx = m_idx % 32;
            return (m_data[byte_idx] >> bit_idx) & 0x01;
        }
    };
};

int main(){
    Vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    vec[1] = 10;

    vec.print();

    Vector<bool> vec_bool;
    vec_bool.push_back(true);
    vec_bool.push_back(false);
    vec_bool.push_back(true);
    vec_bool[1] = true;
    bool val = vec_bool[0];

    return 0;
}
