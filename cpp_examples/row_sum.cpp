#include <iostream>
#include <cmath>

// Compute harmonic row sum
// n up to (2^32)-1
// and quadratic row
int main()
{
	int n;
	std::cout << "Input n: ";
	std::cin >> n;

	double sum_harm = 0.0;
	double sum_quad = 0.0;
	for (int den = 1.0; den <= n; ++den) {
		const double val = 1.0 / den;
		sum_harm += val;
		sum_quad += val * val;
		// sum_quat += 1.0 / (den * den); // integer overflow
	}

	std::cout << "Harmonic row sum = " << sum_harm << '\n';
	std::cout << "Quadratic row sum = " << sum_quad << '\n';

	double x0 = -0.5;
	double x1 = 0.5;
	double dx = 0.1;
	std::cout << "x\t|\tln(1+x)\t|row_sum\n";
	clock_t start = clock();
	for (; x0 <= x1; x0 += dx){
		double row_sum = 0.0;
		double x_deg = -1.0;
		for (int den = 1; den <= n; ++den){
			x_deg *= -x0;
			row_sum += x_deg / den;
		}
		//std::cout << x0 << "\t|\t" << log(1 + x0);
		//std::cout << "\t|\t" << row_sum << '\n';
	}
	clock_t fin = clock();
	std::cout << "elapsed: " << (double)(fin - start) / CLOCKS_PER_SEC << '\n';

	x0 = -0.5;
	start = clock();
	for (; x0 <= x1; x0 += dx) {
		double row_sum = 0.0;
		double x_deg = -1.0;
		for (int den = 1; den <= n; ++den) {
			row_sum += std::pow(x0, den) / den;
		}
	}
	fin = clock();
	std::cout << "elapsed: " << (double)(fin - start) / CLOCKS_PER_SEC << '\n';

	return 0;
}
