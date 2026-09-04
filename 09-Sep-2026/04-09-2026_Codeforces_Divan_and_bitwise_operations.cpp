/*
=========================================================
Date        : 04-09-2026
Problem Name: C. Divan and bitwise operations
Platform    : Codeforces
Difficulty  : 1500
Tags        : bitmasks, combinatorics, math

Problem Summary:
Given n elements and m segment bitwise OR queries that cover 
the entire sequence at least once, find the sum of bitwise XOR 
of all non-empty subsequences modulo 10^9 + 7.

Key Observation:
Each bit contributes independently. If a bit is set at least once 
in the array, exactly 2^(n-1) subsequences will have an odd number 
of elements with that bit set, making the total sum (bitwise OR of all elements) * 2^(n-1).
=========================================================
*/

/*
---------------------------------------------------------
APPROACH 1: Bitwise Independence & Contribution (Optimal)
---------------------------------------------------------
• Intuition:
  - The bitwise OR of all elements in the entire array is simply the 
    bitwise OR of all given segment OR values since every element is covered.
  - For any bit k that is present (value 1) in at least one element, exactly 
    half of all 2^n subsequences (i.e., 2^(n - 1)) will have an odd count of 
    elements with bit k set.

• Approach:
  - Compute total_or by taking the bitwise OR of all m segment inputs x_i.
  - Compute 2^(n - 1) % (10^9 + 7).
  - The answer is (total_or % MOD) * 2^(n - 1) % MOD.

• Why it Works:
  - If c elements have bit k set (c >= 1), the number of ways to choose an odd 
    number of elements with bit k set is sum_{odd j} C(c, j) = 2^(c - 1).
  - The remaining (n - c) elements can be chosen arbitrarily in 2^(n - c) ways.
  - Total ways bit k appears in XOR = 2^(c - 1) * 2^(n - c) = 2^(n - 1).

• Time Complexity (TC):
  - O(m + log n) per testcase.
  - Total TC: O(sum(m) + sum(log n)) which is well within 2 * 10^5 operations.

• Space Complexity (SC):
  - O(1) auxiliary space beyond input reading.
---------------------------------------------------------
FINAL APPROACH:
This approach is chosen because reconstructing individual elements is unnecessary.
Bitwise independence allows direct mathematical calculation via total bitwise OR 
in O(m) time and O(1) extra space, which is optimal.
---------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

static const long long MOD = 1e9 + 7;

long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

void solve() {
    int n, m;
    cin >> n >> m;

    long long total_or = 0;
    for (int i = 0; i < m; ++i) {
        int l, r;
        long long x;
        cin >> l >> r >> x;
        total_or |= x;
    }

    long long ways = power(2, n - 1);
    long long ans = ((total_or % MOD) * ways) % MOD;

    cout << ans << "\n";
}

int main() {
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
