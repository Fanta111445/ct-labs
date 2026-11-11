#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

int main() {
    const double pi = std::acos(-1.0);
    double a = -pi;
    double b = pi;
    int n = 10;

    std::cout << "Lab 2, variant 12\n"
              << "Enter A B N, or press Enter for -pi, pi, 10: ";

    std::string line;
    if (!std::getline(std::cin, line)) {
        return 1;
    }

    if (line.find_first_not_of(" \t\r") != std::string::npos) {
        std::istringstream input(line);
        char extra;
        if (!(input >> a >> b >> n) || input >> extra
            || a > b || n <= 0 || !std::isfinite(b - a)) {
            std::cerr << "Invalid input. Enter A <= B and a positive integer N.\n";
            return 1;
        }
    }

    const double h = (b - a) / n;
    const char* border = "+------------+----------------+----------------+----------------+\n";

    std::cout << "\nh = " << std::setprecision(10) << h << "\n\n"
              << border
              << "|          i |           x[i] |           F(x) |           G(x) |\n"
              << border << std::fixed << std::setprecision(6);

    // У N интервалов N + 1 точка, включая начало и конец отрезка.
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
