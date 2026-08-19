/*
=========================================================
Date        : 19-08-2026
Problem Name: Napoleon Cake (1501B)
Platform    : Codeforces
Difficulty  : 900
Tags        : dp, greedy, implementation, sortings, data structures

Problem Summary:
Arkady builds an n-layer cake sequentially. After placing layer i, he pours a[i] 
units of cream on top, drenching the top a[i] layers currently in the stack. 
We need to determine which layers (1 to n) are drenched in cream at the end.

Key Observation:
Pouring cream at layer i affects layers from max(1, i - a[i] + 1) to i. 
Traversing backwards from layer n down to 1 allows us to maintain the maximum 
remaining cream coverage greedily in a single pass.
=========================================================
*/

/*
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
APPROACH 1: Difference Array (Range Update & Prefix Sums)
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
• Intuition:
  Each pour at index i is a range update [max(1, i - a[i] + 1), i] adding 1.

• Approach:
  - Maintain a difference array diff of size n + 2.
  - For each i, increment diff[max(1, i - a[i] + 1)] and decrement diff[i + 1].
  - Compute prefix sums; if prefix_sum[i] > 0, layer i is drenched.

• Why it Works:
  Standard range update technique that aggregates intervals into point values.

• Time Complexity (TC): O(n) per test case
• Space Complexity (SC): O(n) auxiliary space for difference array

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
APPROACH 2: Backward Greedy Traversal (Optimal & Space-Efficient)
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
• Intuition:
  A layer i requires coverage if either it was poured on directly (a[i] > 0) 
  or a layer above it (j > i) had enough cream to reach down past i.

• Approach:
  - Traverse the array from right to left (i = n - 1 down to 0).
  - Maintain cream = max(cream, a[i]).
  - If cream > 0, mark layer i as 1 and decrement cream; otherwise mark as 0.

• Why it Works:
  Cream flows downwards only. Working backwards guarantees we know the exact 
  maximum reach of all subsequent pours without needing extra prefix structures.

• Time Complexity (TC): O(n) per test case
• Space Complexity (SC): O(1) auxiliary space (excluding the output array)
*/

/*
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
FINAL APPROACH: Backward Greedy Traversal
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
• Why this approach is chosen:
  - It runs in a single clean pass without requiring secondary difference arrays.
  - It minimizes memory overhead and provides optimal runtime performance for competitive programming.
  - The logic is concise, highly cache-friendly, and eliminates off-by-one errors common in range updates.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    vector<int> result(n, 0);
    int cream = 0;
    
    for (int i = n - 1; i >= 0; --i) {
        cream = max(cream, a[i]);
        if (cream > 0) {
            result[i] = 1;
            cream--;
        } else {
            result[i] = 0;
        }
    }
    
    for (int i = 0; i < n; ++i) {
        cout << result[i] << (i + 1 == n ? "" : " ");
    }
    cout << "\n";
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
