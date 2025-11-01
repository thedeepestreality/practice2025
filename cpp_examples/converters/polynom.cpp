#include <iostream>

int main() {
	int coef[] = { 1, 2, 1 };
	int n = sizeof(coef) / sizeof(coef[0]);
	int x;
	std::cin >> x;
	int sum = 0;
	
	//// the worst solution
	//for (int idx = 0; idx < n; ++idx)
	//	sum += coef[idx] * std::pow(x, idx);

	//// good solution
	//int x_deg = 1;
	//for (int idx = 0; idx < n; ++idx) {
	//	sum += coef[idx] * x_deg;
	//	x_deg *= x;
	//}

	// best solution
	// sum = (...(coef[n-1] * x + coef[n-2]) * x + coef[n-3]) * x + ...) * x + coef[0];
	sum = coef[n - 1];
	for (int idx = n - 2; idx >= 0; --idx)
		sum = sum * x + coef[idx];

	std::cout << sum << '\n';
	return 0;
}