/*
=========================================================
Date        : 23-08-2026
Problem Name: Appleman and Toastman (461A)
Platform    : Codeforces
Difficulty  : 1200
Tags        : Greedy, Sorting, Math

Problem Summary:
Given an array of n integers, we repeatedly sum groups and split them.
Toastman adds the sum of any received group to the total score.
Appleman splits groups of size > 1 into two non-empty subsets and discards singletons.
Find the maximum possible total score achievable.

Key Observation:
In an optimal splitting strategy, smaller elements are separated first.
The element at sorted index i (0-based) contributes to (i + 2) sums, except the largest element which contributes n times.
=========================================================
*/

/*
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
APPROACH EXPLANATION
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

1. Greedy with Sorting (Optimal Approach)
• Intuition:
  - To maximize the sum, elements that are split later appear in more group sums.
  - Larger elements should participate in as many operations as possible.
• Approach:
  - Sort the array in non-decreasing order: a[0] <= a[1] <= ... <= a[n-1].
  - Element a[i] contributes (i + 2) times for 0 <= i < n - 1, and a[n-1] contributes n times (or for n=1, exactly 1 time).
  - Equivalently, for n > 1, element a[i] contributes min(n, i + 2) times.
• Why it Works:
  - Splitting off the smallest available single element at each step leaves the remaining largest elements together to be summed again.
• Time Complexity (TC):
  - O(n log n) due to sorting.
• Space Complexity (SC):
  - O(1) auxiliary space (ignoring input storage).
*/

/*
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
FINAL APPROACH
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
• Chosen Approach: Greedy with Sorting.
• Why Chosen:
  - Sorting takes O(n log n), which easily runs within the 2.0-second time limit for n = 3 * 10^5.
  - Simple, robust, and directly computes the maximum possible sum using 64-bit integers.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    if (n == 1) {
        cout << a[0] << "\n";
        return;
    }

    sort(a.begin(), a.end());

    long long total_score = 0;
    for (int i = 0; i < n; ++i) {
        if (i == n - 1) {
            total_score += a[i] * n;
        } else {
            total_score += a[i] * (i + 2);
        }
    }

    cout << total_score << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
