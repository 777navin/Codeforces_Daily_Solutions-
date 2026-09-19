/*
=========================================================
Date        : 19-09-2026
Problem Name: 701B - Cells Not Under Attack
Platform    : Codeforces
Difficulty  : 1200
Tags        : math, implementation, data structures

Problem Summary:
Given an n x n chessboard and m rooks placed one by one.
A cell is under attack if it shares a row or a column with any placed rook.
After placing each rook, determine the number of cells that are not under attack.

Key Observation:
A cell (r, c) is safe if and only if row r has no rook and column c has no rook.
If there are 'cntR' distinct attacked rows and 'cntC' distinct attacked columns,
the number of unattacked cells is exactly (n - cntR) * (n - cntC).
=========================================================
*/

/*
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
APPROACH 1: Brute Force
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
• Intuition:
  Maintain an n x n 2D grid to track attacked cells directly after each rook placement.

• Approach:
  For each rook placed at (x, y), mark the entire row x and column y as attacked,
  then iterate over the entire grid to count the remaining safe cells.

• Why it Works:
  Directly simulates the rook attacks as defined by the problem statement.

• Time Complexity (TC):
  O(m * n^2) - Traversing/updating the grid takes O(n^2) operations per rook.
  Fails because n <= 10^5 and m <= 10^5.

• Space Complexity (SC):
  O(n^2) - Required for the 2D grid representation (MLE for n = 10^5).
*/

/*
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
APPROACH 2: Optimized (Tracking Unique Rows and Columns)
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
• Intuition:
  Instead of tracking individual cells, track which rows and columns are attacked.
  Any intersection of an unattacked row and an unattacked column forms a safe cell.

• Approach:
  Use boolean arrays or hash sets to mark visited rows and columns.
  Track the count of unique attacked rows (cntR) and columns (cntC).
  After processing each rook, the number of safe cells is (n - cntR) * (n - cntC).

• Why it Works:
  By independence of rows and columns, the number of safe positions is the Cartesian
  product of all safe rows and all safe columns.

• Time Complexity (TC):
  O(m) - Each rook is processed in O(1) time using boolean flags.

• Space Complexity (SC):
  O(n) - Two boolean vectors of size n + 1 to store row and column states.
*/

/*
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
FINAL APPROACH: Unique Row & Column Tracking
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
• Why chosen:
  It operates in O(1) per rook placement, easily fitting within the 2.0-second limit for m = 10^5.
• Comparison:
  Reduces time from an infeasible O(m * n^2) down to linear O(m) and memory from O(n^2) to O(n).
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Optimize standard I/O operations for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    int m;
    if (!(cin >> n >> m)) return 0;

    vector<bool> row_used(n + 1, false);
    vector<bool> col_used(n + 1, false);

    long long cntR = 0; // Number of distinct rows attacked
    long long cntC = 0; // Number of distinct columns attacked

    for (int i = 0; i < m; ++i) {
        int r, c;
        cin >> r >> c;

        if (!row_used[r]) {
            row_used[r] = true;
            cntR++;
        }
        if (!col_used[c]) {
            col_used[c] = true;
            cntC++;
        }

        long long safe_cells = (n - cntR) * (n - cntC);
        cout << safe_cells << (i == m - 1 ? "" : " ");
    }
    cout << "\n";

    return 0;
}
