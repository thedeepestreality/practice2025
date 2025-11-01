#include <iostream>

int main() {
	int arr[] = { 1, 2, 3 };
	std::cout << arr[1] << ' ' << *(arr + 1) << '\n';
	std::cout << 1[arr] << '\n';

	*(arr + 1) = 10;

	int num = 333;
	
	for (int i = -20; i < 20; ++i)
		std::cout << *(arr + i) << ' ';
	int* ptr = arr;
	*(ptr + 11) = 300;
	std::cout << '\n';
	
	//int* ptr = &num;
	//*ptr = 300;
	std::cout << num << '\n';

	return 0;
}