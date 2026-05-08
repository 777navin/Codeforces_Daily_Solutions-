/*
Date: 08-05-2026
Problem Name: Solution for Cube
Platform: Codeforces
Difficulty: 1500
Tags: implementation, math, brute force

Problem Summary:
Given a 2x2x2 Rubik's cube flattened into an array of 24 integers representing the colors 
of its square faces, determine if the cube can be completely solved using exactly one 
90-degree rotation of any one face in either direction.

Methods to Solve:
1. Simulation of Face Rotations (Optimal for small state space)

- Intuition:
  A 2x2x2 cube consists of 6 faces, each having 4 stickers. A single 90-degree face rotation 
  leaves the stickers on the rotated face (and its opposite face) within their respective faces. 
  The only stickers that change faces are the 8 stickers forming a "band" around the rotated face. 
  Because there are only 3 axes of rotation, there are exactly 6 possible 8-sticker bands. 
  A 90-degree turn simply shifts the stickers in one of these bands forward or backward by 2 positions.

- Approach:
  1. Define the 6 bands (cycles of 8 sticker indices) based on the unfolded 2D net of the cube.
  2. For each band, simulate shifting the stickers by +2 (clockwise) and +6 (counter-clockwise, equivalent to -2).
  3. After each shift, check if the cube is solved.
  4. A cube is solved if all 6 faces (groups of indices 1-4, 5-8, ..., 21-24) have identical colors.
  5. If any simulated state is solved, output YES. If all 12 possibilities fail, output NO.

- Dry Run (Sample 2):
  Input: 5 3 5 3 2 5 2 5 6 2 6 2 4 4 4 4 1 1 1 1 6 3 6 3
  Faces 4 (Left) and 5 (Right) are already solid (4s and 1s).
  Band 1 (Left vertical slice) indices: 1, 3, 5, 7, 9, 11, 24, 22.
  Current values at these indices: 5, 5, 2, 2, 6, 6, 3, 3.
  Shifting by +2 positions yields: 3, 3, 5, 5, 2, 2, 6, 6.
  Applying this shift makes Top, Front, Bottom, and Back faces solid.
  The cube becomes solved. Return YES.

- Time Complexity: O(1) 
  The cube always has exactly 24 stickers, and we check a maximum of 12 fixed-size permutations.
- Space Complexity: O(1)
  Only an array of 24 integers and the fixed permutation mappings are stored.
- Why better than previous method: N/A (Direct simulation is the only necessary approach).
- When to use: When a system has a fixed, small state-space limit and explicit mapping is trivial.

Comparison Table:
Method               | TC   | SC   | Best Use Case
Simulation           | O(1) | O(1) | Small combinatorial problems with fixed bounds.

Final Recommended Solution: Simulation of Face Rotations
*/

#include <iostream>
#include <vector>

using namespace std;

// Function to check if the current cube state is solved
// A state is solved if all 4 stickers on each of the 6 faces are the same.
bool is_solved(const vector<int>& a) {
    for (int i = 1; i <= 24; i += 4) {
        if (a[i] != a[i + 1] || a[i] != a[i + 2] || a[i] != a[i + 3]) {
            return false;
        }
    }
    return true;
}

void solve() {
    // 1-based indexing for the 24 stickers
    vector<int> a(25);
    for (int i = 1; i <= 24; ++i) {
        cin >> a[i];
    }

    // Precomputed cycles of indices that move together during face rotations.
    // Each of the 6 vectors represents the 8 stickers adjacent to one of the 6 faces.
    vector<vector<int>> bands = {
        {1, 3, 5, 7, 9, 11, 24, 22},   // Left vertical band
        {2, 4, 6, 8, 10, 12, 23, 21},  // Right vertical band
        {13, 14, 5, 6, 17, 18, 21, 22}, // Top horizontal band
        {15, 16, 7, 8, 19, 20, 23, 24}, // Bottom horizontal band
        {3, 4, 17, 19, 10, 9, 16, 14},  // Front coronal band
        {1, 2, 18, 20, 12, 11, 15, 13}  // Back coronal band
    };

    // Try rotating each band
    for (const auto& band : bands) {
        // A 90-degree turn shifts elements by 2.
        // dir = 2 is clockwise, dir = 6 is counter-clockwise (8 - 2)
        for (int dir : {2, 6}) {
            vector<int> b = a; // Copy original state
            
            // Apply the shift mapping
            for (int i = 0; i < 8; ++i) {
                b[band[(i + dir) % 8]] = a[band[i]];
            }
            
            // Check if the single rotation solved the cube
            if (is_solved(b)) {
                cout << "YES\n";
                return;
            }
        }
    }
    
    // If no valid configuration is found
    cout << "NO\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // Single test case required for this problem
    solve();
    
    return 0;
}
