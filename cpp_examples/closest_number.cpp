#include <iostream>

int main() {
	long long x;
	int n;
	long long y;
	long long y_closest = 0;
	long long min_diff = INT_MAX;
	std::cin >> x >> n;
	for (int idx = 1; idx <= n; ++idx) {
		std::cin >> y;
		if (std::abs(x - y) < min_diff) {
			min_diff = std::abs(x - y);
			y_closest = y;
		}
		else if (std::abs(x - y) == min_diff) {
			if (y < y_closest)
				y_closest = y;
		}
	}
	std::cout << y_closest << '\n';
	return 0;
}
