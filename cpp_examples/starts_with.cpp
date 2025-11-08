#include <iostream>

bool startsWith(char* src, char* str) {
	while (*str != 0) {
		if (*src == 0 || *src != *str)
			return false;
		++str;
		++src;
	}
	return true;
}

int main(int argc, char* argv[]) {
	if (argc == 3)
		std::cout << (startsWith(argv[1], argv[2]) ? "YES\n" : "NO\n");
	else
		std::cout << "Not enought arguments\n";
	return 0;
}
