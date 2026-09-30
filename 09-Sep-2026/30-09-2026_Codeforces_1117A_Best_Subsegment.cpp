/*
=========================================================
Date        : 30-09-2026
Problem Name: 1117A - Best Subsegment
Platform    : Codeforces
Difficulty  : 1100
Tags        : Math, Implementation, Two Pointers

Problem Summary:
Given an array of n integers, find the maximum possible arithmetic mean 
among all continuous subsegments. If there are multiple subsegments 
that achieve this maximum mean, output the length of the longest one.

Key Observation:
The maximum arithmetic mean of any subsegment is strictly equal to the maximum 
element present in the array. Thus, the problem reduces to finding the maximum 
length of a contiguous subarray consisting entirely of the maximum element.
=========================================================
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
=========================================================
APPROACH 1: Contiguous Maximum Element Scanning (Optimal)
=========================================================

• Intuition:
  The average of a subsegment can never exceed the maximum value in that subsegment. 
  Therefore, the overall maximum arithmetic mean is simply the maximum element in the entire array, 
  and the maximum length subsegment achieving this mean consists of consecutive copies of this maximum element.

• Approach:
  1. Find the maximum element (max_val) in the array.
  2. Iterate through the array to track the current contiguous count of max_val.
  3. Maintain the overall maximum length found.

• Why it Works:
  Including any element smaller than max_val in a subsegment strictly decreases its arithmetic mean. 
  Hence, subsegments with the maximum arithmetic mean can only contain max_val.

• Time Complexity (TC) : O(N) — Single pass over the array to find max_val and calculate consecutive counts.
• Space Complexity (SC): O(1) — Uses a constant amount of extra memory.
=========================================================
*/

// Final Choice: Contiguous Maximum Element Scanning is selected because it runs in linear time O(N) and O(1) auxiliary space, which easily satisfies the 1-second time limit for N = 10^5.

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<int> a(n);
    int max_val = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        max_val = max(max_val, a[i]);
    }

    int max_len = 0;
    int current_len = 0;

    for (int i = 0; i < n; ++i) {
        if (a[i] == max_val) {
            current_len++;
            max_len = max(max_len, current_len);
        } else {
            current_len = 0;
        }
    }

    cout << max_len << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
