/*
=========================================================
Date        : 11-11-2026
Problem Name: C1. k-LCM (easy version)
Platform    : Codeforces
Difficulty  : 1200
Tags        : Math, Constructive Algorithms

Problem Summary:
Find three positive integers whose sum equals n.
Their LCM must be less than or equal to n/2.

Key Observation:
The answer depends on n modulo 4.
We can construct valid numbers using three simple cases.
=========================================================

APPROACH 1: Mathematical Construction

- Intuition:
  We need three positive integers with a small LCM.

- Approach:
  Case 1: If n is odd:
          (1, n/2, n/2)

  Case 2: If n % 4 == 0:
          (n/2, n/4, n/4)

  Case 3: Otherwise:
          (2, n/2 - 1, n/2 - 1)

- Why it Works:
  All three numbers are positive and their sum is n.
  Their LCM is always at most n/2.

- Time Complexity (TC): O(1) per test case.
- Space Complexity (SC): O(1).

FINAL APPROACH:
The mathematical construction is optimal.
It handles all possible values of n in constant time,
without loops, extra memory, or LCM calculations.
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n, k;
    cin >> n >> k;

    if (n % 2 == 1) {
        cout << 1 << " " << n / 2 << " " << n / 2 << '\n';
    }
    else if (n % 4 == 0) {
        cout << n / 2 << " " << n / 4 << " " << n / 4 << '\n';
    }
    else {
        cout << 2 << " " << n / 2 - 1 << " " << n / 2 - 1 << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
