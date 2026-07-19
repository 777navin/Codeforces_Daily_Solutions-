/*
=========================================================
Date        : 19-07-2026
Problem Name: Candies Division
Platform    : Codeforces
Difficulty  : 900
Tags        : Math, Greedy

Problem Summary:
Santa wants to distribute n candies to k kids as evenly as possible. 
The difference between the maximum and minimum candies received by any kid cannot exceed 1. 
Additionally, the number of kids receiving the extra candy (a + 1) cannot exceed floor(k / 2).

Key Observation:
Each kid can definitely receive at least floor(n / k) candies. The remaining candies (n % k) 
can be distributed to at most floor(k / 2) kids to satisfy the condition.
=========================================================
*/

#include <iostream>

using namespace std;

/*
Approach 1: Greedy Math Approach
- Intuition: 
  Give every kid an equal baseline amount of candies first. Then, distribute the leftover 
  candies to as many kids as allowed without violating the floor(k / 2) threshold.
- Approach:
  1. Calculate the base candies per kid: base = n / k. Total baseline candies = base * k.
  2. Calculate the leftover candies: rem = n % k.
  3. The maximum number of kids that can get an extra candy is max_extra = k / 2.
  4. Add the minimum of rem and max_extra to the baseline total.
- Why it Works:
  It ensures the absolute difference between any two kids is at most 1 while maximizing 
  the total candies distributed within the problem constraints.
- Time Complexity (TC) : O(1) per test case
- Space Complexity (SC): O(1)
*/

/*
Final Approach Choice:
- The O(1) greedy mathematical approach is chosen because it directly computes the optimal solution.
- Since n and k can be up to 10^9, a direct mathematical derivation prevents TLE and avoids any loops.
*/

void solve() {
    long long n, k;
    cin >> n >> k;
    
    long long base_distributed = (n / k) * k;
    long long remainder = n % k;
    long long max_extra_allowed = k / 2;
    
    long long total_candies = base_distributed + min(remainder, max_extra_allowed);
    
    cout << total_candies << "\n";
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
