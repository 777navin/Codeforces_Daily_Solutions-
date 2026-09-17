/*
=========================================================
Date        : 17-09-2026
Problem Name: A. Dead Pixel
Platform    : Codeforces
Difficulty  : 800
Tags        : Implementation, Greedy, Math

Problem Summary:
Polycarp has an a x b monitor with a dead pixel at coordinates (x, y). 
He wants to find the maximum possible area of a rectangular window that does not contain the dead pixel.

Key Observation:
The maximum window not containing the dead pixel can be formed by stretching it to one of the four borders (left, right, top, bottom) of the screen, restricted by the position of the dead pixel.
=========================================================
*/

/*
=========================================================
APPROACH EXPLANATION
=========================================================

1. Optimized (Greedy)
• Intuition: The dead pixel splits the screen into regions. To maximize the window area, we can push the window's boundaries against the screen edges while avoiding the dead pixel.
• Approach: For a dead pixel at (x, y), the maximum window can be formed in 4 possible directions:
  1. To the left of the dead pixel: width = x, height = b
  2. To the right of the dead pixel: width = a - x - 1, height = b
  3. Above the dead pixel: width = a, height = y
  4. Below the dead pixel: width = a, height = b - y - 1
  We calculate the areas for all possible directions and take the maximum.
• Why it Works: Any valid maximal window without the dead pixel must touch at least one of the screen borders in one of the dimensions and be bounded by the dead pixel coordinate in the other.
• Time Complexity (TC): O(1) per test case.
• Space Complexity (SC): O(1).
=========================================================
*/

/*
=========================================================
FINAL APPROACH
=========================================================
We use the direct greedy approach calculating the maximum possible widths and heights relative to the dead pixel's coordinates. This is optimal with O(1) time complexity per test case, perfectly suited for Codeforces constraints.
=========================================================
*/

#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    long long a, b, x, y;
    cin >> a >> b >> x >> y;

    // Calculate maximum area in four possible directions
    long long area1 = x * b;             // Left side of dead pixel
    long long area2 = (a - x - 1) * b;   // Right side of dead pixel
    long long area3 = a * y;             // Top side of dead pixel
    long long area4 = a * (b - y - 1);   // Bottom side of dead pixel

    long long max_area = max({area1, area2, area3, area4});
    cout << max_area << "\n";
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
