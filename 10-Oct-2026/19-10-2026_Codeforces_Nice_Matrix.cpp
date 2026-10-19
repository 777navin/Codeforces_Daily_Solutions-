/*
=========================================================
Date        : 19-10-2026
Problem Name: [B. Nice Matrix](https://codeforces.com/problemset/problem/1422/B)
Platform    : Codeforces
Difficulty  : 1300
Tags        : implementation, math, greedy, matrices

Problem Summary:
- Given an n x m matrix, we want to make it "nice" where every row and column is a palindrome.
- We can increase or decrease any element by 1 in one operation.
- Find the minimum number of operations required to achieve this.

Key Observation:
- For a matrix to have symmetric rows and columns (palindromic rows and columns), each element at position (i, j) must be equal to its symmetrical counterparts: (i, m - 1 - j), (n - 1 - i, j), and (n - 1 - i, m - 1 - j).
- To minimize the sum of absolute differences between these four elements and a target value, the optimal target value is their median.
=========================================================
*/

/*
APPROACH 1: Greedy with Median (Optimized)

• Intuition: Each cell (i, j) belongs to a group of up to 4 symmetric cells in the matrix that must all be equal.
• Approach: Iterate through each cell in the matrix, identify its 4 symmetric counterparts, collect them into a group, sort the group, and find the median element.
• Why it Works: The median minimizes the sum of absolute deviations (L1 norm) for a set of numbers.
• Time Complexity (TC): O(n * m * log(4)), which simplifies to O(n * m) since sorting at most 4 elements takes constant time.
• Space Complexity (SC): O(n * m) to store the matrix.
*/

/*
FINAL APPROACH:
- We use the Greedy approach with the median because it guarantees the minimum operations to make any group of symmetric cells identical.
- It is optimal, runs well within the 1-second time limit for n, m <= 100, and avoids unnecessary complex search spaces.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<long long>> a(n, vector<long long>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    
    long long total_operations = 0;
    
    // Iterate over each cell and group it with its 3 symmetric counterparts
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            long long val1 = a[i][j];
            long long val2 = a[i][m - 1 - j];
            long long val3 = a[n - 1 - i][j];
            long long val4 = a[n - 1 - i][m - 1 - j];
            
            vector<long long> group = {val1, val2, val3, val4};
            sort(group.begin(), group.end());
            
            // The optimal value to minimize absolute differences is the median
            long long median = group[1];
            
            total_operations += abs(val1 - median) + abs(val2 - median) + abs(val3 - median) + abs(val4 - median);
        }
    }
    
    // Since each group of 4 symmetric elements is processed multiple times, 
    // dividing by 4 corrects the redundancy.
    cout << total_operations / 4 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
