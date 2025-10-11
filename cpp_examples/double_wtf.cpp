#include <iostream>

int main() {
	//long long x = 123456789101112345;
	//std::cout << "init x = " << x << '\n';
	//double y = x;
	//x = y;
	//std::cout << "cast x = " << x << '\n';
	double x1 = 0.0;
	double x2 = 1.0;
	double dx = 0.1;
	std::cout.precision(64);
	while (x1 <= x2) {
		std::cout << x1 << '\n';
		x1 += dx;

		if (x1 == 0.2)
			std::cout << "warning: almost critical\n";
		if (x1 == 0.3)
			std::cout << "error: critical!\n";
	}
	return 0;
}
