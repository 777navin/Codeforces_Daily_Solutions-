/*
Date: 07-05-2026
Problem Name: Equal or Not Equal
Platform: Codeforces (Educational Round 119 - Div 2)
Difficulty: 800
Tags: geometry, graphs, greedy, implementation

Problem Summary:
We are given a circular array of 'n' integers. For each adjacent pair (including the last and 
first), we are told if they are equal ('E') or not equal ('N'). We need to determine if 
there exists any array of positive integers that satisfies these conditions.

Methods to Solve:
1. Optimal Approach (Count of 'N's)

--------------------------------------------------------------------------------
1. Optimal Approach:
- Intuition: 
  In a circular relationship, equality is transitive. If a == b and b == c, then a == c. 
  The only way to create a contradiction is if we are forced to conclude that two elements 
  are equal through a chain of 'E's, but the input specifies they are not equal ('N').
  On a circle, if there is exactly one 'N', it means a1 = a2 = ... = an, but an != a1. 
  This is a mathematical impossibility. If there are zero 'N's, all are equal (Valid). 
  If there are two or more 'N's, we can always pick values to satisfy the conditions.

- Approach:
  Check the count of 'N' characters in the string. If the count is exactly 1, 
  it is impossible to form the array (NO). Otherwise, it is always possible (YES).

- Dry Run (Small example):
  Input: "EN"
  Count of 'N' = 1. Output: NO. (Explanation: a1 = a2, but a2 != a1 -> Contradiction)
  Input: "ENNEENE"
  Count of 'N' = 2. Output: YES.

- Time Complexity: O(N) per test case to traverse the string.
- Space Complexity: O(1) excluding the input string storage.
- Why better than previous method: This is the most efficient logical deduction.
- When to use: Always for this circular constraint logic.

--------------------------------------------------------------------------------
Comparison Table:
Method           | TC   | SC   | Best Use Case
Optimal (Logic)  | O(N) | O(1) | All cases

Final Recommended Solution:
The "Count of N's" approach is optimal due to the mathematical properties of equality.
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/**
 * Fast I/O Setup
 */
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

/**
 * Problem Solver
 */
void solve() {
    string s;
    cin >> s;

    int n_count = 0;
    for (char c : s) {
        if (c == 'N') {
            n_count++;
        }
    }

    // In a circular array, you cannot have exactly one "Not Equal" 
    // because equality is transitive.
    if (n_count == 1) {
        cout << "NO" << "\n";
    } else {
        cout << "YES" << "\n";
    }
}

int main() {
    fast_io();
    
    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        solve();
    }
    
    return 0;
}
