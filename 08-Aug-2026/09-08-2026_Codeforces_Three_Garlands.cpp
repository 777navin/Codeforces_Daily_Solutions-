/*
=========================================================
Date        : 09-08-2026
Problem Name: 911C - Three Garlands
Platform    : Codeforces
Difficulty  : 1400
Tags        : math, constructive algorithms

Problem Summary:
Given three time intervals (k1, k2, k3) for three garlands,
determine if there exist start times such that every
second has at least one lit garland.

Key Observation:
We need to cover the infinite set of positive integers using 
exactly 3 arithmetic progressions.
=========================================================

1. Mathematical Deduction (Optimal)
- Intuition:
  To cover all numbers, the sum of the densities of the periods (1/k1 + 1/k2 + 1/k3) must be >= 1. We can deduce the only possible valid configurations by analyzing exact covers.
- Approach:
  Sort the three intervals in ascending order. The only valid configurations are:
  1. {1, X, Y} -> A period of 1 covers all integers.
  2. {2, 2, X} -> Two periods of 2 can cover all evens and odds.
  3. {3, 3, 3} -> Three periods of 3 can cover x % 3 == 0, 1, and 2.
  4. {2, 4, 4} -> One 2 covers half the integers, and two 4s cover the two remaining quarters perfectly.
- Why it Works:
  Any other combination either has a total density < 1 (impossible to cover all) or overlaps in such a way that gaps inevitably remain.
- Time Complexity (TC): O(1)
- Space Complexity (SC): O(1)

=========================================================
FINAL APPROACH
=========================================================
- Why this approach is chosen:
  It is a direct mathematical evaluation of the only possible combinations that can perfectly tile the integers with 3 periodic sequences.
- Why it is better than the previous ones:
  There is no brute force possible since time extends to infinity. This O(1) logic is the only feasible and most optimal solution.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    vector<int> k(3);
    cin >> k[0] >> k[1] >> k[2];
    
    // Sort to easily match our known valid tuples
    sort(k.begin(), k.end());
    
    // Check valid exact covering configurations
    if (k[0] == 1) {
        cout << "YES\n";
    } else if (k[0] == 2 && k[1] == 2) {
        cout << "YES\n";
    } else if (k[0] == 3 && k[1] == 3 && k[2] == 3) {
        cout << "YES\n";
    } else if (k[0] == 2 && k[1] == 4 && k[2] == 4) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // The problem doesn't specify multiple test cases, just one line of input.
    solve();
    
    return 0;
}
