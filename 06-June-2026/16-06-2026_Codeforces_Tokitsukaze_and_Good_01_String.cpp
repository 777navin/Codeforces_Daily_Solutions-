/*
Date: 16-06-2026
Problem Name: 16-06-2026_Tokitsukaze_and_Good_01_String.cpp
Platform: Codeforces
Difficulty: 800
Tags: Greedy, Strings, Implementation

Problem Summary:
We are given a binary string of even length. We need to divide it into contiguous 
subsegments of even length consisting of identical characters by changing the 
minimum number of characters.

Methods to Solve:
1. Greedy Approach
   - Intuition: To make the string "good", every adjacent pair (s[i], s[i+1]) for 
     even 'i' must have the same character. If they don't, we increment our operations.
   - Approach: Iterate through the string with a step of 2. Compare s[i] and s[i+1].
     If they are different, it implies we must change one to match the other.
   - Time Complexity: O(n)
   - Space Complexity: O(1)

Comparison Table:
Method | TC   | SC   | Best Use Case
-------|------|------|--------------
Greedy | O(n) | O(1) | Optimal for minimum operations

Final Recommended Solution: The O(n) greedy approach.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Function to solve a single test case.
 */
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int operations = 0;
    
    // We iterate through the string in pairs (0,1), (2,3), etc.
    // If s[i] != s[i+1], we must perform 1 operation to make them match.
    for (int i = 0; i < n; i += 2) {
        if (s[i] != s[i + 1]) {
            operations++;
        }
    }

    cout << operations << endl;
}

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}
