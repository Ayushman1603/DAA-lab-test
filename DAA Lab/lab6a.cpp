#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// Function to find Longest Common Subsequence
vector<string> LCS(vector<string>& student_1, vector<string>& student_2) {
    int m = student_1.size();
    int n = student_2.size();

    // DP table to store lengths of longest common subsequence
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Fill the DP table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (student_1[i - 1] == student_2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Backtrack to find the LCS
    int lcsLength = dp[m][n];
    vector<string> lcs(lcsLength);
    int i = m, j = n;
    int index = lcsLength - 1;

    while (i > 0 && j > 0) {
        if (student_1[i - 1] == student_2[j - 1]) {
            lcs[index--] = student_1[i - 1];
            i--;
            j--;
        } else if (dp[i - 1][j] >= dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    return lcs;
}

int main() {
    vector<vector<string>> grades = {
        {"AA", "BB", "CC", "DD", "EE", "FF", "AA", "BB", "CC", "DD"},
        {"AB", "BB", "CC", "DD", "EE", "FF", "AA", "BB", "CC", "EE"},
        {"AA", "AC", "CC", "DE", "FF", "BB", "AA", "BB", "CC", "EE"},
        {"AC", "BB", "CC", "DD", "EE", "FF", "AB", "BC", "CC", "DD"},
        {"AA", "BB", "CC", "DD", "EE", "FF", "BB", "BC", "CD", "EF"},
        {"AB", "BB", "CC", "DE", "FF", "AA", "BB", "CC", "DD", "EE"},
        {"AB", "BC", "CC", "DE", "FF", "AA", "BB", "CC", "DD", "EE"},
        {"AC", "BB", "CC", "DD", "FF", "BB", "AA", "CC", "DD", "EE"},
        {"AA", "BB", "CC", "DE", "FF", "AA", "BB", "CC", "DD", "EE"},
        {"AB", "BB", "CC", "DD", "EE", "FF", "AB", "BB", "CC", "DD"},
        {"AB", "BC", "CC", "DD", "FF", "AA", "BB", "CC", "DD", "EE"},
        {"AC", "BB", "CC", "DD", "EE", "FF", "AA", "BB", "CC", "DE"},
        {"AA", "BB", "CC", "DD", "EE", "FF", "AB", "BB", "CC", "DD"},
        {"AB", "BB", "CC", "DD", "EE", "FF", "AC", "BB", "CC", "DD"},
        {"AA", "BB", "CC", "DD", "EE", "FF", "AB", "BB", "CC", "DE"},
        {"AC", "BB", "CC", "DE", "FF", "AA", "BB", "CC", "DD", "EE"},
        {"AA", "AB", "BC", "CC", "DD", "EE", "FF", "AA", "BB", "CC"},
        {"AB", "BB", "CC", "DD", "EE", "FF", "AA", "BB", "CC", "DE"},
        {"AA", "BB", "CC", "DD", "FF", "BB", "CC", "DE", "FF", "AA"}
    };

    // Start with the first two students
    vector<string> student_1 = grades[0];
    vector<string> student_2 = grades[1];

    // Find the LCS between the first two students
    student_1 = LCS(student_1, student_2);

    // Now compare the LCS with the remaining students
    for (int i = 2; i < grades.size(); i++) {
        student_2 = grades[i];
        student_1 = LCS(student_1, student_2);
    }

    // Print the final LCS
    cout << "Longest Common Subsequence: ";
    for (const string& grade : student_1) {
        cout << grade << " ";
    }
    cout << endl;

    return 0;
}
