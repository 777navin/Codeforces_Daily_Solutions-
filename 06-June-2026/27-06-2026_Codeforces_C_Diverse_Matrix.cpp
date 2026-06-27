/*
Date: 27-06-2026
Problem Name: C. Diverse Matrix
Platform: Codeforces
Difficulty: 1400
Tags: Constructive Algorithms, Math, Number Theory, GCD

Problem Summary:
Given a matrix of size r x c, assign positive integers such that the GCDs of 
all r rows and c columns are pairwise distinct. Minimize the maximum GCD 
(magnitude) used. If no solution exists, output 0.

Methods to Solve:
1. Constructive Mathematics (Optimal)

For EACH method include:

- Intuition
  To ensure distinct GCDs for rows and columns without overlapping, we can use 
  multipliers. If we assign 1 to r as row multipliers and (r+1) to (r+c) as 
  column multipliers, the matrix element at (i, j) becomes i * (r + j).
  Row GCDs will be 1, 2, ..., r. 
  Column GCDs will be r+1, r+2, ..., r+c. 
  This guarantees all r+c GCDs are unique.

- Approach
  If r <= c: We apply the standard multipliers. Row i gets i, col j gets r+j.
  If r > c: The standard approach yields overlapping GCDs because the smaller 
  dimension (columns) wouldn't provide a coprime base (which leads to WA on 
  edge cases like r=2, c=1). We handle this by transposing the multiplier logic: 
  assign 1 to c as column multipliers, and (c+1) to (c+r) as row multipliers.
  Corner case: If r == 1 and c == 1, it's impossible to have distinct GCDs, return 0.

- Dry Run (small example)
  r = 2, c = 1 (r > c case)
  Cols get {1}. Rows get {1+1, 1+2} = {2, 3}.
  Matrix: 
  [2 * 1] = [2]
  [3 * 1] = [3]
  Row GCDs: 2, 3. Col GCDs: gcd(2,3)=1. 
  All unique: {1, 2, 3}. Magnitude is 3.

- Time Complexity
  O(r * c) to traverse and print the matrix.

- Space Complexity
  O(1) auxiliary space as values are printed on the fly.

- Why better than previous method
  Correctly handles the `r > c` edge case which previously caused overlapping 
  GCDs (fixing the Wrong Answer on Test 4).

- When to use
  Always for this specific constructive problem.

Comparison Table:
Method       | TC     | SC   | Best Use Case
-------------|--------|------|--------------
Constructive | O(r*c) | O(1) | Optimal and robust for all valid inputs

Final Recommended Solution
Constructive Mathematics with correct dimension swapping.
*/

#include <iostream>

using namespace std;

void solve() {
    int r, c;
    if (!(cin >> r >> c)) return;

    // Corner case where no diverse matrix is possible
    if (r == 1 && c == 1) {
        cout << 0 << "\n";
        return;
    }

    // Standard case: number of rows <= number of columns
    if (r <= c) {
        for (int i = 1; i <= r; ++i) {
            for (int j = 1; j <= c; ++j) {
                cout << i * (r + j) << (j == c ? "" : " ");
            }
            cout << "\n";
        }
    } 
    // Edge case (r > c): swap the multiplier logic to prevent GCD overlap
    else {
        for (int i = 1; i <= r; ++i) {
            for (int j = 1; j <= c; ++j) {
                cout << (c + i) * j << (j == c ? "" : " ");
            }
            cout << "\n";
        }
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
