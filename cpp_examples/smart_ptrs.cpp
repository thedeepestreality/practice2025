#include <iostream>
#include <memory>

// RAII
// Resource Allocation is Initialization
// Simplest implementation of unqie_ptr
struct AutoPtr{
    int* m_ptr;
    AutoPtr(int* ptr) : m_ptr(ptr) {}
    ~AutoPtr() {
        delete m_ptr;
        m_ptr = nullptr;
    }

    AutoPtr(const AutoPtr& ptr) = delete;
    AutoPtr& operator=(const AutoPtr& ptr) = delete;

    AutoPtr& operator=(AutoPtr&& ptr) noexcept {
        if (&ptr != this){
            delete m_ptr;
            m_ptr = ptr.m_ptr;
            ptr.m_ptr = nullptr;
        }
        return *this;
    }

    AutoPtr(AutoPtr&& ptr) noexcept : m_ptr(ptr.m_ptr) {
        ptr.m_ptr = nullptr;
    }

};

struct Dummy {
    int m_x;
    double m_y;
    Dummy(int x, double y) : m_x(x), m_y(y) {}
};

// Problem 3: cross-dependence

struct B;

struct A {
    std::shared_ptr<B> m_ptr;
    int* dyn_mem;
    A() {
        m_ptr = std::make_shared<B>();
    }
};

struct B {
    std::shared_ptr<A> m_ptr;
    int* dyn_mem;
    B() {
        m_ptr = std::make_shared<A>();
    }
};


int main(){
    // Problem 0: forgot to call delete -> memory leak
    // int* ptr = new int;

    // // delete ptr;
    AutoPtr ptr(new int);
    AutoPtr ptr2(new int);

    // Problem 1: double free
    // ptr2 = ptr;

    ptr2 = std::move(ptr);

    // Problem 2: single owner
    std::unique_ptr<Dummy> u_ptr = std::make_unique<Dummy>(1, 3.14);

    std::shared_ptr<Dummy> s_ptr = std::move(u_ptr);
    std::shared_ptr<Dummy> s_ptr2 = s_ptr;
    s_ptr2 = s_ptr;

    std::shared_ptr<Dummy> s_ptr3 = std::make_shared<Dummy>(42, 2.718);

    A a;

    std::weak_ptr<Dummy> w_ptr = s_ptr;

    if (!w_ptr.expired()){
        auto ws_ptr = w_ptr.lock();
    }

    return 0;
}