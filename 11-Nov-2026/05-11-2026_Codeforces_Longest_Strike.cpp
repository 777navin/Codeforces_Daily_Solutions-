
/*
=========================================================
Date        : 05-11-2026
Problem Name: F. Longest Strike
Platform    : Codeforces (1676F)
Difficulty  : 1300
Tags        : Greedy, Sorting, Two Pointers, Implementation

Problem Summary:
Given an array and integer k, find the longest consecutive
integer range [l, r] where every integer occurs at least
k times in the array.

Key Observation:
After sorting, count frequencies of distinct elements.
A valid range consists of consecutive values whose
frequencies are all at least k.
=========================================================

APPROACH 1: Brute Force

- Intuition:
  Check every possible range of integers.

- Approach:
  Count frequencies and test every possible [l, r].

- Why it Works:
  Every possible valid range is considered.

- Time Complexity: O(M^2), where M is the value range.
- Space Complexity: O(M).

APPROACH 2: Sorting + Greedy (OPTIMIZED)

- Intuition:
  Only numbers appearing at least k times can be included.

- Approach:
  Sort the array and count frequencies.
  Traverse distinct values and maintain consecutive
  valid numbers. Reset whenever a gap occurs.

- Why it Works:
  Every valid answer must contain only consecutive
  integers with frequency at least k.
  Keeping the longest such segment maximizes r - l.

- Time Complexity: O(N log N).
- Space Complexity: O(N).

FINAL APPROACH:
Use sorting + greedy traversal.
It avoids checking every possible range and processes
each distinct value only once after sorting.
*/

// FINAL CODE

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);

    for (int &x : a) {
        cin >> x;
    }

    sort(a.begin(), a.end());

    int bestL = -1, bestR = -1;
    int currentL = -1;
    int previous = -2;

    for (int i = 0; i < n; ) {
        int j = i;

        // Count frequency of current value.
        while (j < n && a[j] == a[i]) {
            j++;
        }

        int value = a[i];
        int frequency = j - i;

        if (frequency >= k) {

            // Start a new consecutive segment.
            if (currentL == -1 || value != previous + 1) {
                currentL = value;
            }

            previous = value;

            // Update the longest valid segment.
            if (bestL == -1 ||
                value - currentL > bestR - bestL) {
                bestL = currentL;
                bestR = value;
            }

        } else {
            // Invalid value breaks the segment.
            currentL = -1;
            previous = -2;
        }

        i = j;
    }

    if (bestL == -1) {
        cout << -1 << '\n';
    } else {
        cout << bestL << " " << bestR << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}

/*
=========================================================
Complexity:
Time  : O(N log N) per test case
Space : O(N)

=========================================================
*/
