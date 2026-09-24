/*
=========================================================
Date        : 24-09-2026
Problem Name: C. Letters
Platform    : Codeforces
Difficulty  : 1000
Tags        : binary search, implementation, two pointers

Problem Summary:
There are n dormitories, each having a_i rooms numbered sequentially across all dorms.
Given m letters with cumulative room numbers b_j in strictly non-decreasing order,
find the dormitory number and the relative room number within that dormitory for each letter.

Key Observation:
Since the queries b_j are already given in sorted order, we can either use two pointers
to march through the dormitories or binary search (std::lower_bound) on prefix sums.
=========================================================
*/

/*
---------------------------------------------------------
APPROACH 1: Binary Search on Prefix Sums
---------------------------------------------------------
• Intuition:
  Compute prefix sums of room capacities. For each query b_j, the first dormitory
  whose cumulative rooms >= b_j is the target dormitory.

• Approach:
  1. Build prefix sum array pref where pref[i] = pref[i - 1] + a[i].
  2. For each query b_j, use std::lower_bound on pref to find dormitory index i.
  3. The relative room number is b_j - pref[i - 1].

• Why it Works:
  Prefix sums are strictly monotonically increasing, allowing binary search in O(log n).

• Time Complexity (TC): O(n + m log n)
• Space Complexity (SC): O(n) for prefix sums array.
---------------------------------------------------------
APPROACH 2: Two Pointers (Linear Sweep) - Most Optimal
---------------------------------------------------------
• Intuition:
  Since the letter queries b_j are guaranteed to be sorted in increasing order,
  the target dormitory index only moves forward as we process each query.

• Approach:
  1. Maintain a pointer `dorm` representing the current dormitory and track `sum_prev`
     (total rooms in all dormitories before `dorm`).
  2. For each query b_j, advance `dorm` and add a[dorm] to cumulative sum until
     the letter falls within dormitory `dorm`.
  3. Print `dorm` and the relative room index `b_j - sum_prev`.

• Why it Works:
  Both the queries and dormitory indices advance monotonically, visiting each dormitory at most once.

• Time Complexity (TC): O(n + m)
• Space Complexity (SC): O(n) to store room counts (or O(1) auxiliary space).
---------------------------------------------------------
FINAL APPROACH:
The Two Pointers approach is chosen because it takes full advantage of the fact that
letter indices are already sorted. It achieves linear O(n + m) time complexity, eliminating
the logarithmic factor of binary search and running significantly faster within time limits.
---------------------------------------------------------
*/

#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int dorm = 0;
    long long sum_prev = 0; // Total rooms in dormitories 0 to dorm - 1

    for (int j = 0; j < m; ++j) {
        long long b;
        cin >> b;

        // Advance dormitory pointer until the room falls within the current dormitory
        while (b > sum_prev + a[dorm]) {
            sum_prev += a[dorm];
            dorm++;
        }

        // dorm is 0-indexed, output 1-indexed dormitory number and room inside it
        long long room_num = b - sum_prev;
        cout << (dorm + 1) << " " << room_num << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
