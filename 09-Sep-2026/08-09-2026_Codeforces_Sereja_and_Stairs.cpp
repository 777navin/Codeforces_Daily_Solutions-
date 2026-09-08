/*
=========================================================
Date        : 08-09-2026
Problem Name: 381B - Sereja and Stairs
Platform    : Codeforces
Difficulty  : 1100
Tags        : greedy, data structures, sortings

Problem Summary:
Given m cards with positive integers, form a "stair" sequence
a_1 < a_2 < ... < a_i > ... > a_k of maximum possible length.
Output the maximum length followed by any such valid sequence.

Key Observation:
In a strictly increasing then strictly decreasing sequence, the maximum 
element can appear at most once (at the peak), while every other number 
smaller than the maximum can appear at most twice (once ascending, once descending).
=========================================================
*/

/*
---------------------------------------------------------
APPROACH 1: Frequency Array / Greedy Construction (Optimal)
---------------------------------------------------------
• Intuition:
  To maximize the length, we should use as many valid elements as possible.
  Any value strictly less than the maximum can be placed once in the increasing 
  prefix and once in the decreasing suffix. The maximum value can only be placed once.

• Approach:
  1. Count occurrences of each number using a frequency array or hash map.
  2. Identify the maximum element present in the input.
  3. Iterate through values from smallest up to the maximum:
     - If count >= 1, push one instance to the increasing sequence (left part).
     - If count >= 2 and the number is strictly less than the maximum, 
       push one instance to the decreasing sequence (right part).
  4. Concatenate the left part with the reversed right part (or output right part descending).

• Why it Works:
  Placing one instance of each distinct number in ascending order and a second 
  instance of each duplicate (except the peak) in descending order satisfies the 
  strict monotonicity constraints while using the maximum possible count of each number.

• Time Complexity (TC):
  O(m + MAX_VAL) where m is the number of cards and MAX_VAL <= 5000.
  Counting takes O(m) and iterating up to MAX_VAL takes O(MAX_VAL).

• Space Complexity (SC):
  O(MAX_VAL) to store the frequency array and result sequences.
---------------------------------------------------------
*/

/*
---------------------------------------------------------
FINAL APPROACH SELECTION:
---------------------------------------------------------
The frequency-based greedy approach is chosen because card values are bounded 
by 5000, allowing an O(m + MAX_VAL) solution that is both memory-efficient and 
optimal in runtime.
---------------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m;
    if (!(cin >> m)) return 0;

    const int MAX_VAL = 5000;
    vector<int> freq(MAX_VAL + 1, 0);
    int max_val = 0;

    for (int i = 0; i < m; ++i) {
        int val;
        cin >> val;
        freq[val]++;
        max_val = max(max_val, val);
    }

    vector<int> inc_part;
    vector<int> dec_part;

    for (int i = 1; i <= max_val; ++i) {
        if (freq[i] > 0) {
            inc_part.push_back(i);
            freq[i]--;
        }
    }

    for (int i = max_val - 1; i >= 1; --i) {
        if (freq[i] > 0) {
            dec_part.push_back(i);
            freq[i]--;
        }
    }

    cout << inc_part.size() + dec_part.size() << "\n";

    for (int i = 0; i < (int)inc_part.size(); ++i) {
        cout << inc_part[i] << (i + 1 == (int)inc_part.size() && dec_part.empty() ? "" : " ");
    }
    for (int i = 0; i < (int)dec_part.size(); ++i) {
        cout << dec_part[i] << (i + 1 == (int)dec_part.size() ? "" : " ");
    }
    cout << "\n";

    return 0;
}
