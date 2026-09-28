/*
=========================================================
Date        : 28-09-2026
Problem Name: A. Lame King
Platform    : Codeforces
Difficulty  : 800
Tags        : math, greedy

Problem Summary:
A king starts at (0, 0) on a 201x201 checkerboard and needs to reach (a, b).
The king can move Up, Down, Left, Right, or Skip, but cannot repeat the exact 
same move in two consecutive seconds. Calculate the minimum seconds required.

Key Observation:
Moving diagonally requires alternating between horizontal and vertical moves. 
If distance in one direction exceeds the other, extra skip moves are forced.
=========================================================
*/

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

/*
---------------------------------------------------------
APPROACH 1: Greedy / Mathematical Analysis
---------------------------------------------------------

• Intuition:
  To reach (a, b), we need at least |a| horizontal steps and |b| vertical steps. 
  Since we can alternate horizontal and vertical moves without repeating moves, 
  min(|a|, |b|) steps can be paired directly.

• Approach:
  Let dx = |a| and dy = |b|.
  If dx == dy, we can perfectly alternate horizontal and vertical moves in 2 * dx steps.
  If dx != dy, let max_d = max(dx, dy) and min_d = min(dx, dy).
  We alternate moves for 2 * min_d steps. The remaining (max_d - min_d) steps in the 
  dominant direction must be separated by Skip moves. Thus, we need 2 * max_d - 1 total moves.

• Why it Works:
  Alternating (Move X, Move Y) handles equal components without penalty.
  When one component is larger, inserting a 'Skip' move between consecutive same-direction 
  moves satisfies the constraint while minimizing total steps.

• Time Complexity (TC) : O(1) per test case
• Space Complexity (SC): O(1) auxiliary space
---------------------------------------------------------
*/

/*
=========================================================
FINAL APPROACH CHOICE
=========================================================
• Chosen Approach: Mathematical / Greedy (O(1))
• Reason: The board bounds and step counts can be computed directly via coordinate 
  differences without simulation, making it optimal in both time and space.
=========================================================
*/

void solve() {
    int a, b;
    cin >> a >> b;
    
    int dx = abs(a);
    int dy = abs(b);
    
    if (dx == dy) {
        cout << 2 * dx << "\n";
    } else {
        cout << 2 * max(dx, dy) - 1 << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
