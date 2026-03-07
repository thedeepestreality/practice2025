// 4 < x < 6
// (4 < x) < 6 -> (4 < x) && (x < 6)
// x = 5
// true < 6
// 1 < 6 -> true
// x = 1
// false < 6
// 0 < 6 -> true
// 4 < MagicCompare<int>(x) < 6

#include <iostream>

class MagicCompareInt{
private:
    int rval;
    bool result;
public:
    MagicCompareInt(int val, bool res=true) : rval(val), result(res)
    {
        std::cout << "Constructor: " << val << '\n';
    }
    operator bool() const{
        return result;
    }
    operator int() const{
        return rval;
    }
};

MagicCompareInt operator<(const MagicCompareInt& lval, int rval){
    bool result = lval && ((int)lval < rval);
    return MagicCompareInt(rval, result);
}

MagicCompareInt operator<(int lval, const MagicCompareInt& rval){
    int rval_val = rval;
    return MagicCompareInt(rval_val, lval < rval_val);
}

MagicCompareInt operator<(const MagicCompareInt& lval, const MagicCompareInt& rval){
    int rval_val = rval;
    bool result = lval && ((int)lval < (int)rval);
    return MagicCompareInt(rval_val, result);
}

int main(){
    std::cout << static_cast<bool>(MagicCompareInt(4) < 1 < 6) << '\n';
    MagicCompareInt x = 7;
    std::cout << static_cast<bool>(6 < x) << '\n';
    MagicCompareInt y = 6;
    std::cout << static_cast<bool>(x < y) << '\n';
    return 0;
}