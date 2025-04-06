// most effective way to find factors of an integer:-
#include <iostream>
#include <vector>
#include <cmath>

std::vector<int> findFactors(int n) {
    std::vector<int> factors;

    // Iterate from 1 to the square root of n
    for (int i = 1; i <= std::sqrt(n); ++i) {
        if (n % i == 0) { // If i is a factor
            factors.push_back(i); // Add i to the list of factors

            if (i != n / i) { // Check if i and n/i are different
                factors.push_back(n / i); // Add n/i to the list of factors
            }
        }
    }

    return factors;
}

int main() {
    int n = 28; // Example input
    std::vector<int> factors = findFactors(n);

    std::cout << "Factors of " << n << " are: ";
    for (int factor : factors) {
        std::cout << factor << " ";
    }
    std::cout << std::endl;

    return 0;
}
// Time Complexity: O(sqrt(n))  

