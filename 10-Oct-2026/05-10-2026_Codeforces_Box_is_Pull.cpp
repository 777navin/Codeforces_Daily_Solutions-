/*
=========================================================
Date        : 05-10-2026
Problem Name: Box is Pull
Platform    : Codeforces
Difficulty  : 800
Tags        : math, implementation, greedy

Problem Summary:
Wabbit needs to move a box from (x1, y1) to (x2, y2).
Moving the box along a straight horizontal or vertical line takes time equal to the distance.
If the box needs to change directions (both x and y coordinates change), extra 2 seconds are required to change pulling position.

Key Observation:
If x1 == x2 or y1 == y2, the total time is simply the straight-line distance.
If x1 != x2 and y1 != y2, Wabbit must move along one axis, turn around, and move along the other axis, adding 2 penalty seconds for repositioning.
=========================================================
*/

#include <iostream>
#include <cmath>

using namespace std;

/*
---------------------------------------------------------
1. Optimal Approach (Greedy / Math)
---------------------------------------------------------
• Intuition:
  Moving along a single axis requires distance |x1 - x2| or |y1 - y2| time without any extra turns.
  Changing axis direction requires moving out of the way and getting into position, adding an extra 2 seconds.

• Approach:
  - If x1 == x2, answer is |y1 - y2|.
  - If y1 == y2, answer is |x1 - x2|.
  - If x1 != x2 and y1 != y2, answer is |x1 - x2| + |y1 - y2| + 2.

• Why it Works:
  - Straight line movement allows pulling directly.
  - Direction changes force Wabbit to move 2 steps around the box to change orientation before pulling again.

• Time Complexity (TC): O(1) per test case.
• Space Complexity (SC): O(1) auxiliary space.
---------------------------------------------------------
*/

/*
=========================================================
FINAL APPROACH SELECTION:
This approach directly calculates the minimal path length in O(1) time.
It handles all edge cases cleanly and is optimal in terms of both time and space complexity.
=========================================================
*/

void solve() {
    long long x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    
    long long dx = abs(x1 - x2);
    long long dy = abs(y1 - y2);
    
    if (dx == 0) {
        cout << dy << "\n";
    } else if (dy == 0) {
        cout << dx << "\n";
    } else {
        cout << dx + dy + 2 << "\n";
    }
}

int main() {
    // Optimize standard I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
