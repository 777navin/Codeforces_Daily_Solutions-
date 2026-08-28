/*
=========================================================
Date        : 28-08-2026
Problem Name: Random Events (1461C)
Platform    : Codeforces
Difficulty  : 1500
Tags        : dp, math, probabilities, greedy, data structures

Problem Summary:
Given an array permutation of length n and m experiments (r_i, p_i).
Each experiment independently sorts the prefix [1, r_i] with probability p_i.
Find the probability that the array is completely sorted in ascending order after all m operations.

Key Observation:
Only the operations with prefix length r_i >= last unsorted index can fix the array.
The probability of staying unsorted is the product of failure probabilities (1 - p_i) of all applicable operations.
=========================================================
*/

/*
=========================================================
APPROACH 1: Greedy Probability Calculation
=========================================================

• Intuition:
  - Find the 1-based index `last_idx` of the rightmost element such that `a[i] != i`.
  - If the array is already sorted (`last_idx == 0`), the probability is 1.0.
  - Any operation with `r_i < last_idx` will never sort the full array to completion.
  - Any operation with `r_i >= last_idx` will successfully sort the entire array if it succeeds.

• Approach:
  - Find the highest index `k` where `a[k] != k`.
  - If no such index exists, the answer is 1.0.
  - Initialize failure probability `prob_fail = 1.0`.
  - For every experiment `(r, p)`: if `r >= k`, update `prob_fail *= (1.0 - p)`.
  - The final answer is `1.0 - prob_fail`.

• Why it Works:
  - Since operations are independent, the array remains unsorted if and only if EVERY operation capable of sorting the suffix (`r >= k`) fails.
  - Multiplying `(1 - p)` across all valid operations gives the probability that none of the valid operations succeed.

• Time Complexity (TC):
  - O(N + M) per test case: O(N) to find the rightmost misplaced element and O(M) to process queries.
  - Total Time: O(sum(N + M)) <= O(10^5).

• Space Complexity (SC):
  - O(N) auxiliary space to store the permutation.
=========================================================
*/

/*
=========================================================
FINAL APPROACH:
Chosen because O(N + M) is optimal, simple, and handles precision without requiring complex DP states.
=========================================================
*/

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    // Find the rightmost index where the element is out of place
    int last_idx = 0;
    for (int i = n; i >= 1; --i) {
        if (a[i] != i) {
            last_idx = i;
            break;
        }
    }

    double prob_fail = 1.0;
    for (int i = 0; i < m; ++i) {
        int r;
        double p;
        cin >> r >> p;
        if (r >= last_idx) {
            prob_fail *= (1.0 - p);
        }
    }

    if (last_idx == 0) {
        cout << fixed << setprecision(6) << 1.0 << "\n";
    } else {
        cout << fixed << setprecision(6) << (1.0 - prob_fail) << "\n";
    }
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
