/*
File Name: 23-04-2026_Codeforces_822A_Im_Bored_With_Life.cpp

Date: 23-04-2026
Problem Name: I'm bored with life
Platform: Codeforces
Contest: Codeforces Round
Problem Code: 822A
Difficulty: Easy
Tags: Math, GCD, Factorial, Observation

======================================================================
Problem Summary:

Given two integers A and B.

Find:

GCD(A!, B!)

Where:
x! = 1 * 2 * 3 * ... * x

Need to print the greatest common divisor of factorials.

Constraints:
1 <= A, B <= 1e9
min(A, B) <= 12

======================================================================
Key Observation:

Assume:
A <= B

Then:

A! divides B!

Because B! contains:
1 * 2 * 3 * ... * A * ... * B

So every factor of A! exists inside B!

Therefore:

GCD(A!, B!) = A!

More generally:

GCD(A!, B!) = min(A, B)!

So we only need factorial of min(A, B)

======================================================================
Methods to Solve:

1. Brute Force
- Compute A!, B!
- Compute gcd
- Works only for tiny values

2. Optimal Observation
- Answer = factorial(min(A, B))

Since min(A,B) <= 12, factorial easily fits in 32-bit / 64-bit.

======================================================================
Dry Run:

Input:
4 3

min = 3

3! = 1 * 2 * 3 = 6

Answer = 6

----------------------------------------------------------------------

Input:
5 5

min = 5

5! = 120

Answer = 120

======================================================================
Complexity:

Time  : O(min(A,B))
Space : O(1)

======================================================================
Final Recommended Solution:
Compute factorial of min(A,B)

======================================================================
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long A, B;
    cin >> A >> B;

    long long n = min(A, B);

    long long ans = 1;
    for (long long i = 1; i <= n; i++) {
        ans *= i;
    }

    cout << ans << '\n';

    return 0;
}
