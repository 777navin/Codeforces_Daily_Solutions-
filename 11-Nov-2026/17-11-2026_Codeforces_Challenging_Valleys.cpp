/*
=========================================================
Date        : 17-11-2026
Problem Name: D. Challenging Valleys
Platform    : Codeforces
Difficulty  : 1000
Tags        : Implementation, Two Pointers

Problem Summary:
Given an array a of length n, determine if it is a "valley".
A valley has exactly one contiguous equal-element subarray a[l...r]
strictly bounded by larger elements on both ends (or array boundaries).

Key Observation:
Consecutive duplicate elements act as a single plateau; compressing them
leaves an array that must be strictly non-increasing then strictly non-decreasing (no local peaks).
=========================================================
*/

/*
---------------------------------------------------------
1. Brute Force (Check Every Subarray)
---------------------------------------------------------
• Intuition:
  Directly test every possible subarray [l, r] against the four given valley conditions.
• Approach:
  Iterate over all pairs (l, r) with 0 <= l <= r < n. Verify all elements inside are equal
  and check if boundary conditions hold; count valid subarrays and check if count == 1.
• Why it Works:
  Exhaustively evaluates the exact problem definition without missing any edge cases.
• Time Complexity (TC): O(N^3) per test case (TLE for N <= 2 * 10^5).
• Space Complexity (SC): O(1) auxiliary space.

---------------------------------------------------------
2. Better (Two Pointers / Grouping Equal Blocks)
---------------------------------------------------------
• Intuition:
  A valid subarray must be a maximal contiguous block of identical elements.
• Approach:
  Group consecutive identical elements using two pointers [l, r]. For each maximal block,
  check if (l == 0 || a[l - 1] > a[l]) and (r == n - 1 || a[r] < a[r + 1]).
• Why it Works:
  Any non-maximal equal subarray fails the boundary strict inequality on at least one side,
  so only maximal blocks can be valleys.
• Time Complexity (TC): O(N) per test case.
• Space Complexity (SC): O(1) auxiliary space.

---------------------------------------------------------
3. Most Optimal (Adjacent Consecutive Compression / Slope Check)
---------------------------------------------------------
• Intuition:
  If we remove consecutive duplicates, a valley cannot have any local maximum (an element
  strictly greater than both neighbors) and can never rise then fall.
• Approach:
  Compress consecutive equal elements on the fly (or into a vector). Track if the sequence
  has started increasing; if it decreases after increasing, it forms a peak (two valleys).
• Why it Works:
  Compressing equal elements turns plateaus into single points. A single valley means the
  sequence goes down (optional) and then up (optional), never up then down.
• Time Complexity (TC): O(N) per test case.
• Space Complexity (SC): O(N) if storing compressed array, or O(1) on the fly.
---------------------------------------------------------
*/

/*
=========================================================
FINAL APPROACH:
We use the Two Pointers / Maximal Equal Block approach.
It runs in linear O(N) time with O(1) extra space, avoids allocating
a compressed array, and directly mirrors the problem's boundary conditions.
=========================================================
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int valley_count = 0;
    int l = 0;

    while (l < n) {
        int r = l;
        // Expand r to cover the entire contiguous block of equal elements
        while (r + 1 < n && a[r + 1] == a[l]) {
            ++r;
        }

        // Check left and right valley conditions
        bool left_ok = (l == 0) || (a[l - 1] > a[l]);
        bool right_ok = (r == n - 1) || (a[r] < a[r + 1]);

        if (left_ok && right_ok) {
            ++valley_count;
        }

        // Move to the start of the next distinct block
        l = r + 1;
    }

    cout << (valley_count == 1 ? "YES\n" : "NO\n");
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
