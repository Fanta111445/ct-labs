#include <cctype>
#include <cmath>
#include <iomanip>
#include <iostream>

int main() {
    double a, b;
    int n;

    std::cout << "Enter A: ";
    if (!(std::cin >> a)) {
        std::cerr << "A must be a number.\n";
        return 1;
    }

    std::cout << "Enter B: ";
    if (!(std::cin >> b) || a >= b || !std::isfinite(b - a)) {
        std::cerr << "Enter finite bounds with A < B.\n";
        return 1;
    }

    std::cout << "Enter N: ";
    if (!(std::cin >> n) || n <= 0) {
        std::cerr << "N must be a positive integer.\n";
        return 1;
    }

    // Reject a fractional part or other characters attached to N.
    const int next = std::cin.peek();
    if (next != std::char_traits<char>::eof() && !std::isspace(next)) {
        std::cerr << "N must be a positive integer.\n";
        return 1;
    }

    const double h = (b - a) / n;
    const char* border = "+------------+----------------+----------------+----------------+\n";
    std::cout << "\nh = " << std::setprecision(10) << h << "\n\n"
              << border
              << "|          i |           x[i] |           F(x) |           G(x) |\n"
              << border << std::fixed << std::setprecision(6);

    for (long long i = 0; i <= n; ++i) {
        const double x = (i == n) ? b : a + i * h;
        const double f = 2.0 - std::cos(x);
        const double g = std::exp(-(x * x));

        std::cout << "| " << std::setw(10) << i
                  << " | " << std::setw(14) << x
                  << " | " << std::setw(14) << f
                  << " | " << std::setw(14) << g << " |\n";
    }

    std::cout << border;
    return 0;
}
