/*
=========================================================
Date        : 12-09-2026
Problem Name: Distance (1612A)
Platform    : Codeforces
Difficulty  : 800
Tags        : math, constructive algorithms, geometry

Problem Summary:
Given point A(0, 0) and point B(x, y), find an integer point C
such that d(A, C) = d(A, B) / 2 and d(B, C) = d(A, B) / 2, where
d is the Manhattan distance. If no such point exists, print -1 -1.

Key Observation:
d(A, B) = x + y. If (x + y) is odd, the half-distance is not an integer,
so no valid point exists. If (x + y) is even, we can walk (x + y) / 2
steps along the Manhattan path from (0, 0) to (x, y).
=========================================================
*/

/*
---------------------------------------------------------
APPROACH 1: Brute Force Search
---------------------------------------------------------
• Intuition:
  The constraints on x and y are small (0 <= x, y <= 50), so any valid
  point C must lie within a small coordinate bounding box.
• Approach:
  Iterate over all possible pairs (cx, cy) in [0, 50] x [0, 50].
  Check if d(A, C) == d(A, B) / 2 and d(B, C) == d(A, B) / 2.
• Why it Works:
  The solution space is finite and tiny; an exhaustive search will locate
  a solution if one exists.
• Time Complexity (TC) : O(max(x, y)^2) per test case
• Space Complexity (SC): O(1)

---------------------------------------------------------
APPROACH 2: Direct Construction (Optimal)
---------------------------------------------------------
• Intuition:
  Point C lies halfway along the Manhattan path from A(0, 0) to B(x, y).
• Approach:
  Check if (x + y) is odd; if so, output -1 -1.
  Otherwise, target distance is k = (x + y) / 2.
  If x >= k, set C = (k, 0).
  Else, set C = (x, k - x).
• Why it Works:
  Because 0 <= x <= k <= x + y, C always lies on the bounding box segments
  between (0, 0) and (x, y), ensuring d(A, C) = k and d(B, C) = (x - cx) + (y - cy) = k.
• Time Complexity (TC) : O(1) per test case
• Space Complexity (SC): O(1)
*/

/*
=========================================================
FINAL APPROACH: Direct Construction
• Provides an instant O(1) mathematical solution without search loops.
• Naturally handles boundary conditions and cleanly avoids unnecessary iterations.
=========================================================
*/

#include <iostream>

using namespace std;

void solve() {
    int x, y;
    cin >> x >> y;

    if ((x + y) % 2 != 0) {
        cout << "-1 -1\n";
        return;
    }

    int half = (x + y) / 2;
    if (x >= half) {
        cout << half << " " << 0 << "\n";
    } else {
        cout << x << " " << (half - x) << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
