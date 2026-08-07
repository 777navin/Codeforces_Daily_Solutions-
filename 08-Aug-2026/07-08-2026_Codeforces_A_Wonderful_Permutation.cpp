/*
=========================================================
Date        : 07-08-2026
Problem Name: A. Wonderful Permutation
Platform    : Codeforces
Difficulty  : 800 (Easy)
Tags        : Greedy, Implementation

Problem Summary:
Given a permutation of length n and an integer k, we need to find the minimum
number of swap operations required to minimize the sum of the first k elements.
Since a permutation contains distinct integers from 1 to n, the minimum possible
sum of any k elements is the sum of integers from 1 to k.

Key Observation:
To minimize the sum of the first k elements, the prefix of length k must contain
all integers from 1 to k. The minimum number of swaps equals the number of elements
in the first k positions that are strictly greater than k.
=========================================================
*/

#include <iostream>
#include <vector>

using namespace std;

/*
---------------------------------------------------------
APPROACH 1: Optimal Greedy Counting
---------------------------------------------------------

Intuition:
• To make the sum p_1 + p_2 + ... + p_k as small as possible, the first k elements
  must be the k smallest integers available in the permutation, which are {1, 2, ..., k}.
• Any integer strictly greater than k currently located in the first k positions needs
  to be swapped out for an integer <= k located in the remaining positions (k+1 to n).

Approach:
• Iterate through the first k elements of the given permutation.
• Count how many elements p_i satisfy p_i > k.
• Each such element requires exactly 1 swap operation to be replaced by a missing
  element <= k from the suffix.

Why it Works:
• Every element > k in the prefix corresponds to a missing element <= k in the prefix.
• One swap can simultaneously place one element <= k into the prefix and move one
  element > k out to the suffix.
• Therefore, the minimum number of swaps is exactly the count of elements > k in
  the first k indices.

Time Complexity (TC) : O(k) per testcase, which is O(n) overall.
Space Complexity (SC): O(n) to store the input array (or O(1) auxiliary space).
---------------------------------------------------------
*/

/*
---------------------------------------------------------
FINAL APPROACH SELECTION:
---------------------------------------------------------
• Optimal Greedy Counting is chosen because it directly identifies the necessary
  swaps without physically simulating any array operations.
• It runs in linear time O(n) and minimal space, making it optimal and well within
  the 1.0-second time limit for n, k <= 100.
---------------------------------------------------------
*/

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> p(n);
    int ops = 0;

    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        if (i < k && p[i] > k) {
            ops++;
        }
    }

    cout << ops << "\n";
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
