/*
=========================================================
Date        : 07-09-2026
Problem Name: George and Round (387B)
Platform    : Codeforces
Difficulty  : 1200
Tags        : greedy, two pointers, sortings

Problem Summary:
George needs to prepare a contest with at least n problems having specific 
complexities a[1] <= a[2] <= ... <= a[n]. He already has m problems with 
complexities b[1] <= b[2] <= ... <= b[m], and he can simplify any problem 
(decrease its complexity) to match a required complexity. Find the minimum 
number of new problems he must invent from scratch.

Key Observation:
A prepared problem with complexity b[j] can satisfy a required complexity a[i] 
if and only if b[j] >= a[i]. Greedily matching the smallest possible valid b[j] 
to each a[i] maximizes the number of requirements satisfied.
=========================================================
*/

/*
---------------------------------------------------------
APPROACH 1: Greedy with Two Pointers (Most Optimal)
---------------------------------------------------------
• Intuition:
  Both arrays are already sorted in non-decreasing order. To satisfy as many 
  required problems as possible, we should match the smallest available prepared 
  problem b[j] that is at least a[i].

• Approach:
  - Maintain a pointer `i` for array `a` and a pointer `j` for array `b`.
  - Iterate `j` from 0 to m - 1: if b[j] >= a[i], it means prepared problem `j` 
    can satisfy requirement `i`, so increment `i`.
  - The number of satisfied requirements is `i`. The remaining `n - i` requirements 
    must be created from scratch.

• Why it Works:
  - Matching the smallest valid prepared problem preserves larger prepared problems 
    for larger required complexities.
  - Any valid matching can be transformed into this greedy matching without reducing 
    the total count of satisfied requirements.

• Time Complexity (TC): O(n + m) — Single pass over both sorted arrays.
• Space Complexity (SC): O(1) auxiliary space beyond storing the input arrays.
---------------------------------------------------------
*/

/*
---------------------------------------------------------
FINAL APPROACH SELECTION:
---------------------------------------------------------
We choose the Greedy Two-Pointer approach because the input arrays are already 
given in sorted order. It operates in optimal linear time O(n + m) and minimal 
memory O(1) auxiliary space, making it both optimal and straightforward to implement.
---------------------------------------------------------
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Optimize standard I/O operations for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> b(m);
    for (int j = 0; j < m; ++j) {
        cin >> b[j];
    }

    int i = 0; // Pointer for required difficulties `a`
    for (int j = 0; j < m && i < n; ++j) {
        // If prepared problem b[j] can cover requirement a[i]
        if (b[j] >= a[i]) {
            ++i;
        }
    }

    // Remaining required problems that need to be created from scratch
    cout << (n - i) << "\n";

    return 0;
}
