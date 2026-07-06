/*
=========================================================
Date        : 06-07-2026
Problem Name: A. Game
Platform    : Codeforces
Difficulty  : 800
Tags        : Sorting, Greedy, Games

Problem Summary:
Two players remove numbers from a list of n integers until only one remains. 
Player 1 wants to minimize the final number, and Player 2 wants to maximize it. 
They alternate turns, with Player 1 moving first.

Key Observation:
Since players play optimally to minimize/maximize the result, the best strategy is for each 
player to remove the most disadvantageous numbers for their goal. Sorting the array 
allows us to see that the middle element(s) will be the final result.
=========================================================

APPROACH:
1. Optimal Strategy
   - Sort the array of numbers in non-decreasing order.
   - Player 1 (minimizer) will always remove the largest available number.
   - Player 2 (maximizer) will always remove the smallest available number.
   - This process effectively eliminates the extreme values from both ends.
   - After n-1 moves, the remaining element is the median-positioned element in the sorted list.
   - Specifically, the result is at index (n-1)/2 in a 0-indexed sorted array.

   Time Complexity (TC): O(N log N) due to sorting.
   Space Complexity (SC): O(1) if sorting in place, or O(N) depending on storage.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Why this approach is chosen:
 * Sorting allows us to simulate the optimal behavior of both players efficiently. 
 * Since Player 1 and Player 2 take turns removing numbers from opposite ends 
 * of the sorted spectrum, we can mathematically determine the final remaining 
 * number without needing to simulate the actual turns.
 */

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Sort the numbers to easily remove extremes
    sort(a.begin(), a.end());

    // After (n-1) turns, the number left is at index (n-1) / 2
    // Example: n=3, (3-1)/2 = index 1 (the median)
    cout << a[(n - 1) / 2] << endl;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
