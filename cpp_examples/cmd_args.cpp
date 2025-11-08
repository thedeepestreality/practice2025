#include <iostream>

int main(int argc, char* argv[]) {
	for (int idx = 0; idx < argc; ++idx)
		std::cout << argv[idx] << '\n';
	if (argc == 3) {
		int a = atoi(argv[1]);
		int b = atoi(argv[2]);
		std::cout << a + b << '\n';
	}
	return 0;
}