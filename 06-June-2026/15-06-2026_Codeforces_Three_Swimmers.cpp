// 15-06-2026_Codeforces_Three_Swimmers.cpp

/*
Date: 15-06-2026
Problem Name: Three swimmers
Platform: Codeforces
Difficulty: 800
Tags: math, number theory

Problem Summary:
Three swimmers swim across a pool in 'a', 'b', and 'c' minutes respectively. 
They return to the starting side at multiples of their respective times. 
Given the time 'p' when you arrive at the pool, find the minimum wait time 
until at least one swimmer returns to the starting side.

Methods to Solve:
1. Brute Force (Not applicable due to 10^18 constraints)
2. Optimal Approach: Mathematical Calculation

For Optimal Approach:
- Intuition: The time the i-th swimmer arrives is a multiple of their period (a, b, or c).
  The next arrival time for a swimmer with period 'x' after time 'p' is 
  the smallest multiple of 'x' greater than or equal to 'p'.
  This can be calculated as: 
  - If p % x == 0: wait = 0
  - Else: wait = x - (p % x)
- Approach: Calculate the wait time for each swimmer individually and take the minimum.
- Time Complexity: O(1) per test case
- Space Complexity: O(1)

Comparison Table:
Method | TC | SC | Best Use Case
Optimal | O(1) | O(1) | All cases with 10^18 constraints

Final Recommended Solution: Use the math-based remainder logic for O(1) performance.
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/**
 * Function to calculate the wait time for a specific swimmer.
 * @param p Arrival time
 * @param period Swimmer's cycle time
 * @return Wait time until next arrival
 */
long long calculate_wait(long long p, long long period) {
    if (p % period == 0) return 0;
    return period - (p % period);
}

void solve() {
    long long p, a, b, c;
    if (!(cin >> p >> a >> b >> c)) return;

    // Calculate wait times for all three swimmers
    long long wait_a = calculate_wait(p, a);
    long long wait_b = calculate_wait(p, b);
    long long wait_c = calculate_wait(p, c);

    // The answer is the minimum of the three calculated wait times
    cout << min({wait_a, wait_b, wait_c}) << "\n";
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
