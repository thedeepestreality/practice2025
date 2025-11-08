#include <iostream>

int main(int argc, char* argv[]) {
	if (argc > 1) {
		int idx = 0;
		while (argv[1][idx] != 0) {
			char c = argv[1][idx];
			if (c >= 'a' && c <= 'z')
				std::cout << (char)(c - 'a' + 'A');
			else
				std::cout << c;
			++idx;
		}
	}
	else
		std::cout << "Not enough arguments\n";
	return 0;
}