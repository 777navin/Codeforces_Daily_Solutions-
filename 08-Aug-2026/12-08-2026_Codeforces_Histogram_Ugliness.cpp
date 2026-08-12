/*
=========================================================
Date        : 12-08-2026
Problem Name: 1534B - Histogram Ugliness
Platform    : Codeforces
Difficulty  : 1100
Tags        : greedy, math, arrays

Problem Summary:
Given a histogram, you can decrease the height of any bar by 1 an arbitrary number of times. 
You need to minimize the "ugliness", which is the sum of the vertical outline length and the number of operations used.

Key Observation:
Decreasing a bar that is strictly taller than both its neighbors reduces the vertical outline by 2 at the cost of 1 operation, netting a -1 improvement in ugliness.
=========================================================
*/

/*
=========================================================
APPROACH EXPLANATION
=========================================================

1. Optimal Greedy Approach (Most Optimal)
   - Intuition: 
     Every time we decrease a bar that is strictly taller than both its neighbors, we reduce the total vertical outline by 2.
     Since the operation costs 1, the net change to the ugliness score is -1.
   
   - Approach: 
     Iterate through the array and identify strict local peaks. 
     Reduce these peaks to the maximum of their two neighbors (left and right).
     Count these reductions as operations.
     After flattening all peaks, calculate the vertical outline length of the new histogram by summing absolute differences of adjacent bars.
     Total ugliness = operations + final outline length.
   
   - Why it Works: 
     Decreasing any bar that is not a strict peak will cost 1 operation but reduce the outline by at most 0, leading to a net increase in ugliness. 
     Thus, shaving off only the strict peaks to the level of their highest neighbor guarantees minimal ugliness.
   
   - Time Complexity (TC): O(N) per testcase. We traverse the array a constant number of times.
   - Space Complexity (SC): O(N) to store the array of histogram heights.
=========================================================
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// Why this approach is chosen:
// The problem demands an efficient solution due to the large sum of N (up to 4 * 10^5). 
// The greedy peak-shaving approach operates in linear time O(N) and directly constructs the optimal state without complex simulations.
void solve() {
    int n;
    cin >> n;
    
    vector<long long> a(n + 2, 0); // Padding with 0s at ends (a[0] = 0, a[n+1] = 0)
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    long long operations = 0;
    
    // Step 1: Shave off the strict peaks
    for (int i = 1; i <= n; i++) {
        if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
            long long max_neighbor = max(a[i - 1], a[i + 1]);
            operations += (a[i] - max_neighbor);
            a[i] = max_neighbor;
        }
    }
    
    long long final_outline = 0;
    
    // Step 2: Calculate the vertical outline of the modified histogram
    for (int i = 1; i <= n + 1; i++) {
        final_outline += abs(a[i] - a[i - 1]);
    }
    
    // Total ugliness is operations used + remaining outline length
    cout << operations + final_outline << "\n";
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
