/*
=========================================================
Date        : 23-10-2026
Problem Name: What is for dinner?
Platform    : Codeforces (33A)
Difficulty  : 1200
Tags        : Greedy, Implementation

Problem Summary:
- There are n teeth divided into m rows.
- Each tooth has a residual viability value.
- Eating one fish decreases every tooth's viability
  in the selected row by one.
- Find the maximum fish Valerie can eat without
  making any tooth's viability negative, limited by k.

Key Observation:
- A row can be used at most the minimum viability
  among all teeth belonging to that row.
- Sum these row limits and cap the result at k.
=========================================================

Approach 1: Brute Force
- Intuition: Simulate eating fish one at a time.
- Approach: Repeatedly select a row that can be used.
- Why it Works: Each operation respects tooth viability.
- TC: Potentially O(k * n).
- SC: O(n).

Approach 2: Optimized Greedy
- Intuition: Each row has an independent maximum capacity.
- Approach:
  1. Store the minimum viability for each row.
  2. Sum the minimum viability across all rows.
  3. The answer is min(k, total capacity).
- Why it Works: Every fish consumes one unit of capacity
  from exactly one row, and rows do not interfere.
- TC: O(n + m).
- SC: O(m).

Final Approach:
- The optimized greedy approach is chosen because it
  processes every tooth once and computes each row's
  maximum capacity directly.
- It avoids simulation and handles large k efficiently.
=========================================================
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    long long k;
    cin >> n >> m >> k;

    vector<long long> minViability(m + 1, LLONG_MAX);

    for (int i = 0; i < n; ++i) {
        int row;
        long long viability;
        cin >> row >> viability;

        minViability[row] = min(minViability[row], viability);
    }

    long long totalCapacity = 0;

    for (int row = 1; row <= m; ++row) {
        totalCapacity += minViability[row];
    }

    cout << min(k, totalCapacity) << '\n';

    return 0;
}
