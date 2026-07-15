/*
=========================================================
Date        : 15-07-2026
Problem Name: Salem and Sticks (1105A)
Platform    : Codeforces
Difficulty  : 1000 (Easy)
Tags        : brute force, greedy, math

Problem Summary:
Given n sticks, find an integer t to minimize the total cost of changing 
their lengths so that every stick has a length of t-1, t, or t+1. 
The cost of changing a stick's length from a to b is |a - b|.

Key Observation:
The lengths of the sticks are very small (a_i <= 100). This means the 
optimal target length t must also lie within the range [1, 100].
=========================================================
*/

/*
1. Brute Force (Most Optimal for given constraints)
• Intuition: Since the maximum length of any stick is 100, the target length t will never exceed 100.
• Approach: Loop through all possible values of t from 1 to 100. For each t, calculate the cost to make all sticks "almost good" (cost is max(0, abs(a[i] - t) - 1)). Keep track of the minimum cost and the t that produced it.
• Why it Works: The search space for t is extremely small, guaranteeing we find the absolute minimum cost without risking a Time Limit Exceeded (TLE) error.
• Time Complexity (TC): O(N * M) where N is the number of sticks (1000) and M is the max possible value of a_i (100). 10^5 operations is virtually instantaneous.
• Space Complexity (SC): O(N) to store the lengths of the sticks in an array.
*/

/*
Final Approach:
The brute force approach checking t from 1 to 100 is chosen. 
It is absolutely optimal given the strict problem constraints (N <= 1000, A_i <= 100) 
and provides a clean, highly readable solution with zero risk of edge-case failures.
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int best_t = 1;
    int min_cost = 1e9; // Initialize with a large value
    
    // Check all possible values for t based on constraint a_i <= 100
    for (int t = 1; t <= 100; t++) {
        int current_cost = 0;
        
        for (int i = 0; i < n; i++) {
            int dist = abs(a[i] - t);
            // If length is already almost good (|a_i - t| <= 1), cost is 0
            if (dist > 1) {
                current_cost += (dist - 1);
            }
        }
        
        // Update the minimum cost and the optimal t
        if (current_cost < min_cost) {
            min_cost = current_cost;
            best_t = t;
        }
    }
    
    cout << best_t << " " << min_cost << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // The problem requires a single test case processing per execution.
    solve();
    
    return 0;
}
