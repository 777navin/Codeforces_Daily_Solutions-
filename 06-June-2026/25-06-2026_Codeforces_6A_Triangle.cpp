/*
Date: 25-06-2026
Problem Name: A. Triangle
Platform: Codeforces
Difficulty: 900
Tags: geometry, math, brute force

Problem Summary:
Given four sticks of different lengths, determine if it is possible to construct a 
non-degenerate triangle (positive area), a degenerate triangle (zero area), or if 
it is impossible to construct any triangle using any three sticks.

Methods to Solve:
1. Brute Force (Optimal for N=4)

For Method 1:
- Intuition: Since there are only 4 sticks and we need to choose 3, there are only 
  4 possible combinations (nCr where n=4, r=3). We check all combinations.
- Approach: Sort the lengths. Check if any three satisfy the triangle inequality.
  For sides a, b, c:
  - Non-degenerate: a + b > c (where a <= b <= c)
  - Degenerate: a + b == c
- Time Complexity: O(1) - Fixed number of combinations.
- Space Complexity: O(1)

Comparison Table:
Method | TC   | SC   | Best Use Case
-------|------|------|--------------
Brute  | O(1) | O(1) | Small N

Final Recommended Solution: Sort and check conditions.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to check if three sides form a triangle
// Returns 1 for non-degenerate, 0 for degenerate, -1 for impossible
int check(int a, int b, int c) {
    if (a + b > c) return 1;
    if (a + b == c) return 0;
    return -1;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> s(4);
    for (int i = 0; i < 4; ++i) {
        cin >> s[i];
    }

    // Sorting to easily check triangle inequality (a + b > c)
    sort(s.begin(), s.end());

    bool triangle = false;
    bool segment = false;

    // Check all combinations of 3 sticks
    // Combinations: (0,1,2), (0,1,3), (0,2,3), (1,2,3)
    int combos[4][3] = {
        {s[0], s[1], s[2]},
        {s[0], s[1], s[3]},
        {s[0], s[2], s[3]},
        {s[1], s[2], s[3]}
    };

    for (int i = 0; i < 4; ++i) {
        int res = check(combos[i][0], combos[i][1], combos[i][2]);
        if (res == 1) triangle = true;
        else if (res == 0) segment = true;
    }

    if (triangle) {
        cout << "TRIANGLE" << endl;
    } else if (segment) {
        cout << "SEGMENT" << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}
