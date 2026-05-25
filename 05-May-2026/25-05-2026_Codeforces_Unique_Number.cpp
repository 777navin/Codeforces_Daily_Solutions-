// 25-05-2026_Codeforces_Unique_Number.cpp

/*
Date: 25-05-2026
Problem Name: C. Unique Number
Platform: [Codeforces](https://codeforces.com/problemset/problem/1462/C)
Difficulty: Easy (Rating: 900)
Tags: Greedy, Math

Problem Summary:
Given a positive integer x (1 <= x <= 50), find the smallest positive integer such that the sum of its digits equals x, and all of its digits are completely distinct. If no such number can be formed, output -1. 

Methods to Solve:
1. Brute Force (Backtracking / All Subsets)
2. Optimal Approach (Greedy)

---------------------------------------------------------
Method 1: Brute Force (Backtracking)
---------------------------------------------------------
- Intuition: 
  Since the digits must be distinct and can only be from 1 to 9, there are only 2^9 (512) possible combinations of digits. We can generate all valid combinations, filter the ones that sum up to x, sort their digits to form the smallest number, and find the overall minimum among them.
- Approach:
  Use a recursive function to either include or exclude each digit from 1 to 9. If the current sum equals x, convert the chosen digits into an integer and update the minimum answer. 
- Dry Run (x = 15):
  It generates combinations like {6, 9}, {7, 8}, {1, 5, 9} etc. 
  Smallest valid sequence ordered correctly is 69.
- Time Complexity: O(2^9) which simplifies to O(1) constant time since the input space is restricted strictly to digits 1-9.
- Space Complexity: O(1) max recursion depth is 9.
- Why better than previous method: N/A (Baseline).
- When to use: When constraints are extremely small and you want a foolproof logic without finding mathematical patterns.

---------------------------------------------------------
Method 2: Optimal Approach (Greedy)
---------------------------------------------------------
- Intuition: 
  To make a number as small as possible, two conditions must be met:
  1. It should have the fewest number of digits possible.
  2. The most significant digits (leftmost) should be as small as possible.
  To achieve this, we should greedily use the largest possible digits (9, then 8, then 7...) starting from the least significant digit (rightmost).
- Approach:
  1. The maximum possible sum with distinct digits is 1+2+3+4+5+6+7+8+9 = 45. If x > 45, it's impossible, print -1.
  2. Start iterating a variable `d` from 9 down to 1.
  3. If x >= d, take the digit `d`, append it to the front of our result (or back and reverse later), and subtract `d` from x.
  4. If x < d, take the remaining x as the leftmost digit, and we are done.
- Dry Run (x = 15):
  - d = 9: x >= 9 is True. Add '9'. x becomes 15 - 9 = 6.
  - d = 8: x >= 8 is False (6 < 8).
  - d = 7: x >= 7 is False.
  - d = 6: x >= 6 is True. Add '6'. x becomes 6 - 6 = 0.
  - Number is constructed right-to-left: 9, then 6 -> 69.
- Time Complexity: O(1) maximum of 9 iterations regardless of x.
- Space Complexity: O(1) for storing the small result string.
- Why better than previous method: Much cleaner, faster, and avoids unnecessary recursion overhead.
- When to use: Standard approach for this problem in competitive programming environments.

Comparison Table:
Method       | TC   | SC   | Best Use Case
---------------------------------------------------------
Brute Force  | O(1) | O(1) | Small bounds, simple logic check
Greedy       | O(1) | O(1) | Optimal standard CP solution

Final Recommended Solution: Optimal Approach (Greedy)
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Fast I/O for Competitive Programming
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

// Function implementing the Optimal Greedy Approach
void solve() {
    int x;
    cin >> x;

    // The maximum possible sum with 9 distinct digits is 45
    if (x > 45) {
        cout << -1 << "\n";
        return;
    }

    string result = "";
    
    // Greedily pick the largest possible digit from 9 down to 1
    for (int d = 9; d >= 1; --d) {
        if (x >= d) {
            result += to_string(d);
            x -= d;
        }
    }

    // Since we picked digits from largest to smallest, 
    // the string holds them in descending order (e.g., "96").
    // Reversing it will give the smallest valid number (e.g., "69").
    reverse(result.begin(), result.end());

    cout << result << "\n";
}

int main() {
    // Apply fast I/O
    fast_io();

    int t;
    // Handle multiple test cases
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
