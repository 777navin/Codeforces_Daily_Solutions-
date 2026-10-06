/*
=========================================================
Date        : 06-10-2026
Problem Name: E1. Unforgivable Curse (easy version)
Platform    : Codeforces
Difficulty  : 1400
Tags        : constructive algorithms, dsu, graphs, greedy, sortings

Problem Summary:
Given two strings s and t of length n, determine if s can be transformed into t
by swapping characters at indices i and j such that |i - j| = 3 or |i - j| = 4.
In this easy version, k is fixed at 3.

Key Observation:
A character at index i can reach any other position in the string unless it is
trapped, i.e., index i is so central that i - 3 < 0 and i + 3 >= n. For trapped
indices, s[i] must already equal t[i], while all non-trapped indices can be freely rearranged.
=========================================================
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
=========================================================
3. APPROACH EXPLANATION
=========================================================

---------------------------------------------------------
Approach 1: Character Position Range Verification (Optimal)
---------------------------------------------------------
• Intuition:
  Swapping at distances 3 and 4 allows any character at index i to move freely 
  to any other reachable position, provided i - 3 >= 0 or i + 3 < n. If neither 
  condition holds, the character at index i cannot move at all.

• Approach:
  1. Check if s and t are anagrams (same multiset of characters). If not, return "NO".
  2. Iterate through each index i from 0 to n - 1.
  3. If i - 3 < 0 and i + 3 >= n (index i cannot make a move left or right),
     then s[i] must strictly match t[i]. If s[i] != t[i], return "NO".
  4. If all such constrained positions match and overall character counts match, return "YES".

• Why it Works:
  The swap distances (k=3 and k+1=4) form connected components across all indices 
  that have at least one valid left or right swap move. All such indices fall into a 
  single connected component, making them fully permutable among themselves.

• Time Complexity (TC): O(n) per test case, to count frequencies and verify indices.
• Space Complexity (SC): O(1) auxiliary space (using fixed-size frequency array of size 26).
*/

/*
=========================================================
4. FINAL APPROACH
=========================================================
• Why this approach is chosen:
  It operates in linear time O(n) and O(1) space per test case by directly utilizing
  the connectivity property of indices under the swap constraints.
• Why it is better than the previous ones:
  Avoids unnecessary graph building/DSU operations while maintaining optimal bounds.
*/

// Fast I/O
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve() {
    int n, k;
    cin >> n >> k; // k is always 3 in E1
    
    string s, t;
    cin >> s >> t;

    // Step 1: Check if s and t have the same multiset of characters
    string sorted_s = s;
    string sorted_t = t;
    sort(sorted_s.begin(), sorted_s.end());
    sort(sorted_t.begin(), sorted_t.end());

    if (sorted_s != sorted_t) {
        cout << "NO\n";
        return;
    }

    // Step 2: Check indices that cannot be moved anywhere
    for (int i = 0; i < n; ++i) {
        bool can_move_left = (i - k >= 0);
        bool can_move_right = (i + k < n);

        // If index i cannot move either left or right, s[i] must match t[i]
        if (!can_move_left && !can_move_right) {
            if (s[i] != t[i]) {
                cout << "NO\n";
                return;
            }
        }
    }

    cout << "YES\n";
}

int main() {
    fast_io();
    
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }

    return 0;
}
