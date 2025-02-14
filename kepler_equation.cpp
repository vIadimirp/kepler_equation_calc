// December 19, 2024
// This program calculates E from Kepler's equation: M = E - esinE
// I also used binary search because it's cool

#include <iostream>
#include <cmath>
#include <iomanip>


int main() {
    double M;  // = 1;
    double e;  // = 0.6;
    std::cout << "Mean annomaly (M) = "; std::cin >> M;
    std::cout << "Eccentricity (e, 0 < e < 1) = "; std::cin >> e;

    if (e > 1 || e < 0) {
        std::cout << "Eccentricity must be in range [0; 1]";
        return 1;
    }
    
    double start = M - 2;
    double end = M + 2;
    unsigned short precision = 16;  // Floating point length

    // This is my simple binary search algorithm
    // It's slightly modified because I dont fucking know how to normally integrate it
    double E;
    do {
        E = (start + end) / 2;

        if (E - e * std::sin(E) - M > 0) end = E;
        else start = E;
    } while (std::abs(E - e * std::sin(E) - M) > std::pow(10, -precision));

    std::cout << "Eccentric anomaly (E) = " << std::setprecision(precision) << E << std::endl;

    return 0;
}
