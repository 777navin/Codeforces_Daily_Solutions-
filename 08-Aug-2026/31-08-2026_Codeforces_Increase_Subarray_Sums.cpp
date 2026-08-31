/*
=========================================================
Date        : 31-08-2026
Problem Name: Increase Subarray Sums (1644C)
Platform    : Codeforces
Difficulty  : 1400
Tags        : dp, greedy, brute force, implementation

Problem Summary:
Given an array of n integers and a value x, calculate f(k) for each k from 0 to n.
f(k) is the maximum possible sum of a contiguous subarray after adding x to 
at most k distinct elements. An empty subarray has a sum of 0.

Key Observation:
If we choose a subarray of length len, we can add at most min(k, len) * x to its sum.
Thus, we only need to precompute the maximum subarray sum for each length len in [1, n].
=========================================================
*/

/*
---------------------------------------------------------
APPROACH 1: Brute Force / Direct Prefix Sums
---------------------------------------------------------
• Intuition:
  Compute the maximum subarray sum for all lengths from 1 to n using prefix sums, 
  then for each k, evaluate all possible lengths len.

• Approach:
  1. Compute prefix sums of the array a.
  2. For each length len from 1 to n, find max_sum[len] = max(prefix[i + len] - prefix[i]).
  3. For each k from 0 to n:
     ans = 0 (representing the empty subarray)
     ans = max(ans, max_sum[len] + min(k, len) * x) for all len from 1 to n.
  4. Print ans for each k.

• Why it Works:
  Adding x to k elements will greedily contribute min(k, len) * x to any subarray of length len.
  Since n <= 5000 and sum of n <= 5000, an O(n^2) approach easily passes within the 2.0s time limit.

• Time Complexity (TC): O(n^2) per testcase, O(sum(n^2)) overall.
• Space Complexity (SC): O(n) auxiliary space for prefix sums and max_sum array.
---------------------------------------------------------
*/

/*
---------------------------------------------------------
FINAL APPROACH SELECTION
---------------------------------------------------------
• Chosen Approach: O(n^2) Length-based Precomputation (Approach 1).
• Reason: With sum of n <= 5000, O(n^2) requires at most ~2.5 * 10^7 operations, 
  which runs well under the 2-second time limit with minimal overhead and optimal memory usage.
---------------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long INF = 1e18;

void solve() {
    int n;
    long long x;
    cin >> n >> x;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // max_sum[len] stores the maximum subarray sum of length len
    vector<long long> max_sum(n + 1, -INF);
    max_sum[0] = 0;

    for (int l = 0; l < n; ++l) {
        long long current_sum = 0;
        for (int r = l; r < n; ++r) {
            current_sum += a[r];
            int len = r - l + 1;
            max_sum[len] = max(max_sum[len], current_sum);
        }
    }

    // For each k from 0 to n, find the maximum sum across all subarray lengths
    for (int k = 0; k <= n; ++k) {
        long long ans = 0; // Empty subarray sum
        for (int len = 1; len <= n; ++len) {
            ans = max(ans, max_sum[len] + min((long long)k, (long long)len) * x);
        }
        cout << ans << (k == n ? "" : " ");
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
