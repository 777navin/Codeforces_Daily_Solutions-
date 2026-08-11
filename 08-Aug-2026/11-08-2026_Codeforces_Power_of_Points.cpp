/*
=========================================================
Date        : 11-08-2026
Problem Name: Power of Points
Platform    : Codeforces
Difficulty  : 1500
Tags        : sorting, math, prefix sum

Problem Summary:
Given n points, for each point s as the center, construct n segments [s, x_i] or [x_i, s].
Calculate the sum of powers (number of intersecting segments) for all integer points from 1 to 10^9.

Key Observation:
The total sum of powers of all points for a given s is mathematically equivalent to the sum of the lengths of all n segments: sum(|s - x_i| + 1).
=========================================================
*/

/*
1. Brute Force
- Intuition: Directly calculate the sum of distances from the chosen point s to all other points x_i.
- Approach: For each chosen s (from x_1 to x_n), run a nested loop over all x_i to compute sum(|s - x_i| + 1).
- Why it Works: It strictly follows the simplified mathematical formula derived from the problem.
- Time Complexity (TC): O(N^2) - N queries, each taking O(N) time.
- Space Complexity (SC): O(N) - to store the original array and answers.

2. Optimized
- Intuition: Repeatedly calculating distances can be optimized if the points are sorted. We can compute left and right distance sums in O(1).
- Approach: Sort the array (keeping track of original indices). Use a prefix sum array. For any point, distance sum = (left elements calculation) + (right elements calculation).
- Why it Works: Sorting groups smaller and larger elements. Prefix sums allow getting the sum of these ranges instantly without looping.
- Time Complexity (TC): O(N log N) - due to sorting the array. Prefix sum calculations take O(N).
- Space Complexity (SC): O(N) - for storing the array with original indices, prefix sums, and the answer array.
*/

/*
=========================================================
FINAL APPROACH: Optimized
- Chosen because N <= 2*10^5; the O(N^2) brute force approach will give Time Limit Exceeded (TLE).
- The prefix sum and sorting technique reduces the time to O(N log N), which comfortably passes the 2-second time limit.
=========================================================
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    // Store values and their original indices to output answers in the correct order
    vector<pair<long long, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }
    
    // Sort array based on the coordinate values
    sort(a.begin(), a.end());
    
    // Compute prefix sums
    vector<long long> pref(n);
    pref[0] = a[0].first;
    for (int i = 1; i < n; ++i) {
        pref[i] = pref[i - 1] + a[i].first;
    }
    
    vector<long long> ans(n);
    
    // Calculate answer for each point
    for (int i = 0; i < n; ++i) {
        long long s = a[i].first;
        
        long long left_sum = 0;
        if (i > 0) {
            // (Count of left elements * s) - (Sum of left elements)
            left_sum = s * i - pref[i - 1];
        }
        
        long long right_sum = 0;
        if (i < n - 1) {
            // (Sum of right elements) - (Count of right elements * s)
            right_sum = (pref[n - 1] - pref[i]) - s * (n - 1 - i);
        }
        
        // Add n because each of the n segments adds +1 to its length
        ans[a[i].second] = left_sum + right_sum + n;
    }
    
    // Print the results in their original order
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
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
