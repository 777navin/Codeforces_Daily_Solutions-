/*
=========================================================
Date        : 02-10-2026
Problem Name: Kefa and Company
Platform    : Codeforces
Difficulty  : 1500 (Medium-Easy)
Tags        : Two Pointers, Sorting, Binary Search, Sliding Window

Problem Summary:
Kefa wants to invite a group of friends to a restaurant such that the total 
friendship factor is maximized. However, no two invited friends can have a difference 
in their money amounts greater than or equal to d, otherwise the poorer friend 
will feel uncomfortable.

Key Observation:
If we sort the friends by their money in ascending order, any valid group of friends 
will form a contiguous subarray where (money[right] - money[left] < d).
=========================================================
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
=========================================================
APPROACH 1: Two Pointers / Sliding Window
=========================================================

• Intuition:
  Sorting the friends by money naturally clusters friends with similar wealth together.
  A two-pointer sliding window can expand the right boundary while the money difference 
  with the left boundary remains less than d, and shrink from the left when it violates the condition.

• Approach:
  1. Store each friend as a pair (money, friendship_factor).
  2. Sort friends in non-decreasing order of money.
  3. Maintain a sliding window [left, right] and track current_friendship sum.
  4. Expand 'right', adding friendship factors. If money[right] - money[left] >= d, 
     subtract friendship factors from 'left' and increment 'left'.
  5. Keep track of the maximum friendship sum seen.

• Why it Works:
  Since the array is sorted, all elements inside [left, right] satisfy the money condition 
  relative to 'left'. Because money[right] is the maximum in the window, all pairwise 
  differences within the window are strictly less than d.

• Time Complexity (TC) : O(N log N) due to sorting, O(N) for sliding window.
• Space Complexity (SC): O(N) to store friend pairs.
=========================================================
*/

/*
=========================================================
FINAL APPROACH SELECTION
=========================================================
• Why chosen: Two Pointers / Sliding Window is optimal both in time and memory complexity.
• Advantage : Processing the sorted array in a single pass O(N) avoids unnecessary binary searches 
  or prefix sums, keeping time complexity strictly optimal at O(N log N).
=========================================================
*/

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long d;
    if (!(cin >> n >> d)) return 0;

    vector<pair<long long, long long>> friends(n);
    for (int i = 0; i < n; ++i) {
        cin >> friends[i].first >> friends[i].second; // first = money, second = friendship
    }

    // Sort friends by money in ascending order
    sort(friends.begin(), friends.end());

    long long max_friendship = 0;
    long long current_friendship = 0;
    int left = 0;

    // Two Pointers / Sliding Window
    for (int right = 0; right < n; ++right) {
        current_friendship += friends[right].second;

        while (friends[right].first - friends[left].first >= d) {
            current_friendship -= friends[left].second;
            left++;
        }

        max_friendship = max(max_friendship, current_friendship);
    }

    cout << max_friendship << "\n";

    return 0;
}
