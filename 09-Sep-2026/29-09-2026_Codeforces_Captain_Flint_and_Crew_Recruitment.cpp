/*
=========================================================
Date        : 29-09-2026
Problem Name: Captain Flint and Crew Recruitment (1388A)
Platform    : Codeforces
Difficulty  : 800 (Easy)
Tags        : Math, Number Theory, Constructive Algorithms

Problem Summary:
Given an integer n, determine if it can be represented as the sum of 4 
distinct positive integers such that at least 3 of them are "nearly prime" 
(a product of two distinct prime numbers). If possible, print YES and 
the 4 integers; otherwise, print NO.

Key Observation:
The smallest three nearly prime numbers are 6 (2*3), 10 (2*5), and 14 (2*7). 
Their sum is 30. Any n <= 30 cannot form a valid set, while for n > 30, we 
can start with {6, 10, 14} and let the 4th number be rem = n - 30, adjusting 
if rem matches 6, 10, or 14.
=========================================================
*/

#include <iostream>

using namespace std;

/*
---------------------------------------------------------
APPROACH 1: Constructive Choice using Smallest Nearly Primes
---------------------------------------------------------

• Intuition:
  To maximize the chance of representing n as a sum, we should pick the 
  smallest possible nearly prime integers for the first 3 numbers: 
  6 (2*3), 10 (2*5), and 14 (2*7).

• Approach:
  1. The sum of the smallest 3 nearly prime numbers is 6 + 10 + 14 = 30.
  2. If n <= 30, it is impossible to form 4 distinct positive integers, 
     so print NO.
  3. If n > 30, calculate the remaining value rem = n - 30.
  4. If rem is equal to 6, 10, or 14 (i.e., n is 36, 40, or 44), rem would 
     not be distinct. In these edge cases, replace 14 with 15 (3*5, which is 
     also nearly prime), making the fixed sum 6 + 10 + 15 = 31, and compute 
     rem = n - 31.
  5. Print YES along with the four numbers.

• Why it Works:
  Using the smallest valid nearly prime values guarantees the remainder `rem` 
  is positive for any n > 30. Handling the collision cases (rem = 6, 10, 14) 
  by shifting 14 to 15 (which changes the sum to 31 and rem to rem - 1) ensures 
  all four generated numbers remain strictly positive and distinct.

• Time Complexity (TC):
  O(1) per test case, as it involves basic arithmetic checks.

• Space Complexity (SC):
  O(1) auxiliary space used.
---------------------------------------------------------
*/

/*
---------------------------------------------------------
FINAL APPROACH
---------------------------------------------------------
The constructive approach using the smallest nearly primes {6, 10, 14} 
(or {6, 10, 15} for edge collisions) is optimal because it achieves O(1) 
time complexity per testcase and directly guarantees distinct numbers 
without brute-force searching or backtracking.
---------------------------------------------------------
*/

void solve() {
    int n;
    cin >> n;

    // Minimum possible sum using smallest 3 nearly primes (6, 10, 14) + min positive int (1) is 31
    if (n <= 30) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    int rem = n - 30;

    // Avoid duplicate numbers if rem equals one of the chosen nearly primes
    if (rem == 6 || rem == 10 || rem == 14) {
        // Use {6, 10, 15} instead (Sum = 31)
        cout << "6 10 15 " << n - 31 << "\n";
    } else {
        // Use {6, 10, 14} (Sum = 30)
        cout << "6 10 14 " << rem << "\n";
    }
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
