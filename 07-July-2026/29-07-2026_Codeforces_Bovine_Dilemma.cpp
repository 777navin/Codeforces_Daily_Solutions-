/*
=========================================================
Date        : 29-07-2026
Problem Name: Bovine Dilemma
Platform    : Codeforces
Difficulty  : 800
Tags        : geometry, math

Problem Summary:
Given 'n' x-coordinates of trees on the x-axis and one tree at (0,1).
Find the number of different non-zero areas of triangles that can be 
formed using the tree at (0,1) and any two trees on the x-axis.

Key Observation:
The area of the triangle is 0.5 * base * height. The height is always 1.
Thus, the area strictly depends on the base length, which is the 
absolute difference between the x-coordinates of the two chosen trees.
=========================================================

1. Most Optimal Approach
---------------------------------------------------------
- Intuition:
  Since the height is fixed at 1, different areas correspond directly
  to different base lengths. We just need to find all unique distances
  between any two trees on the x-axis.
  
- Approach:
  1. Read the array of x-coordinates.
  2. Use two nested loops to pair every tree with every other tree.
  3. Calculate the absolute difference between their x-coordinates.
  4. Store these differences in a set to keep only unique non-zero values.
  5. The size of the set is our answer.

- Why it Works:
  A set automatically filters out duplicate differences, giving us 
  the exact count of distinct triangle areas. 

- Time Complexity (TC): 
  O(n^2 log n) due to nested loops and set insertions. With n <= 50, 
  this is well within the 1-second time limit.

- Space Complexity (SC): 
  O(n^2) to store the unique differences in the set.

---------------------------------------------------------
Final Approach Justification:
The given constraints (N <= 50) are very small. A brute-force 
computation of all pairwise differences stored in a standard set 
is highly efficient, clean to implement, and strictly optimal 
for this problem size.
=========================================================
*/

#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    
    set<int> unique_areas;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            unique_areas.insert(abs(x[j] - x[i]));
        }
    }
    
    cout << unique_areas.size() << "\n";
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
