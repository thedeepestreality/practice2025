#include <iostream>
#include <cmath>

// typedef unsigned long int ulint;
using ulint = unsigned long int;

//typedef double(*ud_fun)(double);
using ud_fun = double(*)(double);

double lin(double val) {
	return val;
}

// rectangular approximate numeric integration
double integrate_rect(
	ud_fun fun,
	double a,
	double b,
	double dx
) {
	double sum = 0.0;
	while (a < b) {
		double right_x = a + dx;
		if (right_x > b) {
			right_x = b;
			dx = right_x - a;
		}
		double area = fun(a) * dx;
		sum += area;
		a += dx;
	}
	return sum;
}

// trapezoid approximate numeric integration
double integrate_trap(
	ud_fun fun,
	double a,
	double b,
	double dx
) {
	double sum = 0.0;
	while (a < b) {
		double right_x = a + dx;
		if (right_x > b) {
			right_x = b;
			dx = right_x - a;
		}
		double area = 0.5 * (fun(a) + fun(a + dx)) * dx;
		sum += area;
		a += dx;
	}
	return sum;
}

int main() {
    double a = 0.0;
    double b = 3.0;
    double dx = 1e-1; // dx = 0.1
    double analytic_value = 0.5 * (b*b - a*a);
    double numeric_value = integrate_rect(lin, a, b, dx);

    std::cout << "f(x) = x rect integral: \n";
    std::cout << analytic_value << ' ' << numeric_value << '\n';

    numeric_value = integrate_trap(lin, a, b, dx);
    std::cout << "f(x) = x trap integral: \n";
    std::cout << analytic_value << ' ' << numeric_value << '\n';

    analytic_value = -cos(b) + cos(a);
    numeric_value = integrate_rect(sin, a, b, dx);

    std::cout << "f(x) = sin(x) integral: \n";
    std::cout << analytic_value << ' ' << numeric_value << '\n';

    numeric_value = integrate_trap(sin, a, b, dx);
    std::cout << "f(x) = sin(x) trap integral: \n";
    std::cout << analytic_value << ' ' << numeric_value << '\n';

    // ud_fun func_arr[] = { lin, sin, asin};
    double (*func_arr[])(double) = { lin, sin, asin};
    for (int idx=0; idx < 3; ++idx)
        std::cout << integrate_trap(func_arr[idx], a, b, dx) << '\n';

	return 0;
}
