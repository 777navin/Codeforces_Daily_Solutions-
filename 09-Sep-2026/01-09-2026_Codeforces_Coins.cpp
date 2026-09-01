/*
=========================================================
Date        : 01-09-2026
Problem Name: A. Coins
Platform    : Codeforces (Problem 1061A)
Difficulty  : 800
Tags        : greedy, math

Problem Summary:
Given an infinite supply of coins of values from 1 to n, find the 
minimum number of coins required to form a total sum of S.

Key Observation:
To minimize the count of coins, greedily use the largest coin value n
as much as possible, and if there is a remainder, use one smaller coin.
=========================================================
*/

/*
---------------------------------------------------------
APPROACH 1: Greedy Division / Math (Most Optimal)
---------------------------------------------------------
• Intuition:
  Using the largest available coin value (n) reduces the total sum S 
  at the fastest possible rate.

• Approach:
  Compute the ceiling of S / n, which is equivalent to integer 
  arithmetic (S + n - 1) / n.

• Why it Works:
  Taking floor(S / n) coins of value n leaves a remainder r (0 <= r < n).
  If r == 0, no extra coins are needed; if r > 0, exactly one coin of value r 
  (which is <= n) suffices.

• Time Complexity (TC):
  O(1)

• Space Complexity (SC):
  O(1)
---------------------------------------------------------
*/

/*
---------------------------------------------------------
FINAL APPROACH SELECTION:
This mathematical approach runs in O(1) time and O(1) space, directly 
calculating the answer via integer ceiling division without any loops or 
recursion. It handles inputs up to S = 10^9 instantaneously.
---------------------------------------------------------
*/

#include <iostream>

using namespace std;

void solve() {
    long long n, S;
    if (!(cin >> n >> S)) return;
    
    // Ceiling division of S by n: (S + n - 1) / n
    long long ans = (S + n - 1) / n;
    
    cout << ans << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    
    return 0;
}
