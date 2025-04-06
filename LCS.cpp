// Program to find the longest common subsequence of two strings using dynamic programming :-
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// Function to find the longest common subsequence (LCS)
std::string findLCS(const std::string& X, const std::string& Y) {
    int m = X.length();
    int k = Y.length();

    // Create a 2D vector to store lengths of longest common subsequence
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(k + 1, 0));

    // Fill dp array using the tabulation method
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= k; ++j) {
            if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Reconstruct the LCS from the dp table
    int i = m, j = k;
    std::string lcs;

    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs.push_back(X[i - 1]);
            --i;
            --j;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            --i;
        } else {
            --j;
        }
    }

    // Reverse the lcs string since we built it backwards
    std::reverse(lcs.begin(), lcs.end());
    
    return lcs;
}

int main() {
    std::string X = "ABCD";
    std::string Y = "ACDB";

    std::string lcs = findLCS(X, Y);

    std::cout << "Longest Common Subsequence: " << lcs << std::endl;

    return 0;
}






