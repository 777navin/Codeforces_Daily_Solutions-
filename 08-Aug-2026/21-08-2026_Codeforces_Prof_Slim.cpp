/*
=========================================================
Date        : 21-08-2026
Problem Name: Prof. Slim (1670A)
Platform    : Codeforces
Difficulty  : 800
Tags        : greedy, math, sortings, two pointers

Problem Summary:
Given an array of n non-zero integers, we can swap the signs 
of any pair of positive and negative elements any number of times. 
Determine if the array can be transformed into a non-decreasing order.

Key Observation:
The total count of negative numbers is invariant. In a non-decreasing 
array, all negative elements must strictly occupy the first k positions, 
where k is the total count of negative elements.
=========================================================
*/

/*
=========================================================
APPROACH 1: Greedy Prefix Sign Assignment (Optimal)
=========================================================

• Intuition:
  - Since we can transfer negative signs freely between indices, we must
    place all available negative signs on the prefix of size k.
  - The remaining elements must have positive signs.

• Approach:
  - Count total negative elements (let count = k).
  - Modify the array: first k elements become -|a[i]|, and elements from 
    index k to n-1 become +|a[i]|.
  - Check if the transformed array is non-decreasing (a[i] <= a[i+1] for all i).

• Why it Works:
  - Any valid sorted configuration with k negative numbers requires all 
    negatives to appear before any positive numbers.
  - Since the absolute values at each position cannot move, assigning 
    signs to the first k elements is the only possible configuration.

• Time Complexity (TC): O(N) per testcase, summing to O(∑N) <= O(10^5).
• Space Complexity (SC): O(N) to store the array.
*/

/*
=========================================================
FINAL APPROACH
=========================================================
We use Approach 1 (Greedy Prefix Sign Assignment) because the sign placement 
is deterministic and uniquely constrained. It runs in optimal linear time O(N) 
and O(1) auxiliary space, which easily satisfies the 1.0s time limit.
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    int neg_count = 0;
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] < 0) {
            neg_count++;
        }
    }
    
    // Assign negative signs to the first neg_count elements
    for (int i = 0; i < neg_count; ++i) {
        a[i] = -abs(a[i]);
    }
    // Assign positive signs to the remaining elements
    for (int i = neg_count; i < n; ++i) {
        a[i] = abs(a[i]);
    }
    
    // Verify if the array is sorted in non-decreasing order
    bool is_sorted = true;
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] > a[i + 1]) {
            is_sorted = false;
            break;
        }
    }
    
    if (is_sorted) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
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
