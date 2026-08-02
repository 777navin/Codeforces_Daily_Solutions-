/*
=========================================================
Date        : 02-08-2026
Problem Name: 331C1 - The Great Julya Calendar
Platform    : Codeforces
Difficulty  : 1100
Tags        : greedy, dp, math

Problem Summary:
Given an integer n, you can subtract one of its digits from it.
Repeat this operation until the number becomes 0.
Find the minimum number of subtractions required.

Key Observation:
Greedily subtracting the largest digit present in the current number 
will minimize the number of steps required to reach zero.
=========================================================

Approaches:

1. Dynamic Programming (Alternative)
   - Intuition: We can try all possible digits present in 'n' and take the minimum steps.
   - Approach: Maintain a dp array where dp[i] is the min steps for number i. Transition: dp[i] = 1 + min(dp[i - d]) for all digits d in i.
   - Why it Works: Explores all valid paths to 0 and optimally picks the shortest.
   - Time Complexity (TC): O(N * log10(N))
   - Space Complexity (SC): O(N)

2. Greedy Approach
   - Intuition: To reach 0 as fast as possible, subtract the largest possible value at each step.
   - Approach: Loop while n > 0. Extract digits of n to find the maximum digit. Subtract this maximum digit from n and increment the step count.
   - Why it Works: Subtracting the largest digit optimally decreases the number fastest without skipping better intermediate states for this specific problem structure.
   - Time Complexity (TC): O(Steps * log10(N)) ≈ O(N)
   - Space Complexity (SC): O(1)

=========================================================
Final Approach: Greedy
- Chosen because it is highly optimal and requires O(1) space.
- The DP approach uses O(N) space which is unnecessary.
- The greedy simulation easily passes the 10^6 constraints for C1 within the 2s time limit.
=========================================================
*/

#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    long long n;
    cin >> n;

    long long steps = 0;
    
    // Continue subtracting the maximum digit until n reaches 0
    while (n > 0) {
        long long temp = n;
        long long max_digit = 0;
        
        // Find the maximum digit in the current number
        while (temp > 0) {
            max_digit = max(max_digit, temp % 10);
            temp /= 10;
        }
        
        // Subtract the maximum digit
        n -= max_digit;
        steps++;
    }

    cout << steps << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Problem does not require multiple test cases according to the sample
    solve();

    return 0;
}
