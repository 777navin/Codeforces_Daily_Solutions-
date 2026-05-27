/*
Date: 27-05-2026
Problem Name: A. Binary Decimal (1530A)
Platform: Codeforces
Difficulty: 800
Tags: Math, Greedy

Problem Summary:
A "binary decimal" is a number composed only of the digits 0 and 1. Given an integer n, the objective is to find the minimum number of binary decimals required to sum up to n. 

Methods to Solve:
1. String Iteration (Brute/Better)
2. Modulo Arithmetic (Optimal Approach)

-------------------------------------------------------------------
Method 1: String Iteration
- Intuition: Each binary decimal can contribute a maximum of 1 to any specific decimal place. Therefore, to form a digit 'd' at any decimal place, we need exactly 'd' binary decimals that have a 1 in that position. Thus, the minimum number of binary decimals needed is simply the maximum digit present in the number n.
- Approach: Read the number as a string, iterate through its characters, and find the maximum character.
- Dry Run (n = 121):
  - '1' -> max = 1
  - '2' -> max = 2
  - '1' -> max = 2
  - Answer = 2.
- Time Complexity: O(D) where D is the number of digits in n.
- Space Complexity: O(D) to store the string.
- Why better than previous method: N/A (Standard baseline approach).
- When to use: When the number is too large to fit in standard integer types (e.g., > 10^18).

-------------------------------------------------------------------
Method 2: Modulo Arithmetic (Optimal Approach)
- Intuition: Same mathematical property as Method 1, but extracting digits mathematically avoids the overhead of string allocation.
- Approach: Continuously take n % 10 to get the last digit, update the maximum digit found so far, and divide n by 10 to shift the digits right. Stop when n becomes 0.
- Dry Run (n = 121):
  - n % 10 = 1, max_digit = 1, n = 12
  - n % 10 = 2, max_digit = 2, n = 1
  - n % 10 = 1, max_digit = 2, n = 0
  - Answer = 2.
- Time Complexity: O(D) where D is the number of digits in n. Since n <= 10^9, D <= 10, so effectively O(1).
- Space Complexity: O(1), entirely in-place.
- Why better than previous method: Avoids string parsing and dynamic memory allocation; uses pure mathematical operations.
- When to use: For standard CP problems where n fits within 32-bit or 64-bit integers.

Comparison Table:
Method             | TC   | SC   | Best Use Case
---------------------------------------------------------
1. String          | O(D) | O(D) | Extremely large numbers (BigInt)
2. Modulo Math     | O(D) | O(1) | Standard CP constraints (n <= 10^9)

Final Recommended Solution: Method 2 (Modulo Arithmetic) is slightly more optimal in terms of space and standard practice for numerical manipulation in C++.
*/

#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    int max_digit = 0;
    
    // Extract digits one by one to find the maximum digit
    while (n > 0) {
        int current_digit = n % 10;
        max_digit = max(max_digit, current_digit);
        
        // If we hit 9, we can break early as no digit can be larger
        if (max_digit == 9) {
            break;
        }
        
        n /= 10;
    }
    
    cout << max_digit << "\n";
}

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    
    // Handle multiple test cases
    while (t--) {
        solve();
    }

    return 0;
}
