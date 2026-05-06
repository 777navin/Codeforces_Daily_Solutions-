// 28-04-2026_Codeforces_Disturbing_Distribution.cpp

/*
Date: 28-04-2026
Problem Name: A. Disturbing Distribution
Platform: Codeforces
Difficulty: Div 2 A
Tags: greedy, math

Problem Summary:
Given an array `a` of length `n`, you can repeatedly select and remove any non-decreasing 
subsequence. The cost of an operation is the product of the elements in the selected subsequence. 
You need to find the minimum total cost to empty the array, modulo 676 767 677.

=================================================================================================
Methods to Solve:
=================================================================================================

1. Brute Force (Conceptual / DP)
--------------------------------
- Intuition: Try all valid non-decreasing subsequences to remove, and recursively find the 
  minimum cost for the remaining elements.
- Approach: Bitmask DP or backtracking to iterate over all subset removals.
- Time Complexity: O(2^N * N), which will give Time Limit Exceeded (TLE) for N = 100.
- Space Complexity: O(2^N) for memoization states.
- Why better than previous method: Purely theoretical to understand all valid states.
- When to use: Never use for this problem size.

2. Optimal Approach (Greedy Observation)
----------------------------------------
- Intuition: Let's analyze how elements multiply. For any two integers X >= 2 and Y >= 2, 
  their product is always greater than or equal to their sum (X * Y >= X + Y). Therefore, 
  grouping two numbers >= 2 in the same operation NEVER reduces the cost. We should always 
  remove numbers >= 2 independently. 
  
  However, for the number 1, 1 * X = X, which is strictly less than 1 + X. This means 
  we should ALWAYS try to group 1s with some number >= 2 to essentially "hide" the 1s 
  and avoid paying for them. 

- Approach:
  1. Calculate the sum `S` of all elements in the array that are >= 2.
  2. If there are NO elements >= 2 in the array (i.e., only 1s), we can just group all 
     the 1s together in a single operation. The cost is 1 * 1 * ... * 1 = 1.
  3. If there are elements >= 2:
     - We can hide any number of 1s in a number X >= 2 as long as those 1s appear *before* X in the array (to maintain the non-decreasing rule 1 <= X).
     - If the VERY LAST element of the array is 1, it has no element >= 2 coming after it. 
       Thus, it cannot be hidden and MUST be removed separately (costing 1).
     - If the last element is NOT 1, it means all 1s in the array appear before the last 
       number >= 2. We can hide ALL of them in that last number.
  4. Final logic:
     - If array only has 1s: Cost is 1.
     - If the last element is 1: Cost is `S + 1`.
     - Otherwise: Cost is `S`.
  5. Finally, return the cost modulo 676767677 as requested by the problem.

- Dry Run (Example: a = [1, 2, 1, 3]):
  - Elements >= 2 are 2 and 3. Sum S = 5.
  - The last element is 3 (which is not 1).
  - So, we can group the first '1' with '2' (cost 2) and the second '1' with '3' (cost 3).
  - Total cost = 5. Matches formula S.

- Time Complexity: O(N) per testcase. We only need a single pass to sum elements and check the last.
- Space Complexity: O(N) to store the array, or O(1) if processed optimally.
- Why better than previous method: Mathematical reduction turns an exponential DP into an O(N) linear scan.
- When to use: Always for this problem. Perfect for competitive programming.

=================================================================================================
Comparison Table:
=================================================================================================
+-----------------+-------------------+-------------------+---------------------------------+
| Method          | Time Complexity   | Space Complexity  | Best Use Case                   |
+-----------------+-------------------+-------------------+---------------------------------+
| 1. Brute Force  | O(2^N * N)        | O(2^N)            | Theoretical baseline            |
| 2. Greedy Math  | O(N)              | O(N)              | Optimal for contest submission  |
+-----------------+-------------------+-------------------+---------------------------------+

Final Recommended Solution: Approach 2 (Greedy Math)
*/

#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    long long sum_greater_than_one = 0;
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] >= 2) {
            sum_greater_than_one += a[i];
        }
    }
    
    long long min_cost = 0;
    
    // Case 1: The array consists entirely of 1s
    if (sum_greater_than_one == 0) {
        min_cost = 1;
    } 
    // Case 2: There are trailing 1s that cannot be hidden in a larger number
    else if (a.back() == 1) {
        min_cost = sum_greater_than_one + 1;
    } 
    // Case 3: All 1s can be hidden in elements >= 2 appearing after them
    else {
        min_cost = sum_greater_than_one;
    }
    
    // Apply the specific modulo requested by the problem
    cout << min_cost % 676767677 << "\n";
}

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
