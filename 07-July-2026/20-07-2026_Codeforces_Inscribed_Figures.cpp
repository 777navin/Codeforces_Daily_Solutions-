/*
=========================================================
Date        : 20-07-2026
Problem Name: A. Inscribed Figures
Platform    : Codeforces
Difficulty  : 1400
Tags        : Implementation, Geometry

Problem Summary:
Given a sequence of figures (1: Circle, 2: Triangle, 3: Square) where each subsequent 
figure is inscribed inside the previous one with maximum possible dimensions. 
We need to determine if the total number of touching points is finite or infinite. 
If it is finite, calculate and print the total number of distinct touching points.

Key Observation:
An infinite number of points occurs if a square is inscribed in a triangle (3 inside 2) 
or a triangle is inscribed in a square (2 inside 3), as they share a line segment. 
Otherwise, the intersection points are distinct and countable based on adjacent pairs, 
with a special reduction when a triangle is inside a circle which is inside a square (3 -> 1 -> 2).
=========================================================
*/

#include <iostream>
#include <vector>

using namespace std;

/*
Approach 1: Optimized Linear Scan (Simulation)
• Intuition:
  The problem can be solved by analyzing adjacent pairs of figures. Each combination 
  of adjacent figures contributes a specific number of touching points, or triggers an 
  infinite condition. We also track three consecutive elements to handle overlapping points.

• Approach:
  - Check all adjacent pairs $(a_i, a_{i+1})$. If we ever see pairs (2, 3) or (3, 2), return "Infinite".
  - For finite pairs, count points: (1, 2) or (2, 1) gives 3 points; (1, 3) or (3, 1) gives 4 points.
  - If we look at triplets, when a triangle (2) is inscribed in a circle (1) which is inscribed 
    in a square (3), the top vertex of the triangle touches the circle exactly where the circle 
    touches the top side of the square. Thus, one point is double-counted and we subtract 1.

• Why it Works:
  The geometric constraints state that the shapes are centered and maximized. The contact 
  points are structurally invariant for these shapes, allowing a direct case-by-case evaluation.

• Time Complexity (TC) : O(n) - We iterate through the array of figures exactly once.
• Space Complexity (SC): O(1) - Only a few variables are used to track the points and status.
*/

// Why this approach is chosen:
// This is the most optimal approach as it resolves the geometric intersections in a single pass.
// It directly tracks state changes without complex geometric calculations or floating-point issues.

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int total_points = 0;

    for (int i = 0; i < n - 1; ++i) {
        // Infinite intersections check: Triangle & Square adjacent
        if ((a[i] == 2 && a[i + 1] == 3) || (a[i] == 3 && a[i + 1] == 2)) {
            cout << "Infinite\n";
            return;
        }
        
        // Circle and Triangle (3 touching points)
        if ((a[i] == 1 && a[i + 1] == 2) || (a[i] == 2 && a[i + 1] == 1)) {
            total_points += 3;
        }
        // Circle and Square (4 touching points)
        else if ((a[i] == 1 && a[i + 1] == 3) || (a[i] == 3 && a[i + 1] == 1)) {
            total_points += 4;
        }

        // Handle the special triplet case: Square -> Circle -> Triangle (3 -> 1 -> 2)
        // The top vertex of the triangle shares a point where the circle touches the square.
        if (i > 0 && a[i - 1] == 3 && a[i] == 1 && a[i + 1] == 2) {
            total_points -= 1;
        }
    }

    cout << "Finite\n" << total_points << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
