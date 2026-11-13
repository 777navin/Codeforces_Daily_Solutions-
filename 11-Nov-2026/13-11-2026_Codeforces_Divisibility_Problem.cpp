/*
=========================================================
Date        : 13-11-2026
Problem Name: Divisibility Problem
Platform    : Codeforces ([Problem Link](https://codeforces.com/problemset))
Difficulty  : 800
Tags        : math, implementation

Problem Summary:
- Given two positive integers $a$ and $b$, find the minimum number of increments by 1 needed to make $a$ divisible by $b$.
- Answer this for $t$ independent test cases where $a, b \le 10^9$.

Key Observation:
- If $a$ is already divisible by $b$, the remainder $a \pmod b$ is 0, requiring 0 moves.
- Otherwise, the number of moves needed to reach the next multiple of $b$ is $b - (a \pmod b)$.
=========================================================
*/

/*
=========================================================
APPROACH EXPLANATION
=========================================================

1. Brute Force
   • Intuition: Increment $a$ one by one until it becomes divisible by $b$.
   • Approach: Use a loop to keep adding 1 to $a$ and check if $a \% b == 0$.
   • Why it Works: Simulates the problem statement directly.
   • Time Complexity (TC): O(b - (a % b)) per test case (Too slow for $10^9$).
   • Space Complexity (SC): O(1).

2. Optimized (Mathematical)
   • Intuition: Calculate the remainder directly using modulo arithmetic instead of looping.
   • Approach: Check if $a \pmod b == 0$. If yes, answer is 0. Otherwise, the answer is $b - (a \pmod b)$.
   • Why it Works: Bypasses redundant additions by finding the distance to the next multiple in O(1) time.
   • Time Complexity (TC): O(1) per testcase.
   • Space Complexity (SC): O(1).

=========================================================
FINAL APPROACH
=========================================================
• The optimized mathematical approach is chosen because $a$ and $b$ can be as large as $10^9$, making loop-based simulation extremely slow and prone to Time Limit Exceeded (TLE).
• Using modulo arithmetic allows us to solve each test case in O(1) constant time, easily fitting within the 1-second time limit for $10^4$ test cases.
*/

#include <iostream>

using namespace std;

void solve() {
    long long a, b;
    cin >> a >> b;
    
    // If a is already divisible by b, 0 moves are needed.
    // Otherwise, find the difference between b and the remainder of a divided by b.
    long long rem = a % b;
    if (rem == 0) {
        cout << 0 << "\n";
    } else {
        cout << b - rem << "\n";
    }
}

int main() {
    // Optimize standard I/O operations for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
