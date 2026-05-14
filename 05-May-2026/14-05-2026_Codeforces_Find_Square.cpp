/*
Date: 14-05-2026
Problem Name: Find Square
Platform: Codeforces
Difficulty: 800
Tags: Implementation, Math

Problem Summary
Given an n x m grid initially fully white ('W') with a single painted black ('B') square of an odd side length, find the 1-based row and column coordinates of the center of this black square.

Methods to Solve:
1. Brute Force (First Black Cell & Side Length)
2. Better Approach (Bounding Box Min/Max)
3. Optimal Approach (Center of Mass)

For EACH method include:

- Intuition
  1. First Cell: Find the very first 'B' (top-left). Count consecutive 'B's in that row to find the side length `L`. Center is `(row + L/2, col + L/2)`.
  2. Bounding Box: Keep track of the minimum and maximum row and column indices where a 'B' appears. The center is the exact midpoint of these boundaries.
  3. Center of Mass: Since a square is perfectly symmetrical, the average of all 'B' row coordinates and the average of all 'B' column coordinates will mathematically pinpoint the exact center.

- Approach (Optimal - Center of Mass)
  Iterate through every cell in the grid. Whenever a 'B' is encountered, add its row index to a running total `r_sum` and its column index to `c_sum`, while incrementing a `count` of total black cells. Finally, divide the sums by `count` to get the exact center.

- Dry Run (small example)
  Input: 
  3 3
  WWW
  BWW
  WWW
  'B' is at row 2, col 1.
  r_sum = 2, c_sum = 1, count = 1.
  Center Row = 2 / 1 = 2
  Center Col = 1 / 1 = 1
  Output: 2 1

- Time Complexity
  $O(n \cdot m)$ because we must read every cell in the grid exactly once.

- Space Complexity
  $O(1)$ auxiliary space. We read characters on the fly and only store sum and count variables, entirely avoiding the need to store the grid in memory.

- Why better than previous method
  The Center of Mass approach requires zero conditional logic (no `min()`/`max()` checks) once a 'B' is found. It is purely additive, making it completely bug-proof against weird boundary edge cases.

- When to use
  Highly recommended when finding the exact center of any uniformly symmetrical, contiguous shape on a grid.

Comparison Table:
Method         | TC           | SC     | Best Use Case
-------------------------------------------------------------------
First Cell     | $O(n \cdot m)$ | $O(1)$ | Top-down parsing, early exit possible
Bounding Box   | $O(n \cdot m)$ | $O(1)$ | Identifying limits of irregular shapes
Center of Mass | $O(n \cdot m)$ | $O(1)$ | Symmetrical uniform shapes (Safest)

Final Recommended Solution
Optimal Approach: Center of Mass
*/

#include <iostream>

using namespace std;

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;

    long long r_sum = 0;
    long long c_sum = 0;
    long long count = 0;

    // Process grid on the fly to save memory
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            char cell;
            cin >> cell;
            if (cell == 'B') {
                r_sum += i;
                c_sum += j;
                count++;
            }
        }
    }

    // The center is strictly the average of the coordinates
    if (count > 0) {
        cout << r_sum / count << " " << c_sum / count << "\n";
    }
}

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
