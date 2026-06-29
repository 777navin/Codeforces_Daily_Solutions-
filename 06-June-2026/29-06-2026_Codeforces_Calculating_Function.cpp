/*
Date: 29-06-2026
Problem Name: Calculating Function
Platform: Codeforces
Difficulty: 800
Tags: Math, Implementation, Constructive Algorithms

Problem Summary:
Calculate f(n) = -1 + 2 - 3 + 4 - ... + (-1)^n * n for a given integer n (1 <= n <= 10^15).

Methods to Solve:
1. Iterative Approach (Brute Force)
2. Mathematical Pattern (Optimal)

For EACH method include:

- Intuition:
  1. Brute Force: Iterate from 1 to n, adding if even, subtracting if odd. O(n) time.
  2. Optimal: Observed pattern:
     n=1: -1
     n=2: 1
     n=3: -2
     n=4: 2
     n=5: -3
     If n is even, f(n) = n/2. If n is odd, f(n) = -(n+1)/2. O(1) time.

- Dry Run: 
  n=4 (even): 4/2 = 2.
  n=5 (odd): -(5+1)/2 = -3.

- Complexity:
  Method 1: TC O(n), SC O(1)
  Method 2: TC O(1), SC O(1)

Comparison Table:
Method         | TC   | SC | Best Use Case
---------------|------|----|--------------
Iterative      | O(n) | O(1)| Small n
Optimal Pattern| O(1) | O(1)| Large n (10^15)

Final Recommended Solution: Mathematical Pattern O(1)
*/

#include <iostream>

using namespace std;

void solve() {
    long long n;
    cin >> n;

    if (n % 2 == 0) {
        cout << n / 2 << endl;
    } else {
        cout << -(n + 1) / 2 << endl;
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
