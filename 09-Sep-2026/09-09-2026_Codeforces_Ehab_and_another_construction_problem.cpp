/*
=========================================================
Date        : 09-09-2026
Problem Name: 1088A - Ehab and another construction problem
Platform    : Codeforces
Difficulty  : 800
Tags        : constructive algorithms, brute force, math

Problem Summary:
Given an integer x, find two integers a and b such that:
1 <= a, b <= x, b divides a, a * b > x, and a / b < x.
If no such pair exists, print -1.

Key Observation:
For any x > 1, picking a = x and b = x satisfies:
x divides x, x * x > x, and x / x = 1 < x.
For x = 1, no integer in [1, 1] satisfies a * b > 1.
=========================================================
*/

#include <bits/stdc++.h>
using namespace std;

/*
---------------------------------------------------------
APPROACH 1: Brute Force Search
---------------------------------------------------------
• Intuition:
  Iterate through all possible values of a and b in the range [1, x]
  and check all four given conditions directly.

• Approach:
  - Run nested loops: a from 1 to x, and b from 1 to x.
  - If (a % b == 0) && (a * b > x) && (a / b < x), output (a, b) and exit.
  - If loops finish without finding a pair, output -1.

• Why it Works:
  The upper bound x <= 100 is very small, so checking all pairs is trivial.

• Time Complexity (TC) : O(x^2)
• Space Complexity (SC): O(1)

---------------------------------------------------------
APPROACH 2: Mathematical Construction (Most Optimal)
---------------------------------------------------------
• Intuition:
  Setting a = x and b = x gives a / b = 1, which is strictly less than x for all x > 1,
  and a * b = x^2, which is strictly greater than x for all x > 1.

• Approach:
  - If x == 1, no valid pair exists because only a = 1, b = 1 is possible, yielding a * b = 1 (not > 1). Return -1.
  - If x > 1, directly output "x x".

• Why it Works:
  - 1 <= x, x <= x holds.
  - x divides x.
  - x * x > x holds for all integers x >= 2.
  - x / x = 1 < x holds for all integers x >= 2.

• Time Complexity (TC) : O(1)
• Space Complexity (SC): O(1)
---------------------------------------------------------
*/

/*
=========================================================
FINAL APPROACH:
Chosen: Approach 2 (Mathematical Construction)
Why it is better:
- Solves the problem in O(1) time and space without loops.
- Minimal logic, zero overhead, and eliminates edge-case pitfalls.
=========================================================
*/

void solve() {
    int x;
    if (!(cin >> x)) return;

    if (x == 1) {
        cout << -1 << "\n";
    } else {
        cout << x << " " << x << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
