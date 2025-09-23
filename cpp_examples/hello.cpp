#include <iostream>
// single-line comment
// using namespace std;

/*
Multi
Line
Comment
*/

int main(){
  //std::cout << "Hello world!" << std::endl;

  std::cout << "Hello world!\n";
  std::cout << 'H' << 'e' << 'l' << 'l' << 'o' << '\n';

  std::cout << "Input integer: ";
  int x;
  std::cin >> x;
  std::cout << "Your input: " << x << '\n';
  int y = 10;
  int sum = x + y;
  std::cout << "Sum = " << sum << " or " << x+y << '\n';
  return 0;
}
