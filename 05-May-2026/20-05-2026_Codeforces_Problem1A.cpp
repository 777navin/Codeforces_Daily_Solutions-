/*
Date: 20-05-2026
Problem Name: Theatre Square (Problem 1A)
Platform: Codeforces
Difficulty: *1000
Tags: math, implementation

Problem Summary:
We are given dimensions n × m of a rectangular square and tile size a × a.
We must cover the entire square using minimum number of tiles.
Tiles cannot be broken, but they can extend beyond the boundary.

Methods to Solve:

1. Brute Force
   - Intuition: Place tiles row by row and column by column.
   - Approach: Simulate covering the area with tiles.
   - Dry Run: For n=6, m=6, a=4 → place 2 tiles along n, 2 tiles along m → total 4.
   - Time Complexity: O(n*m/a^2)
   - Space Complexity: O(1)
   - Why better: Simple but inefficient.
   - When to use: Only for understanding.

2. Mathematical Formula (Optimal)
   - Intuition: Use ceiling division for both dimensions.
   - Approach: tiles_n = ceil(n/a), tiles_m = ceil(m/a), result = tiles_n * tiles_m.
   - Dry Run: For n=6, m=6, a=4 → ceil(6/4)=2, ceil(6/4)=2 → total=4.
   - Time Complexity: O(1)
   - Space Complexity: O(1)
   - Why better: Direct calculation, fastest.
   - When to use: Always in contests.

Comparison Table:
Method              | TC        | SC   | Best Use Case
------------------------------------------------------
Brute Force         | O(n*m)    | O(1) | Learning basics
Mathematical Formula| O(1)      | O(1) | Contest solution

Final Recommended Solution:
Use the mathematical formula with ceiling division.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, m, a;
    cin >> n >> m >> a;

    // Ceiling division: (x + y - 1) / y
    long long tiles_n = (n + a - 1) / a;
    long long tiles_m = (m + a - 1) / a;

    cout << tiles_n * tiles_m << "\n";
    return 0;
}
