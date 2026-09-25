/*
=========================================================
Date        : 25-09-2026
Problem Name: 1481B - New Colony
Platform    : Codeforces
Difficulty  : 1100
Tags        : brute force, greedy, implementation

Problem Summary:
We are given an array representing mountain heights and k boulders thrown one by one.
A boulder rolls to the right as long as the current mountain is higher than or equal to the next; 
when it encounters a strictly higher next mountain, it stops and increases the current mountain's height by 1.
If a boulder rolls off the last mountain, it falls into the waste collection system. Find where the k-th boulder stops or output -1.

Key Observation:
Since n <= 100 and heights <= 100, at most n * max(h) <= 10,000 boulders can ever stop before all mountains become non-increasing.
Any boulder beyond ~10,000 will inevitably fall into the waste system, allowing direct simulation.
=========================================================
*/

/*
---------------------------------------------------------
APPROACH 1: Direct Simulation with Early Pruning
---------------------------------------------------------
• Intuition:
  The maximum total height increments across all mountains before no boulder can stop is bounded by n * max(h) <= 100 * 100 = 10,000.
  If k exceeds this bound, the k-th boulder definitely falls into the waste system.

• Approach:
  - If k > 100 * 100, directly output -1.
  - Otherwise, simulate each boulder one by one starting from index 1.
  - Advance while h[i] >= h[i+1]. If it reaches the end, it falls off (output -1 for this and all future boulders).
  - If h[i] < h[i+1], stop the boulder, increment h[i] by 1, and record index i.
  - Return the position where the k-th boulder stops.

• Why it Works:
  The bounds on n and h_i are tiny (<= 100). The simulation takes at most min(k, 10000) * n operations, which is well within the 2.0s time limit.

• Time Complexity (TC):
  O(min(k, n * max_h) * n) per testcase -> at most ~10^6 operations total across all test cases.

• Space Complexity (SC):
  O(n) auxiliary space to store mountain heights.
---------------------------------------------------------
*/

/*
---------------------------------------------------------
FINAL APPROACH:
• This approach is chosen because n <= 100 and h_i <= 100 make direct simulation trivial and clean.
• It avoids overcomplicating with interval tracking or segment trees, providing optimal simplicity and robust performance well within limits.
---------------------------------------------------------
*/

#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    long long k;
    cin >> n >> k;

    vector<int> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }

    // Since n <= 100 and h_i <= 100, total capacity is at most 100 * 100 = 10000.
    // If k exceeds this threshold, the boulder definitely falls into the waste system.
    if (k > 10000) {
        cout << -1 << "\n";
        return;
    }

    int last_pos = -1;
    for (int b = 0; b < k; ++b) {
        int pos = 0;
        while (pos < n - 1 && h[pos] >= h[pos + 1]) {
            pos++;
        }

        // Boulder fell into the collection system
        if (pos == n - 1) {
            cout << -1 << "\n";
            return;
        }

        // Boulder stopped at pos (1-indexed: pos + 1)
        h[pos]++;
        last_pos = pos + 1;
    }

    cout << last_pos << "\n";
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
