/*
=========================================================
Date        : 18-11-2026
Problem Name: A. Again Twenty Five!
Platform    : Codeforces
Difficulty  : 800
Tags        : math, number theory

Problem Summary:
Given an integer n (2 <= n <= 2 * 10^18), find the last two digits of 5^n.
Print the resulting two digits without any spaces.

Key Observation:
For every integer n >= 2, 5^n always ends with the digits 25.
=========================================================
*/

/*
=========================================================
APPROACHES
=========================================================

1. Brute Force (Iterative Multiplication / Modular Exponentiation)
• Intuition:
  Compute 5^n modulo 100 using a loop or binary exponentiation.
• Approach:
  Multiply a result variable by 5 repeatedly n times (or use binary exponentiation), taking % 100 at each step.
• Why it Works:
  Taking modulo 100 at every step keeps only the last two digits and prevents integer overflow.
• Time Complexity (TC): O(n) for linear loop, O(log n) for binary exponentiation.
• Space Complexity (SC): O(1)

2. Most Optimal (Mathematical Pattern Observation)
• Intuition:
  Look at the first few powers of 5 for n >= 2: 5^2 = 25, 5^3 = 125, 5^4 = 625.
• Approach:
  Read the input n and directly output 25 without performing any calculations.
• Why it Works:
  Since 25 * 5 = 125 (which ends in 25), by induction, 5^n % 100 is always 25 for all n >= 2.
• Time Complexity (TC): O(1)
• Space Complexity (SC): O(1)

=========================================================
FINAL APPROACH
=========================================================
• The Most Optimal O(1) mathematical approach is chosen.
• While binary exponentiation works in O(log n), recognizing that 5^n % 100 is invariant for n >= 2 avoids unnecessary computation and handles n up to 2 * 10^18 instantly.
=========================================================
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    if (cin >> n) {
        // For all n >= 2, the last two digits of 5^n are always 25
        cout << 25 << "\n";
    }

    return 0;
}
