/*
=========================================================
Date        : 24-07-2026
Problem Name: Olesya and Rodion
Platform    : Codeforces
Difficulty  : 800
Tags        : Math, Implementation

Problem Summary:
Given two integers n and t, construct a positive integer 
consisting of exactly n digits (without leading zeros) that 
is divisible by t. If no such number exists, return -1.

Key Observation:
For t in range [2, 9], appending digit t repeated n times or 
t followed by (n-1) zeros creates a valid n-digit number divisible by t. 
For t = 10, it requires at least 2 digits (e.g., "100...0"). If n = 1 and t = 10, 
it is impossible to form a 1-digit number divisible by 10, so return -1.
=========================================================
*/

#include <iostream>
#include <string>

using namespace std;

/*
---------------------------------------------------------
APPROACH 1: Direct Construction (Optimal)
---------------------------------------------------------
• Intuition:
  - If t = 10 and n = 1, we cannot form a single-digit number divisible by 10 without leading zeros, so output -1.
  - If t = 10 and n > 1, we can form the number as '1' followed by (n - 1) '0's (e.g., 10, 100, 1000...).
  - If t < 10, we can simply print digit t followed by (n - 1) '0's (e.g., for t = 7 and n = 3, 700 is divisible by 7).

• Approach:
  - Check edge case n = 1 and t = 10.
  - If t == 10, print '1' and (n - 1) zeros.
  - Otherwise, print t and (n - 1) zeros.

• Why it Works:
  - Any number formed by k * 10^(n-1) is divisible by k. For k = t < 10, t * 10^(n-1) is always divisible by t.
  - For t = 10, 1 * 10^(n-1) is always divisible by 10 when n >= 2.

• Time Complexity (TC): O(n) - printing n characters.
• Space Complexity (SC): O(1) - auxiliary space.
---------------------------------------------------------
*/

/*
---------------------------------------------------------
FINAL APPROACH CHOICE
---------------------------------------------------------
• Chosen Approach: Direct String Construction.
• Why Chosen: It solves the problem in linear time with respect to digits O(n) without handling huge integer overflows, as n can be up to 100.
---------------------------------------------------------
*/

void solve() {
    int n, t;
    if (!(cin >> n >> t)) return;

    if (n == 1 && t == 10) {
        cout << -1 << "\n";
        return;
    }

    if (t == 10) {
        cout << 1;
        for (int i = 0; i < n - 1; ++i) {
            cout << 0;
        }
    } else {
        cout << t;
        for (int i = 0; i < n - 1; ++i) {
            cout << 0;
        }
    }
    cout << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
