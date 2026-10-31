
/*
=========================================================
Date        : 31-10-2026
Problem Name: Permutations
Platform    : Codeforces (124B)
Difficulty  : 1400
Tags        : Brute Force, Combinatorics, Implementation

Problem Summary:
Given n numbers, each containing k digits.
Rearrange digit positions using the same permutation
for every number to minimize maximum - minimum.

Key Observation:
Since k <= 8, we can try all k! permutations
and calculate the difference for each permutation.
=========================================================

APPROACH 1: Brute Force

- Intuition:
  Try every possible ordering of digit positions.

- Approach:
  Generate all permutations using next_permutation.
  Transform every number using the current permutation.
  Find the maximum and minimum transformed values.

- Why it Works:
  Every possible rearrangement of digit positions
  is examined, so the minimum difference is guaranteed.

- Time Complexity (TC):
  O(k! * n * k)

- Space Complexity (SC):
  O(n * k)

FINAL APPROACH:
Use permutation generation with next_permutation.
Since k <= 8, at most 40320 permutations exist.
This is efficient and guarantees the optimal answer.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<string> numbers(n);

    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    vector<int> p(k);
    iota(p.begin(), p.end(), 0);

    int answer = INT_MAX;

    do {
        int minimumValue = INT_MAX;
        int maximumValue = INT_MIN;

        for (const string& number : numbers) {
            int currentValue = 0;

            for (int position : p) {
                currentValue = currentValue * 10
                             + (number[position] - '0');
            }

            minimumValue = min(minimumValue, currentValue);
            maximumValue = max(maximumValue, currentValue);
        }

        answer = min(answer, maximumValue - minimumValue);

    } while (next_permutation(p.begin(), p.end()));

    cout << answer << '\n';

    return 0;
}
