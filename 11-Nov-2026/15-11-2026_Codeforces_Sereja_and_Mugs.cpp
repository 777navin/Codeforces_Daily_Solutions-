/*
=========================================================
Date        : 15-11-2026
Problem Name: A. Sereja and Mugs
Platform    : Codeforces
Difficulty  : 800
Tags        : Greedy, Implementation, Math

Problem Summary:
There are n mugs with given water volumes and an empty cup of capacity s.
Sereja has (n - 1) friends who take turns pouring one mug each into the cup.
Determine if all (n - 1) friends can pour their mugs without overflowing the cup.

Key Observation:
Since (n - 1) friends play and there are n mugs, exactly one mug will remain unpoured.
To minimize the total water poured, the friends should leave out the largest mug.
=========================================================
*/

/*
---------------------------------------------------------
Approach 1: Sorting (Better)
---------------------------------------------------------
• Intuition:
  To prevent the cup from overflowing, we should pour the (n - 1) smallest mugs and leave the largest one untouched.

• Approach:
  1. Read n, s, and the array of n mug volumes.
  2. Sort the array of mug volumes in ascending order.
  3. Sum the first (n - 1) elements and check if the total is <= s.

• Why it Works:
  Sorting guarantees that the largest element is at the last index, so summing the rest yields the minimum possible water poured.

• Time Complexity (TC): O(n log n) due to sorting.
• Space Complexity (SC): O(n) to store the mug volumes.

---------------------------------------------------------
Approach 2: Single Pass Sum & Max (Most Optimal)
---------------------------------------------------------
• Intuition:
  We don't need the full sorted order; we only need the sum of all mugs minus the single largest mug.

• Approach:
  1. Read n and s.
  2. Iterate through all n mug volumes, maintaining the total sum and the maximum volume seen so far.
  3. Check if (total_sum - max_volume) <= s.

• Why it Works:
  Subtracting the maximum element from the total sum directly computes the sum of the (n - 1) smallest elements in linear time.

• Time Complexity (TC): O(n) for a single pass over the input.
• Space Complexity (SC): O(1) auxiliary space without needing an array.
---------------------------------------------------------
*/

/*
---------------------------------------------------------
Final Approach Selection:
---------------------------------------------------------
Approach 2 (Single Pass Sum & Max) is chosen because it achieves optimal O(n) time and O(1) auxiliary space.
It eliminates the O(n log n) sorting overhead and avoids storing the entire array in memory.
---------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, s;
    if (!(cin >> n >> s)) return;

    int total_sum = 0;
    int max_mug = 0;

    for (int i = 0; i < n; ++i) {
        int volume;
        cin >> volume;
        total_sum += volume;
        max_mug = max(max_mug, volume);
    }

    // Check if the sum of the smallest (n - 1) mugs fits in the cup
    if (total_sum - max_mug <= s) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
