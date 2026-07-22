/*
=========================================================
Date        : 22-07-2026
Problem Name: C. Less or Equal
Platform    : Codeforces
Difficulty  : 1200
Tags        : Sorting, Implementation

Problem Summary:
Given an array of n integers and a number k, find any integer x in the range [1, 10^9]
such that exactly k elements in the sequence are less than or equal to x.
If no such integer x exists, print -1.

Key Observation:
Sorting the array simplifies the problem: after sorting, the k-th smallest element (1-indexed)
is a candidate for x, provided the (k+1)-th element is strictly greater than it.
=========================================================
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
=========================================================
APPROACH 1: Sorting + Boundary Checking (Optimal)
=========================================================

• Intuition:
  If we sort the sequence in non-decreasing order, the first k elements will be 
  a[0], a[1], ..., a[k-1]. To have exactly k elements <= x, x must be at least 
  a[k-1] and strictly less than a[k] (if a[k] exists).

• Approach:
  1. Sort the given array `a` of size n.
  2. Case k = 0: 
     - If a[0] > 1, we can pick x = 1 (since 1 < a[0], 0 elements are <= 1).
     - If a[0] == 1, no x in range [1, 10^9] exists, so output -1.
  3. Case k > 0:
     - Set candidate x = a[k-1].
     - If k < n and a[k-1] == a[k], then choosing x = a[k-1] would make at least 
       (k+1) elements <= x. In this case, output -1.
     - Otherwise, x = a[k-1] is a valid answer.

• Why it Works:
  Sorting groups equal elements together and gives direct access to element counts.
  Checking the boundary element a[k] ensures no extra elements become <= x.

• Time Complexity (TC) : O(n log n) due to sorting the array.
• Space Complexity (SC): O(1) auxiliary space (excluding input array storage).
=========================================================
*/

/*
=========================================================
FINAL APPROACH CHOICE
=========================================================
This Sorting + Boundary Checking approach is chosen because sorting the array 
takes O(n log n), which comfortably passes within the 2.0-second time limit 
for n = 2 * 10^5. It handles edge cases (like k = 0 or duplicate values at index k) 
cleanly and directly.
=========================================================
*/

void solve() {
    int n, k;
    if (!(cin >> n >> k)) return;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Sort the array in non-decreasing order
    sort(a.begin(), a.end());

    int ans = -1;

    if (k == 0) {
        // We need 0 elements <= x. Since x >= 1, if the smallest element
        // is strictly greater than 1, x = 1 works.
        if (a[0] > 1) {
            ans = 1;
        } else {
            ans = -1;
        }
    } else {
        // For k > 0, candidate x is a[k-1].
        // Check if the next element is equal to a[k-1].
        if (k < n && a[k - 1] == a[k]) {
            ans = -1;
        } else {
            ans = a[k - 1];
        }
    }

    cout << ans << "\n";
}

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
