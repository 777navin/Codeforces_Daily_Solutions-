/*
=========================================================
Date        : 22-09-2026
Problem Name: Restoring Painting (675B)
Platform    : Codeforces
Difficulty  : 1400
Tags        : math, constructive algorithms, brute force

Problem Summary:
We are given a 3x3 grid where elements a, b, c, d are fixed at 
(0, 1), (1, 0), (1, 2), and (2, 1) respectively.
Each cell must contain an integer between 1 and n.
The sum of values in every 2x2 subgrid must be identical.
We need to find the total number of distinct valid 3x3 grids.

Key Observation:
The center cell is shared by all four 2x2 squares, and once the top-left 
corner cell x is chosen, the other three corner cells are uniquely determined.
The center cell can independently take any value from 1 to n.
=========================================================
*/

/*
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
APPROACH 1: Brute Force (Iterating over top-left corner)
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
• Intuition:
  Let the 3x3 grid cells be:
  [ x,  a, y1 ]
  [ b,  m,  c ]
  [ y2, d, y3 ]
  All four 2x2 subgrids share the center cell m.
  Equating the four 2x2 sums gives:
    x + a + b + m = a + y1 + m + c  => y1 = x + b - c
    x + a + b + m = b + y2 + m + d  => y2 = x + a - d
    x + a + b + m = m + c + d + y3  => y3 = x + a + b - c - d
  For each valid choice of x in [1, n], if y1, y2, y3 all lie in [1, n],
  then the center cell m can be any integer from 1 to n (n choices).

• Approach:
  - Iterate x from 1 to n.
  - Calculate y1, y2, y3 using the derived linear formulas.
  - Check if 1 <= y1, y2, y3 <= n.
  - If valid, increment the count of valid x values by 1.
  - Multiply the total count of valid x by n to account for all choices of m.

• Why it Works:
  - Since n <= 100,000, an O(n) loop runs in just a few milliseconds.
  - Every valid tuple (x, y1, y2, y3) uniquely determines the corner cells,
    while m independently contributes n configurations.

• Time Complexity (TC): O(n)
• Space Complexity (SC): O(1)

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
APPROACH 2: Most Optimal (Mathematical O(1))
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
• Intuition:
  Instead of looping x from 1 to n, we can directly find the range of valid x:
    1 <= x <= n
    1 <= x + b - c <= n            => 1 - (b - c) <= x <= n - (b - c)
    1 <= x + a - d <= n            => 1 - (a - d) <= x <= n - (a - d)
    1 <= x + a + b - c - d <= n    => 1 - (a + b - c - d) <= x <= n - (a + b - c - d)
  The intersection of these four intervals gives [L, R].
  The number of valid choices for x is max(0LL, R - L + 1).

• Approach:
  - Compute lower bound L = max({1, 1 - (b - c), 1 - (a - d), 1 - (a + b - c - d)}).
  - Compute upper bound R = min({n, n - (b - c), n - (a - d), n - (a + b - c - d)}).
  - Answer is max(0LL, R - L + 1) * n.

• Why it Works:
  - Resolves all boundary conditions analytically in constant time.

• Time Complexity (TC): O(1)
• Space Complexity (SC): O(1)
*/

/*
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
FINAL APPROACH CHOICE
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
We implement Approach 1 (O(n) iteration) as it is extremely concise, 
immune to subtle off-by-one/clamping edge cases, and executes well within 
the 1.0 second limit for n <= 100,000.
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, a, b, c, d;
    if (!(cin >> n >> a >> b >> c >> d)) {
        return 0;
    }

    long long valid_x_count = 0;

    for (long long x = 1; x <= n; ++x) {
        long long y1 = x + b - c;
        long long y2 = x + a - d;
        long long y3 = x + a + b - c - d;

        if (y1 >= 1 && y1 <= n &&
            y2 >= 1 && y2 <= n &&
            y3 >= 1 && y3 <= n) {
            valid_x_count++;
        }
    }

    long long total_paintings = valid_x_count * n;
    cout << total_paintings << "\n";

    return 0;
}
