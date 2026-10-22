/*
=========================================================
Date        : 22-10-2026
Problem Name: Ball Game
Platform    : Codeforces
Difficulty  : 800
Tags        : implementation, math

Problem Summary:
n kids stand in a circle numbered 1 to n clockwise. 
Starting from child 1, the ball is thrown with increasing distances: 
the 1st throw goes 1 step away, the 2nd throw goes 2 steps away, and so on.
We need to output the numbers of the children who receive the ball after each of the n-1 throws.

Key Observation:
Each subsequent throw increments the step distance by 1, wrapping around the circle using modulo arithmetic.
=========================================================
*/

/*
3. APPROACH EXPLANATION

1. Simulation Approach
   • Intuition: Simulate the game step-by-step by keeping track of the current position in the circle.
   • Approach: Maintain the current child index (0-indexed or 1-indexed) and add the throw distance (from 1 to n-1) at each step, taking modulo n.
   • Why it Works: Directly mirrors the problem statement rules and constraints are small (n <= 100).
   • Time Complexity (TC): O(n)
   • Space Complexity (SC): O(1)
*/

/*
4. FINAL APPROACH
The simulation approach is chosen because n is very small (n <= 100), 
making O(n) time and O(1) space optimal and straightforward to implement without errors.
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;

    int current = 1; // Child 1 starts with the ball
    for (int i = 1; i <= n - 1; ++i) {
        // The i-th throw moves i steps clockwise
        current = (current + i - 1) % n + 1;
        cout << current << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    // Optimize standard I/O operations for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t; // Single test case for this problem
    while (t--) {
        solve();
    }

    return 0;
}
