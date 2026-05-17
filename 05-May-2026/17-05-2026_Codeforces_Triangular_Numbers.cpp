/*
Date: 17-05-2026
Problem Name: Triangular numbers (47A)
Platform: Codeforces
Difficulty: 800 (Easy)
Tags: Math, Brute Force

Problem Summary
A triangular number is the number of dots in an equilateral triangle uniformly filled with dots. 
The n-th triangular number is given by the formula: T_n = (n * (n + 1)) / 2.
Given an integer 'n' (1 <= n <= 500), determine if it is a triangular number. 
Output "YES" if it is, otherwise output "NO".

Methods to Solve:
1. Brute Force (Simulation / Linear Search)
2. Mathematical Approach (Using Quadratic Equation / Perfect Square check)

--------------------------------------------------------------------------------

Method 1: Brute Force (Simulation / Linear Search)
- Intuition: 
  Since the maximum value of 'n' is very small (n <= 500), we can actively generate 
  triangular numbers starting from i = 1 onwards. If any generated triangular number 
  matches 'n', then 'n' is a triangular number. If the generated value exceeds 'n', 
  we can stop and conclude it's not.
  
- Approach:
  Initialize a loop with a variable 'i' starting from 1. In each iteration, compute 
  the value term = (i * (i + 1)) / 2. If term == n, return true. If term > n, break 
  and return false.

- Dry Run (n = 3):
  i = 1: term = (1 * 2) / 2 = 1 (1 < 3, continue)
  i = 2: term = (2 * 3) / 2 = 3 (3 == 3, match found -> YES)

- Time Complexity: O(sqrt(n)) 
  The loop runs at most around sqrt(2 * n) times because the values grow quadratically.
- Space Complexity: O(1)
  Only a few primitive variables are used.
- Why better than previous method: N/A (Baseline approach)
- When to use: Ideal when the constraints on 'n' are small (like n <= 500).

--------------------------------------------------------------------------------

Method 2: Mathematical Approach
- Intuition:
  We are given an equation: (x * (x + 1)) / 2 = n
  Multiplying both sides by 8 gives: 4*x^2 + 4*x = 8*n
  Adding 1 to both sides completes the square: 4*x^2 + 4*x + 1 = 8*n + 1
  Which simplifies to: (2*x + 1)^2 = 8*n + 1
  Therefore, 'n' is a triangular number if and only if (8 * n + 1) is a perfect square.

- Approach:
  1. Calculate target = 8 * n + 1.
  2. Find the integer square root of target: r = sqrt(target).
  3. Check if r * r == target. If it matches, output "YES", otherwise "NO".

- Dry Run (n = 3):
  target = 8 * 3 + 1 = 25
  r = sqrt(25) = 5
  5 * 5 == 25 (True -> YES)

- Time Complexity: O(1) 
  Utilizes the built-in `sqrt` function which executes in constant time on modern hardware.
- Space Complexity: O(1)
  No extra space needed.
- Why better than previous method: It avoids any iterative searching or looping, solving the query directly.
- When to use: Best when 'n' can be very large, up to 10^18 (using 64-bit integers).

--------------------------------------------------------------------------------

Comparison Table:
Method             | TC        | SC   | Best Use Case
--------------------------------------------------------------------------------
Brute Force        | O(sqrt(n))| O(1) | Small constraints (n <= 500)
Math (Perfect Sq)  | O(1)      | O(1) | Large scale constraints (up to 10^18)

Final Recommended Solution:
Method 2 (Mathematical Approach) is selected for production readiness as it runs in constant 
time and scales effortlessly if constraints increase.
*/

#include <iostream>
#include <cmath>

using namespace std;

// Fast I/O Configuration
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

/**
 * @brief Determines if a number is a triangular number using the mathematical discriminant approach.
 * @param n The integer to be checked.
 * @return true if n is a triangular number, false otherwise.
 */
bool isTriangular(long long n) {
    long long target = 8 * n + 1;
    long long root = round(sqrt(target));
    
    return (root * root == target);
}

int main() {
    // Optimize standard I/O operations for competitive programming
    fast_io();
    
    long long n;
    if (cin >> n) {
        if (isTriangular(n)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}
