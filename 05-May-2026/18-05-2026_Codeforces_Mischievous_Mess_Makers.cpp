/*
Date: 18-05-2026
Problem Name: Mischievous Mess Makers (645B)
Platform: Codeforces
Difficulty: 1200
Tags: Greedy, Math, Combinatorics

Problem Summary:
We are given an array of n elements initially sorted in ascending order (1 to n). We can perform 
at most k swaps of elements at any two distinct positions. We want to find the maximum possible 
"messiness" (total number of inversions) attainable. An inversion is a pair of indices (i, j) 
such that i < j and p[i] > p[j].

Methods to Solve:
1. Brute Force / Simulation
- Intuition: Simulate all possible swaps recursively or generate permutations to find the maximum 
  inversions.
- Approach: Try every possible pair of swaps for k steps and compute inversions for each configuration.
- Time Complexity: O(n! * n^2) or O(n^2) per step, which is completely intractable for n = 100,000.
- Space Complexity: O(n) for the array/recursion stack.
- Why better than previous method: N/A
- When to use: Only for extremely small constraints (e.g., n <= 10).

2. Optimal Approach (Greedy + Mathematical Formula)
- Intuition: To maximize inversions, we should greedily swap the outermost elements that haven't 
  been swapped yet. Swapping the element at index `i` (from left) and index `n - i + 1` (from right) 
  moves the largest available element to the front and the smallest to the back. This maximizes 
  the number of elements between them that will form new inversions.
- Approach: 
  Let m = min(k, n / 2) be the maximum number of effective swaps we can make.
  For each swap i (from 1 to m):
    - The two swapped elements form 1 inversion with each other.
    - The new larger element at the left position forms (n - 2i) inversions with all elements between them.
    - The elements in between form (n - 2i) inversions with the new smaller element at the right position.
    - Thus, the i-th swap contributes exactly: 1 + 2 * (n - 2i) = 2n - 4i + 1 inversions.
  
  Summing this arithmetic progression from i = 1 to m gives the direct formula:
  Total Inversions = 2 * m * n - 2 * m * m - m
- Dry Run:
  Inputs: n = 5, k = 2
  m = min(2, 5 / 2) = 2
  Formula: 2 * 2 * 5 - 2 * (2^2) - 2 
          = 20 - 8 - 2 = 10.
  Output: 10 (Matches Sample 1).
- Time Complexity: O(1) using the direct mathematical formulation.
- Space Complexity: O(1) as no arrays or extra data structures are required.
- Why better than previous method: Drastically reduces execution time from factorial/quadratic to constant time, making it highly efficient.
- When to use: Always, as it handles the maximum constraints perfectly without integer overflow.

Comparison Table:
Method            | TC   | SC   | Best Use Case
-------------------------------------------------------------
Brute Force       | O(N!)| O(N) | Only for N <= 10
Optimal (Greedy)  | O(1) | O(1) | All cases up to N, K <= 10^5

Final Recommended Solution:
The Greedy Math Approach is the optimal solution. It runs in O(1) time and avoids any array 
allocations. We must use `long long` for calculations to prevent integer overflow since 
the maximum result can be around 5 * 10^9.
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    // Optimize standard I/O operations for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long num_cows, nap_minutes;
    if (cin >> num_cows >> nap_minutes) {
        // We can swap at most half of the elements in the array
        long long effective_swaps = min(nap_minutes, num_cows / 2);
        
        // Direct mathematical derivation of the total inversions added
        long long max_messiness = 2 * effective_swaps * num_cows - 2 * effective_swaps * effective_swaps - effective_swaps;
        
        cout << max_messiness << "\n";
    }

    return 0;
}
