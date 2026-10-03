/*
=========================================================
Date        : 03-10-2026
Problem Name: 911B - Two Cakes
Platform    : Codeforces
Difficulty  : 1200
Tags        : Binary Search, Brute Force, Implementation, Math

Problem Summary:
Ivan has two cakes cut into 'a' and 'b' pieces respectively. He needs to distribute 
all pieces across 'n' plates such that each plate gets pieces from only one cake, 
and every plate gets at least 1 piece. The goal is to maximize the minimum number 
of pieces 'x' present on any single plate.

Key Observation:
Since 'a' and 'b' are very small (<= 100), we can iterate over the possible number of 
plates 'i' allocated to the first cake (from 1 to n - 1). The remaining 'n - i' plates 
will get the second cake. For a fixed split, the minimum pieces per plate is min(a / i, b / (n - i)).
=========================================================
*/

#include <iostream>
#include <algorithm>

using namespace std;

/*
---------------------------------------------------------
APPROACH 1: Brute Force / Iterative Search
---------------------------------------------------------
• Intuition:
  Try all valid splits of allocating 'i' plates to the first cake and 'n - i' plates 
  to the second cake, keeping track of the best minimum piece count achieved.

• Approach:
  Iterate 'i' from 1 to n - 1. For each 'i', calculate the pieces per plate for the 
  first cake as a / i and for the second cake as b / (n - i). The value of x for this 
  split is min(a / i, b / (n - i)). Take the maximum of x over all valid values of 'i'.

• Why it Works:
  Since every plate must contain at least one piece and cannot mix cakes, at least 1 
  plate must be assigned to cake A and at least 1 plate to cake B. Iterating all possible 
  plate allocations guarantees finding the optimal distribution.

• Time Complexity (TC): O(n)
  We iterate through all possible plate splits from 1 to n - 1.

• Space Complexity (SC): O(1)
  Uses only a few integer variables.
---------------------------------------------------------
*/

/*
=========================================================
FINAL APPROACH SELECTION
=========================================================
• Selected Approach: Brute Force (Iterative Split)
• Reason for Choice:
  Given the constraint n <= a + b <= 200, an O(n) linear search executes instantaneously 
  (well within the 1.0s time limit) and is extremely simple and clean to implement without 
  the overhead of binary search.
=========================================================
*/

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a, b;
    if (!(cin >> n >> a >> b)) return 0;

    int max_x = 0;

    // Allocate 'i' plates for the first cake and 'n - i' plates for the second cake
    for (int i = 1; i < n; ++i) {
        int plates_a = i;
        int plates_b = n - i;

        int pieces_per_plate_a = a / plates_a;
        int pieces_per_plate_b = b / plates_b;

        int current_min = min(pieces_per_plate_a, pieces_per_plate_b);
        max_x = max(max_x, current_min);
    }

    cout << max_x << "\n";

    return 0;
}
