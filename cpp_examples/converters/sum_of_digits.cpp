#include <iostream>

int main(){
	int num;
	std::cin >> num;
	int num_copy = num;
	int sum = 0;
	int deg10 = 1;
	// sum of digits + max 10 degree
	while (num != 0) {
		sum += num % 10;
		num /= 10;
		deg10 *= 10;
	}
	deg10 /= 10;
	std::cout << sum << '\n';

	// output digits
	num = num_copy;
	while (deg10 != 0) {
		int digit = num / deg10;
		std::cout << digit << ", ";
		num %= deg10;
		deg10 /= 10;
	}
	std::cout << '\n';
	
	return 0;
}