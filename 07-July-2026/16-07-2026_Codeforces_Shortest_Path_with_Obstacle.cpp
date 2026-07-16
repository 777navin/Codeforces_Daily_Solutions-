/*
=========================================================
Date        : 16-07-2026
Problem Name: Shortest Path with Obstacle
Platform: Codeforces
Difficulty: 800
Tags: math, geometry

Problem Summary:
Find the shortest path on a 2D grid between two points A and B.
You can move in 4 adjacent directions, but point F is an obstacle.
Calculate the minimum number of steps required to reach B from A.

Key Observation:
The shortest path is the Manhattan distance, unless A, B, and F are collinear 
and F lies strictly between A and B, which requires going around (+2 steps).
=========================================================

Approach 1: Most Optimal (Math / Manhattan Distance)
• Intuition: 
  On an empty grid, the shortest path is just the Manhattan distance.
  An obstacle only matters if it directly blocks the straight-line path.
• Approach: 
  Calculate Manhattan distance: |xA - xB| + |yA - yB|.
  Check if A, B, F share the exact same X or Y coordinate.
  If they do, and F is strictly between A and B, add 2 to the distance.
• Why it Works: 
  If F blocks the straight line, we must step sideways once and back once,
  which adds exactly 2 extra steps to the base distance.
• Time Complexity (TC): 
  O(1) - Constant time mathematical operations per test case.
• Space Complexity (SC): 
  O(1) - Only a few integer variables are used.

Final Approach Justification:
• This approach evaluates the grid coordinates mathematically in O(1) time.
• It is chosen because the grid shortest path without obstacles is always the Manhattan distance.
• We only apply a constant +2 penalty when geometrically blocked, making it maximally optimal and clean.
*/

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

void solve() {
    int xA, yA;
    int xB, yB;
    int xF, yF;
    
    cin >> xA >> yA;
    cin >> xB >> yB;
    cin >> xF >> yF;

    // Base shortest path on a grid without obstacles
    int ans = abs(xA - xB) + abs(yA - yB);

    // If A and B are on the same vertical line
    if (xA == xB && xA == xF) {
        // Check if F is strictly between A and B vertically
        if (yF > min(yA, yB) && yF < max(yA, yB)) {
            ans += 2; // Sidestep requires 2 extra moves
        }
    }
    // If A and B are on the same horizontal line
    else if (yA == yB && yA == yF) {
        // Check if F is strictly between A and B horizontally
        if (xF > min(xA, xB) && xF < max(xA, xB)) {
            ans += 2; // Sidestep requires 2 extra moves
        }
    }

    cout << ans << "\n";
}

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    
    return 0;
}
