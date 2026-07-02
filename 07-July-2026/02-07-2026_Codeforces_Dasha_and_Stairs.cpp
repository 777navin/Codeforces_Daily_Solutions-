/*
=========================================================
Date        : 02-07-2026
Problem Name: A. Dasha and Stairs
Platform    : Codeforces
Difficulty  : 800
Tags        : math, implementation

Problem Summary:
Dasha calculates the number of even (a) and odd (b) numbered steps she encounters 
along an arbitrary contiguous interval [l, r] on a staircase numbered from 1 to infinity. 
We need to determine if there exists a valid interval [l, r] (1 <= l <= r) that contains 
exactly 'a' even steps and 'b' odd steps.

Constraints:
0 <= a, b <= 100

Key Observation:
- In any consecutive sequence of integers, the counts of even and odd numbers alternate.
- Therefore, the absolute difference between the count of even and odd numbers in a valid 
  interval can be at most 1. That is, |a - b| <= 1.
- Crucially, if both a and b are 0, it implies an empty or invalid interval since 1 <= l <= r 
  guarantees that at least one step must be counted. Thus, a = 0 and b = 0 is impossible.
=========================================================
*/

/*
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
APPROACH 1: Parity and Difference Check (Most Optimal)
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
• Intuition:
  An interval of positive integers starting at an odd or even number will either have an 
  equal number of odd and even elements, or one of them will exceed the other by exactly 1.
  
• Idea:
  Check if the absolute difference between 'a' and 'b' is less than or equal to 1. 
  Additionally, handle the edge case where both are zero, which is invalid.

• Dry Run:
  - Input: a = 2, b = 3
    |2 - 3| = 1 <= 1, and not both zero -> YES
  - Input: a = 3, b = 1
    |3 - 1| = 2 > 1 -> NO
  - Input: a = 0, b = 0
    Both zero -> NO

• Why it works:
  Any continuous block of numbers naturally forms a balance of odds and evens up to a 
  difference of 1.

• Time Complexity : O(1)
• Space Complexity: O(1)

• Advantages      : Highly efficient, handles edge cases explicitly.
• Disadvantages   : None.
• When to use     : Always, as it runs in constant time.
*/

// -------------------------------------------------------
// Method                      Idea               Time    Space   Difficulty   Recommended
// -------------------------------------------------------
// Mathematical Check          |a - b| <= 1       O(1)    O(1)    Easy         Yes
// -------------------------------------------------------

/*
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
FINAL RECOMMENDED APPROACH
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
The single mathematical condition `abs(a - b) <= 1` combined with checking that `a + b > 0` 
covers all bounds and executes instantaneously, making it the perfect submission-ready strategy.
*/

#include <iostream>
#include <cmath>

using namespace std;

void solve() {
    int a, b;
    if (cin >> a >> b) {
        // Edge case: an interval cannot have 0 elements since 1 <= l <= r
        if (a == 0 && b == 0) {
            cout << "NO\n";
        } 
        // The difference between even and odd count in a valid range can only be 0 or 1
        else if (abs(a - b) <= 1) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}

int main() {
    // Optimize standard I/O operations for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    
    return 0;
}
