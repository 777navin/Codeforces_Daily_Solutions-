/*
=========================================================
Date        : 05-09-2026
Problem Name: Ilya and Bank Account
Platform    : Codeforces
Difficulty  : 900
Tags        : greedy, math, implementation

Problem Summary:
Ilya has a bank account balance represented by an integer n. 
He can choose to delete either the last digit or the digit 
before the last digit at most once, or make no changes.
Find the maximum possible balance Ilya can obtain.

Key Observation:
If n >= 0, leaving it unchanged is always optimal. If n < 0, 
the maximum value comes from comparing the original number, 
the number after dropping the last digit, and the number after 
dropping the second-to-last digit.
=========================================================
*/

/*
---------------------------------------------------------
APPROACH 1: Optimized Arithmetic Comparison
---------------------------------------------------------
• Intuition:
  - If n is non-negative, removing any digit reduces its magnitude and thus decreases its value.
  - If n is negative, reducing its absolute value makes it closer to zero (larger).
  - The only two choices are removing the last digit or removing the tens digit.

• Approach:
  - If n >= 0, the answer is n.
  - Option 1 (remove last digit): n / 10.
  - Option 2 (remove tens digit): (n / 100) * 10 + (n % 10).
  - Take the maximum among n, Option 1, and Option 2.

• Why it Works:
  - Integer division by 10 discards the last digit.
  - Dividing by 100, multiplying by 10, and adding the original last digit (n % 10) replaces the tens digit with the units digit.
  - Comparing the three options directly gives the mathematically largest state.

• Time Complexity (TC) : O(1)
• Space Complexity (SC): O(1)
---------------------------------------------------------
*/

/*
---------------------------------------------------------
FINAL APPROACH SELECTION:
We use the direct arithmetic method because it executes in O(1) 
time with O(1) memory, requires no string allocations or conversions, 
and directly computes the maximal value cleanly.
---------------------------------------------------------
*/

#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    long long n;
    if (!(cin >> n)) return;

    if (n >= 0) {
        cout << n << "\n";
        return;
    }

    // Option 1: Remove the last digit
    long long option1 = n / 10;

    // Option 2: Remove the digit before the last
    long long option2 = (n / 100) * 10 + (n % 10);

    // Output the maximum possible account balance
    cout << max({n, option1, option2}) << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
