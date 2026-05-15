/*
Date: 15-05-2026
Problem Name: Pair of Toys (1023B)
Platform: Codeforces
Difficulty: 1000
Tags: Math, Implementation

Problem Summary:
Tanechka is in a toy shop where there are 'n' toys, cost of the i-th toy is 'i' burles.
She needs to choose exactly two distinct toys (a, b) such that their total cost (a + b) equals 'k'.
Pairs (a, b) and (b, a) are considered the same. We need to find the total number of such unique pairs.

Methods to Solve:
1. Brute Force (Iterative)
2. Optimal Approach (Mathematical Range Intersections)

---------------------------------------------------------------------------------------------------
1. Brute Force
- Intuition: Check every possible pair (a, b) where 1 <= a < b <= n.
- Approach: Use nested loops to find pairs that sum to k.
- Time Complexity: O(n^2) - Too slow for n = 10^14.
- Space Complexity: O(1).
- Why better than previous: N/A.
- When to use: Only for very small constraints (n < 5000).

2. Optimal Approach (Current Solution)
- Intuition: 
  We need to find the number of integers 'a' such that:
  1. 1 <= a <= n
  2. 1 <= b <= n (where b = k - a)
  3. a < b (to avoid double counting and ensure distinctness)
  
  From (a < b) and (b = k - a), we get:
  a < k - a  => 2a < k  => a < k/2.
  Thus, the maximum possible value for 'a' is floor((k-1)/2).
  
  From (b <= n) and (b = k - a), we get:
  k - a <= n => a >= k - n.
  Also, since 'a' must be at least 1, a >= max(1, k - n).
  
  So, 'a' must be in the range [max(1, k - n), floor((k-1)/2)].
  
- Approach:
  Calculate the lower bound: L = max(1LL, k - n)
  Calculate the upper bound: R = (k - 1) / 2
  The answer is max(0LL, R - L + 1).

- Dry Run (n=8, k=15):
  L = max(1, 15 - 8) = 7
  R = (15 - 1) / 2 = 7
  Count = 7 - 7 + 1 = 1 (The pair is (7, 8))

- Time Complexity: O(1) - Constant time calculations.
- Space Complexity: O(1) - No extra space used.
- Why better than previous: Handles constraints up to 10^14 instantly whereas Brute Force would take years.
- When to use: Always, given the constraints.

Comparison Table:
Method           | TC     | SC   | Best Use Case
-------------------------------------------------------
Brute Force      | O(n^2) | O(1) | Educational purposes
Optimal (Math)   | O(1)   | O(1) | Competitive Programming

Final Recommended Solution: Optimal Mathematical Approach
*/

#include <iostream>
#include <algorithm>

using namespace std;

/**
 * Fast I/O and Logic for Codeforces 1023B - Pair of Toys
 */
void solve() {
    long long n, k;
    if (!(cin >> n >> k)) return;

    // Condition 1: a + b = k
    // Condition 2: 1 <= a < b <= n
    
    // From a < b and a + b = k:
    // a < k - a  => 2a < k => a <= (k-1)/2
    long long right_bound = (k - 1) / 2;

    // From b <= n and b = k - a:
    // k - a <= n => a >= k - n
    // Also a >= 1
    long long left_bound = max(1LL, k - n);

    // Number of integers in range [left_bound, right_bound]
    if (left_bound <= right_bound) {
        cout << (right_bound - left_bound + 1) << endl;
    } else {
        cout << 0 << endl;
    }
}

int main() {
    // Standard Competitive Programming Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Problem doesn't mention multiple test cases, but structure is ready if needed
    solve();

    return 0;
}
