#include <cassert>
#include <iostream>

bool valid_braces(const char* s){
    int c=0;
    int i=0;
    while(c>=0&&s[i]!=0){
        c += s[i++] == '(' ? 1 : -1;
    }
    return c == 0;
}

int v(char*s){int c=0;for(;c>=0&&*s;)c+=81-*s++*2;return!c;}

int main(){
    //Positive cases
    assert(v(""));
    assert(v("()"));
    assert(v("()()"));
    assert(v("(())"));
    assert(v("(())()"));
    assert(v("()(())"));
    assert(v("((()))"));
    assert(v("((())())"));
    assert(v("(()(()))"));

    //Negative cases
    assert(!v("("));
    assert(!v(")"));
    assert(!v(")("));

    assert(!v("(()"));
    assert(!v("((("));
    assert(!v("()("));
    assert(!v("())"));
    assert(!v(")()"));
    assert(!v(")(("));
    assert(!v("))("));
    assert(!v(")))"));

    assert(!v("))(("));
    assert(!v(")((("));
    assert(!v("())("));
    assert(!v("()(("));

    std::cout << "All tests passed!\n";

    return 0;
}