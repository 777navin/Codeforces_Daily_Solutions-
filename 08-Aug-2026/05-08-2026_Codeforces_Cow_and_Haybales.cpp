/*
=========================================================
Date        : 05-08-2026
Problem Name: Cow and Haybales (1307A)
Platform    : Codeforces
Difficulty  : 800
Tags        : greedy, implementation, math

Problem Summary:
Maximize the number of haybales in the first pile within d days.
Moving a haybale to an adjacent pile takes 1 day.
You want to move as many haybales from other piles to pile 1 as possible.

Key Observation:
Moving a haybale from pile i to pile 1 takes exactly i-1 days.
Greedily moving haybales from the closest piles first costs fewer days, maximizing total transferred.
=========================================================
*/

/*
1. Optimal Greedy Approach

* Intuition:
  Since moving haybales from closer piles takes fewer days, we should exhaust piles left to right.
* Approach:
  Iterate from pile 2 to n. Calculate the cost to move one haybale to pile 1 (i-1 days).
  Move as many haybales as possible from pile i without exceeding the remaining days d.
* Why it Works:
  Closest piles offer the "cheapest" haybales in terms of days. Taking them first maximizes the total moved.
* Time Complexity (TC): 
  O(N) per testcase, since we iterate through the array once.
* Space Complexity (SC): 
  O(N) to store the elements, though it can be optimized to O(1) by processing on the fly.
*/

/*
FINAL APPROACH
* This greedy approach is chosen because it directly models the optimal choice at each step without complex logic.
* It is optimally efficient with O(N) time and easily fits the 2-second time limit for n, d <= 100.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Iterate through the piles starting from the second one (index 1)
    for (int i = 1; i < n; ++i) {
        int cost = i; // In 0-indexed array, cost to move from i to 0 is i days
        
        // Find maximum haybales we can move from this pile
        int max_moves = min(a[i], d / cost);
        
        // Transfer haybales
        a[0] += max_moves;
        
        // Deduct used days
        d -= max_moves * cost;
        
        // If we run out of days, stop
        if (d == 0) {
            break;
        }
    }

    cout << a[0] << "\n";
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
