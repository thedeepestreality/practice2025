#include <iostream>

void func() {
	int x = 0;
	static int y = 0;
	++x;
	++y;
	if (y > 3) {
		std::cout << "Please pay\n";
		return;
	}

	std::cout << x << ' ' << y << '\n';
	
}

int main() {
	func();
	func();
	func();
	func();
	return 0;
}
