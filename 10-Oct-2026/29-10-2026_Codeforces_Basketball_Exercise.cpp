/*
=========================================================
Date        : 29-10-2026
Problem Name: Basketball Exercise
Platform    : Codeforces
Difficulty  : 1400
Tags        : Dynamic Programming, Greedy, Arrays

Problem Summary:
- Two rows contain n students, each with a given height.
- Choose students in increasing column order.
- Consecutive chosen students must belong to different rows.
- Maximize the total height of the selected students.

Key Observation:
- If we select a student from one row at column i, the
  previous selected student must be from the other row
  at an earlier column.
- Dynamic programming efficiently tracks both possibilities.
=========================================================

APPROACH 1: Brute Force
- Intuition: Try every possible valid selection of students.
- Approach: Enumerate all possible subsets and find the maximum sum.
- Why it Works: Every valid team is considered.
- TC: Exponential, O(2^(2n)).
- SC: O(n) recursion stack.

APPROACH 2: Dynamic Programming with Two States
- Intuition: The last selected student determines the state.
- Approach:
  Let dpTop[i] be the maximum sum when selecting the top
  student at column i.
  Let dpBottom[i] be the maximum sum when selecting the
  bottom student at column i.

  dpTop[i] = top[i] + max(dpBottom[j]) for every j < i.
  dpBottom[i] = bottom[i] + max(dpTop[j]) for every j < i.

- Why it Works: The previous selected student must be from
  the opposite row, and its column must be smaller.
- TC: O(n^2).
- SC: O(n).

APPROACH 3: Most Optimal DP
- Intuition: Maintain the best answer for each row's prefix.
- Approach:
  prevTop and prevBottom represent the best sums ending
  in the respective rows before the current column.
  Use the previous opposite-row state and skip columns
  when beneficial.
- Why it Works: Every valid selection is represented by
  one of the two DP states.
- TC: O(n).
- SC: O(1) auxiliary DP space.

FINAL APPROACH:
- Use the standard two-row dynamic programming recurrence.
- At each column, either select the top or bottom student,
  or skip the column.
- Keep only the previous column's best states.
- Use long long because the maximum sum can reach 10^14.
=========================================================
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<ll> top(n), bottom(n);

    for (int i = 0; i < n; ++i) {
        cin >> top[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> bottom[i];
    }

    ll prevTop = 0;
    ll prevBottom = 0;
    ll prevPrevTop = 0;
    ll prevPrevBottom = 0;

    for (int i = 0; i < n; ++i) {
        ll currentTop = top[i] +
            max(prevBottom, prevPrevBottom);

        ll currentBottom = bottom[i] +
            max(prevTop, prevPrevTop);

        prevPrevTop = prevTop;
        prevPrevBottom = prevBottom;

        prevTop = currentTop;
        prevBottom = currentBottom;
    }

    cout << max(prevTop, prevBottom) << '\n';

    return 0;
}
