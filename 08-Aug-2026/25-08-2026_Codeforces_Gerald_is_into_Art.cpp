/*
=========================================================
Date        : 25-08-2026
Problem Name: Gerald is into Art
Platform    : Codeforces
Difficulty  : 1200
Tags        : geometry, brute force, implementation

Problem Summary:
Determine if two rectangular paintings of sizes (a2 x b2) and (a3 x b3) can be placed
on a rectangular board of size (a1 x b1) without overlapping.
Paintings can be rotated by 90 degrees and must have sides parallel to the board edges.

Key Observation:
Since there are only two paintings, they can only be placed side-by-side either
horizontally or vertically. Testing all rotations gives a constant O(1) checks.
=========================================================
*/

/*
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
APPROACH 1: Complete Orientation Checking (Optimal)
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
• Intuition:
  - Two non-overlapping rectangles placed inside a larger rectangle must split along a straight boundary line, meaning they lie adjacent either horizontally or vertically.
  - Each painting has 2 possible orientations (normal or rotated 90 degrees).

• Approach:
  - Try all 4 combinations of rotations for the two paintings: (a2, b2) / (b2, a2) and (a3, b3) / (b3, a3).
  - For each configuration with dimensions (w1, h1) and (w2, h2), check if:
    1. Placed side-by-side along length: (w1 + w2 <= a1 && max(h1, h2) <= b1) or (w1 + w2 <= b1 && max(h1, h2) <= a1)
    2. Placed stacked along height: (max(w1, w2) <= a1 && h1 + h2 <= b1) or (max(w1, w2) <= b1 && h1 + h2 <= a1)
  - If any configuration fits within the board, print "YES"; otherwise, print "NO".

• Why it Works:
  - Exhaustively tests all geometric placements in a bounded 2D space.

• Time Complexity (TC): O(1) - Constant number of arithmetic checks.
• Space Complexity (SC): O(1) - Auxiliary space used is constant.
*/

/*
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
FINAL APPROACH:
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
• This approach is directly chosen because the problem space contains only 2 paintings, yielding at most 4 rotation states.
• It provides immediate O(1) runtime and zero auxiliary memory overhead.
*/

#include <iostream>
#include <algorithm>

using namespace std;

// Helper function to check if two oriented rectangles (w1, h1) and (w2, h2) fit in board (A, B)
bool fits(int A, int B, int w1, int h1, int w2, int h2) {
    // Side by side along A, within B
    if (w1 + w2 <= A && max(h1, h2) <= B) return true;
    // Side by side along B, within A
    if (w1 + w2 <= B && max(h1, h2) <= A) return true;
    // Stacked along B, within A
    if (h1 + h2 <= B && max(w1, w2) <= A) return true;
    // Stacked along A, within B
    if (h1 + h2 <= A && max(w1, w2) <= B) return true;
    return false;
}

void solve() {
    int a1, b1;
    int a2, b2;
    int a3, b3;

    if (!(cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3)) return;

    bool possible = false;

    // Check all 4 rotation combinations of both paintings
    if (fits(a1, b1, a2, b2, a3, b3)) possible = true;
    if (fits(a1, b1, a2, b2, b3, a3)) possible = true;
    if (fits(a1, b1, b2, a2, a3, b3)) possible = true;
    if (fits(a1, b1, b2, a2, b3, a3)) possible = true;

    if (possible) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    // Optimize standard I/O operations for CP
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
