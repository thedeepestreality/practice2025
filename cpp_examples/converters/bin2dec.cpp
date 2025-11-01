#include <iostream>
#include <cstring>

int main() {
	char bin_str[65] = {};
	std::cin >> bin_str;
	int n = strlen(bin_str);
	unsigned long long res = bin_str[0] - '0';
	for (int idx = 1; idx < n; ++idx)
		res = res * 2 + (bin_str[idx] - '0');

	std::cout << res << '\n';
	return 0;
}