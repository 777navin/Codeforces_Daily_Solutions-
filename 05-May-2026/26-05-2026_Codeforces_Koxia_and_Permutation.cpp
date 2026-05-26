// File Name: 26-05-2026_Codeforces_Koxia_and_Permutation.cpp

/*
Date: 26-05-2026
Problem Name: Koxia and Permutation (1770B)
Platform: Codeforces
Difficulty: 1000
Tags: constructive algorithms, greedy, math

Problem Summary:
Given n and k, construct a permutation of length n such that the maximum cost among all 
contiguous subarrays of length k is minimized. The cost of a subarray is defined as the 
sum of its maximum and minimum elements. 

Methods to Solve:
1. Optimal Constructive Approach (Two Pointers)

For EACH method include:

- Intuition
  The optimal minimum possible cost for the maximum window is `n + 1`. Since the maximum 
  value `n` must exist in some window of size k, the minimum value in that same window 
  would ideally be `1` (or as small as possible) to minimize the sum. To enforce this 
  strictly across all windows of length k, we can systematically drain the largest 
  available numbers and pair them with the smallest available numbers. 

- Approach
  Use two pointers: `left` starting at 1 (smallest) and `right` starting at n (largest).
  For every block of `k` elements in our permutation, we pick the `k - 1` largest 
  available elements from `right`, followed by `1` smallest available element from `left`.
  We repeat this pattern until all `n` elements are placed. This guarantees that within 
  any sliding window of size `k`, the sum of the local maximum and local minimum never 
  exceeds `n + 1`.

- Dry Run (small example)
  Input: n = 5, k = 3
  Initialize: left = 1, right = 5
  Iteration 1: 
  - Take k-1 (2) elements from right: [5, 4], right becomes 3
  - Take 1 element from left: [1], left becomes 2
  - Current Array: [5, 4, 1]
  Iteration 2:
  - Take k-1 (2) elements from right: [3, 2], right becomes 1
  - left (2) is now > right (1), so loop breaks
  - Final Array: [5, 4, 1, 3, 2]
  
  Windows of size 3:
  1. [5, 4, 1] -> max=5, min=1 -> sum=6
  2. [4, 1, 3] -> max=4, min=1 -> sum=5
  3. [1, 3, 2] -> max=3, min=1 -> sum=4
  Max cost across all windows is 6, which is exactly n + 1 (5 + 1).

- Time Complexity
  O(n) per test case. We iterate exactly n times to print the permutation.

- Space Complexity
  O(1) auxiliary space (ignoring standard I/O buffer), as we print the elements directly 
  without storing them in an intermediate array.

- Why better than previous method
  This is a direct O(N) mathematical construction. It requires no sorting, searching, 
  or complex data structures, making it the most optimal and straightforward approach.

- When to use
  Always use this construction for this specific Codeforces problem layout.

Comparison Table:
Method                              | TC   | SC   | Best Use Case
------------------------------------|------|------|---------------------------
Optimal Constructive (Two Pointers) | O(N) | O(1) | Guaranteed O(N) generation

Final Recommended Solution:
Optimal Constructive Approach (Implemented Below)
*/

#include <iostream>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    
    int left = 1;
    int right = n;
    
    // Construct the permutation directly
    while (left <= right) {
        // Print the (k - 1) largest available elements
        for (int i = 0; i < k - 1 && left <= right; ++i) {
            cout << right << " ";
            right--;
        }
        
        // Print the 1 smallest available element
        if (left <= right) {
            cout << left << " ";
            left++;
        }
    }
    cout << "\n";
}

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    // Handle multiple test cases
    while (t--) {
        solve();
    }
    
    return 0;
}
