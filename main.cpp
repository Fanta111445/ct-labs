#include <cmath>
#include <iomanip>
#include <iostream>

int main() {
    double a, b;
    int n;

    std::cout << "Enter A: ";
    std::cin >> a;
    std::cout << "Enter B: ";
    std::cin >> b;
    std::cout << "Enter N: ";
    std::cin >> n;

    if (!std::cin || n <= 0) {
        std::cerr << "Enter numbers for A and B and a positive integer N.\n";
        return 1;
    }
    if (a >= b) {
        std::cerr << "A must be less than B.\n";
        return 1;
    }

    const double h = (b - a) / n;
    const char* border = "+------------+----------------+----------------+----------------+\n";
    std::cout << "\nh = " << std::setprecision(10) << h << "\n\n"
              << border
              << "|          i |           x[i] |           F(x) |           G(x) |\n"
              << border << std::fixed << std::setprecision(6);

    for (long long i = 0; i <= n; ++i) {
        const double x = a + i * h;
        const double f = 2 - std::cos(x);
        const double g = std::exp(-x * x);
        std::cout << "| " << std::setw(10) << i
                  << " | " << std::setw(14) << x
                  << " | " << std::setw(14) << f
                  << " | " << std::setw(14) << g << " |\n";
    }

    std::cout << border;
    return 0;
}
