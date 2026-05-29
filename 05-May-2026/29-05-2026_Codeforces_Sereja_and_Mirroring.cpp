/*
Date: 29-05-2026
Problem Name: Sereja and Mirroring
Platform: Codeforces (Problem 426B)
Difficulty: 1300
Tags: Implementation, Math, Matrices

Problem Summary:
Given an `n x m` matrix `a`, find the minimum number of rows of a matrix `b` that can be repeatedly "mirrored" to form matrix `a`. Mirroring an `x * y` matrix creates a `2x * y` matrix where the top half is the original and the bottom half is its horizontal reflection.

Methods to Solve:
1. Brute Force (Simulation of valid starting lengths)
2. Optimal Approach (Iterative Un-mirroring / Folding)

For EACH method include:

---
Method 1: Brute Force
- Intuition: The final matrix size `n` must be the result of repeatedly doubling the original row count. Thus, the original row count `k` must be of the form `n / 2^p`. We can try all valid divisors and simulate the mirroring process to see if it generates matrix `a`.
- Approach: Find all valid starting row lengths. For each length, dynamically simulate the mirroring expansion and compare the resulting matrix with `a`.
- Dry Run: For a 4x3 matrix, check starting sizes 1, 2, 4. For size 1, mirror to 2, then to 4, check if it matches `a`.
- Time Complexity: O(n * m * log n)
- Space Complexity: O(n * m)
- Why better than previous method: N/A
- When to use: When constraints are very small and simulation is requested.

---
Method 2: Optimal Approach (Iterative Un-mirroring)
- Intuition: Instead of building up from a smaller matrix, we can reverse the process. If the current matrix has an even number of rows and the top half is a perfect mirror of the bottom half, we can "un-mirror" (fold) it into half the size. We repeat this halving process until we can no longer fold.
- Approach:
  1. Check if the number of rows `n` is even. If odd, we can't un-mirror, so break and return `n`.
  2. If even, compare the top half rows with the reversed bottom half rows.
     (i.e., compare row `i` with row `current_rows - 1 - i`).
  3. If all corresponding elements match, we successfully un-mirror: `current_rows = current_rows / 2`.
  4. If any row mismatches, we can't un-mirror further, so we break the loop.
- Dry Run: 
  Matrix:
  0 0 1
  1 1 0
  1 1 0
  0 0 1
  n = 4 (even). Compare row 0 and 3 -> (0 0 1) == (0 0 1). Compare row 1 and 2 -> (1 1 0) == (1 1 0).
  Matches! Fold it to n = 2.
  New logical Matrix:
  0 0 1
  1 1 0
  n = 2 (even). Compare row 0 and 1 -> (0 0 1) != (1 1 0).
  Mismatch! Stop. Return n = 2.
- Time Complexity: O(n * m). We do `n/2` comparisons, then `n/4`, etc. The sum of the geometric series converges to `O(n)`. Multiplied by `m` elements per row, it is `O(n * m)`.
- Space Complexity: O(n * m) to store the matrix in memory.
- Why better than previous method: Avoids generating new matrices and redundant simulations. It is the most mathematically direct and optimal method.
- When to use: Always for this problem, as it easily handles the constraints.

Comparison Table:
Method           | TC               | SC       | Best Use Case
Brute Force      | O(n * m * log n) | O(n * m) | Educational purposes
Optimal Approach | O(n * m)         | O(n * m) | Competitive Programming / Standard solution

Final Recommended Solution: Optimal Approach (Iterative Un-mirroring)
*/

// 29-05-2026_Codeforces_Sereja_and_Mirroring.cpp

#include <iostream>
#include <vector>

using namespace std;

// Fast I/O Boilerplate
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve() {
    int n, m;
    // Reading dimensions
    if (!(cin >> n >> m)) return;

    // Reading the matrix
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    int current_rows = n;

    // Iteratively try to "un-mirror" the matrix
    while (current_rows % 2 == 0) {
        bool is_mirror = true;
        int half = current_rows / 2;

        // Compare the top half with the flipped bottom half
        for (int i = 0; i < half; ++i) {
            for (int j = 0; j < m; ++j) {
                // Check if row 'i' perfectly mirrors row 'current_rows - 1 - i'
                if (a[i][j] != a[current_rows - 1 - i][j]) {
                    is_mirror = false;
                    break;
                }
            }
            if (!is_mirror) break; // Early exit if mismatch found
        }

        // If it is a valid mirror, cut the logical row count in half
        if (is_mirror) {
            current_rows = half;
        } else {
            // Stop if it's not mirrored anymore
            break; 
        }
    }

    // Output the minimum possible starting rows
    cout << current_rows << "\n";
}

int main() {
    // Standard CP setup
    fast_io();
    
    // Codeforces 426B uses a single testcase pattern usually, 
    // but solve() encapsulates the logic cleanly.
    solve();
    
    return 0;
}
