/*
=========================================================
Date        : 14-08-2026
Problem Name: Eating Candies (1669F)
Platform    : Codeforces
Difficulty  : 1100
Tags        : two pointers, greedy, binary search, data structures

Problem Summary:
Alice eats candies from the left, Bob eats candies from the right.
They must eat candies strictly consecutively from their respective ends without sharing.
Find the maximum total number of candies both can eat such that their total consumed weights are equal.

Key Observation:
Since all candy weights are positive (w_i >= 1), prefix and suffix sums are strictly increasing, 
allowing a two-pointer approach to find matching sums in O(n) time.
=========================================================
*/

/*
---------------------------------------------------------
APPROACH 1: Prefix Sums + Binary Search (Better)
---------------------------------------------------------
• Intuition:
  Compute prefix sums from left and suffix sums from right. For each prefix sum, check if an equal suffix sum exists using binary search.
• Approach:
  Precompute prefix sums. For each index i (1 to n), binary search for the same sum in the precomputed suffix sums at an index j > i.
• Why it Works:
  All weights are positive, making the suffix sums strictly monotonic and binary searchable.
• Time Complexity (TC): O(n log n) per testcase.
• Space Complexity (SC): O(n) for storing prefix/suffix arrays.

---------------------------------------------------------
APPROACH 2: Two Pointers (Most Optimal)
---------------------------------------------------------
• Intuition:
  Greedily advance the pointer on the side with the smaller current accumulated sum until they meet or match.
• Approach:
  1. Initialize left = 0, right = n - 1, sum_alice = 0, sum_bob = 0, and max_candies = 0.
  2. While left <= right:
     - If sum_alice <= sum_bob, add candies[left++] to sum_alice.
     - Else, add candies[right--] to sum_bob.
     - If sum_alice == sum_bob at any step, update max_candies = left + (n - 1 - right).
• Why it Works:
  Weights are strictly positive. Increasing the smaller side is the only way it can ever catch up to the larger side.
• Time Complexity (TC): O(n) total operations since each element is processed at most once.
• Space Complexity (SC): O(1) auxiliary space beyond the input storage.
---------------------------------------------------------
*/

/*
=========================================================
FINAL APPROACH: Two Pointers
=========================================================
• Why Chosen: It achieves optimal linear time O(n) and minimal auxiliary space O(1).
• Advantage: Avoids additional memory allocation and log(n) overhead of binary search.
=========================================================
*/

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<long long> w(n);
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }
    
    int left = 0;
    int right = n - 1;
    long long sum_alice = 0;
    long long sum_bob = 0;
    int max_candies = 0;
    
    while (left <= right) {
        if (sum_alice <= sum_bob) {
            sum_alice += w[left];
            left++;
        } else {
            sum_bob += w[right];
            right--;
        }
        
        if (sum_alice == sum_bob) {
            max_candies = left + (n - 1 - right);
        }
    }
    
    cout << max_candies << "\n";
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
