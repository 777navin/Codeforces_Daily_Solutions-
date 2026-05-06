// 06-05-2026_Codeforces_1106C.cpp

/*
Date: 06-05-2026
Problem Name: Lunar New Year and Number Division (1106C)
Platform: Codeforces
Difficulty: 900
Tags: greedy, sortings, math

Problem Summary:
Given an array of 'n' positive integers (where 'n' is an even number), divide the numbers into pairs. 
The goal is to minimize the sum of the squares of the sums of each pair.

Methods to Solve:
1. Brute Force (Generating all permutations/pairings)
2. Optimal Approach (Greedy Strategy with Sorting)

---------------------------------------------------------
Method 1: Brute Force
- Intuition: Generate all possible valid pairings of the 'n' elements. Calculate the sum of squares for each combination and find the absolute minimum.
- Approach: Use recursion/backtracking to pair elements exhaustively.
- Dry Run: For n=4, array=[8,5,2,3], valid pairs could be (8,5)(2,3) -> 169+25=194, (8,2)(5,3) -> 100+64=164, (8,3)(5,2) -> 121+49=170. Min is 164.
- Time Complexity: O((N-1)!!) - Mathematically, the number of ways to pair N items. This is exponentially large and unfeasible for N=300,000.
- Space Complexity: O(N) for the recursion stack.
- Why better than previous method: N/A
- When to use: Never for competitive programming problems of this constraint size.

---------------------------------------------------------
Method 2: Optimal Approach (Greedy + Two Pointers)
- Intuition: To minimize the sum of squared pairs, we need the sum of each pair to be as close to each other as possible. Pairing the smallest available number with the largest available number guarantees the most balanced and uniform distribution of pair sums, minimizing the final quadratic sum.
- Approach: 
  1. Sort the array in ascending order.
  2. Maintain two pointers, one at the start (left = 0) and one at the end (right = n - 1).
  3. Form a pair `(a[left], a[right])`, calculate `(a[left] + a[right])^2`, and add it to the total answer.
  4. Move the pointers inwards (`left++`, `right--`) until they cross.
- Dry Run: 
  Input: n = 4, a = [8, 5, 2, 3]
  Sorted Array: [2, 3, 5, 8]
  Pair 1: a[0] + a[3] = 2 + 8 = 10 -> 10^2 = 100
  Pair 2: a[1] + a[2] = 3 + 5 = 8 -> 8^2 = 64
  Total Result: 100 + 64 = 164
- Time Complexity: O(N log N) - The sorting step dominates the execution time. The two-pointer traversal takes O(N) time.
- Space Complexity: O(1) or O(N) - Depending on the internal memory used by the sorting algorithm (e.g., IntroSort in C++). The logic itself takes O(1) auxiliary space.
- Why better than previous method: Reduces execution time from exponential factorial to sub-quadratic, comfortably passing the 2.0-second time limit for N = 3*10^5.
- When to use: Excellent for problems asking to minimize the maximum sum, or minimize the sum of powers of combinations.

Comparison Table:
Method          | TC         | SC   | Best Use Case
---------------------------------------------------------
Brute Force     | O((N-1)!!) | O(N) | Extremely small constraints (N <= 10)
Optimal(Greedy) | O(N log N) | O(1) | Standard competitive programming, N up to 10^6

Final Recommended Solution: Optimal Approach (Greedy + Two Pointers)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    // Using long long to prevent any potential overflow during input summation
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // Step 1: Sort the array to prepare for the greedy strategy
    sort(a.begin(), a.end());
    
    long long min_sum_of_squares = 0;
    
    // Step 2: Two pointer approach to pair smallest with largest
    int left = 0;
    int right = n - 1;
    
    while (left < right) {
        // Calculate the sum of the current optimal pair
        long long pair_sum = a[left] + a[right];
        
        // Add the square of the sum to our total answer
        min_sum_of_squares += (pair_sum * pair_sum);
        
        // Move pointers inward
        left++;
        right--;
    }
    
    // Output the final calculated minimum
    cout << min_sum_of_squares << "\n";
}

int main() {
    // Fast I/O for competitive programming performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // 1106C requires processing a single global testcase
    solve();
    
    return 0;
}
