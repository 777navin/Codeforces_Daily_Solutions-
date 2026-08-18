/*
=========================================================
Date        : 18-08-2026
Problem Name: B. T-Shirt Hunt
Platform    : Codeforces
Difficulty  : 1300
Tags        : brute force, greedy, implementation, math

Problem Summary:
Determine the minimum number of successful hacks (+100 points each) needed to achieve 
a score >= y such that your rank p receives a Codecraft-17 T-shirt according to a 
pseudo-random generator function. Unsuccessful hacks (-50 points each) can also be used.

Key Observation:
Since each unsuccessful hack subtracts 50 points and each successful hack adds 100 points, 
any score reachable with 0 successful hacks has the form x - 50 * k >= y. Increasing scores 
by steps of 50 or 100 allows testing candidate scores incrementally starting from 0 hacks.
=========================================================
*/

/*
---------------------------------------------------------
APPROACH 1: Simulation / Exhaustive Search (Optimal)
---------------------------------------------------------
• Intuition:
  The number of successful hacks is non-negative and generally very small.
  We can first check if any reachable score >= y with 0 successful hacks awards a T-shirt.
  If not, we incrementally test adding successful hacks (each giving +100 or +50 net adjustments).

• Approach:
  1. Define a helper function `check(s, p)` simulating the 25-step pseudocode generator on score `s`.
  2. Check scores downwards from `x` by steps of 50 as long as `s >= y`. If valid, answer is 0.
  3. Otherwise, search upwards for `s = x + 50`, `x + 100`, `x + 150`, ...
  4. For each score `s > x`, calculate the minimum successful hacks needed: `((s - x + 50) / 100)`.
  5. The first valid score encountered gives the minimum successful hacks.

• Why it Works:
  The pseudocode is deterministic and periodic (mod 475), guaranteeing a match within at most 475 steps (~24,000 points).

• Time Complexity (TC): O(475 * 25) ≈ O(1) constant time operations.
• Space Complexity (SC): O(1) auxiliary memory.
---------------------------------------------------------
*/

/*
---------------------------------------------------------
FINAL APPROACH:
---------------------------------------------------------
We use the simulation approach iterating upwards/downwards in increments of 50.
It guarantees finding the absolute minimum number of successful hacks with minimal code complexity and O(1) runtime.
---------------------------------------------------------
*/

#include <iostream>

using namespace std;

// Simulates the T-shirt winner selection pseudocode for a given score 's'
bool check(int s, int p) {
    int i = (s / 50) % 475;
    for (int step = 0; step < 25; ++step) {
        i = (i * 96 + 42) % 475;
        if (26 + i == p) {
            return true;
        }
    }
    return false;
}

void solve() {
    int p, x, y;
    if (!(cin >> p >> x >> y)) return;

    // Check if 0 successful hacks can achieve the goal (only reducing score by 50)
    for (int s = x; s >= y; s -= 50) {
        if (check(s, p)) {
            cout << 0 << "\n";
            return;
        }
    }

    // Search upwards for the minimal successful hacks
    for (int s = x + 50; ; s += 50) {
        if (check(s, p)) {
            int hacks = (s - x + 50) / 100;
            cout << hacks << "\n";
            return;
        }
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
