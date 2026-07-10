/*
=========================================================
Date        : 10-07-2026
Problem Name: 1608A - Find Array
Platform    : Codeforces
Difficulty  : 800
Tags        : constructive algorithms, math

Problem Summary:
Generate a strictly increasing array of size 'n' where 
no element is divisible by its immediate predecessor. 
Elements must be bounded between 1 and 10^9.

Key Observation:
For any integer x > 1, (x + 1) is never divisible by x 
because the remainder of (x + 1) / x is always 1.
=========================================================

1. Most Optimal Approach
- Intuition: The simplest way to prevent divisibility between 
  adjacent elements is to use consecutive integers.
- Approach: Output the sequence starting from 2 up to n + 1. 
  For example: 2, 3, 4, ..., n+1.
- Why it Works: Because adjacent numbers x and x+1 share no divisors 
  other than 1, x+1 % x = 1 (for x > 1). They also strictly increase.
- Time Complexity (TC): O(n) per test case to print the numbers.
- Space Complexity (SC): O(1) as we print directly without storing.

=========================================================
Final Approach Selection:
This constructive approach is chosen because it perfectly aligns 
with the divisibility rule in the simplest mathematical way. It avoids 
the need to precompute primes or complex sequences, keeping it O(n).
=========================================================
*/

#include <iostream>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    // Print n consecutive numbers starting from 2
    for (int i = 2; i <= n + 1; ++i) {
        cout << i << " ";
    }
    cout << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    
    return 0;
}
