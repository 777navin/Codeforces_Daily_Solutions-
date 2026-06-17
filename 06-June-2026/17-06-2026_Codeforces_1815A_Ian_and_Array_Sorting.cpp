/*
Date: 17-06-2026
Problem Name: Ian and Array Sorting
Platform: Codeforces
Difficulty: 1300
Tags: Constructive Algorithms, Math, Greedy

Problem Summary:
Given an array of length n, you can perform an operation: choose two adjacent elements 
a[i] and a[i+1] and increase or decrease both by 1. Determine if it is possible 
to make the array non-decreasing.

Methods to Solve:
1. Mathematical Parity/Observation Approach

Intuition:
The operation preserves the alternating sum of the array. Specifically, if we look 
at the sum a[0] - a[1] + a[2] - a[3] + ... for an even n, the operation (a[i]++, a[i+1]++) 
changes the alternating sum by +1 - 1 = 0 or -1 + 1 = 0. Thus, the alternating sum is invariant.
For odd n, we can manipulate the array to be sorted if the total parity allows it.

Approach:
- If n is odd: We can always make the array non-decreasing. By performing operations, 
  we can push all "inconvenience" to the first element and balance it.
- If n is even: The alternating sum (a[0] - a[1] + a[2] - ... - a[n-1]) must be <= 0 
  to be able to make it non-decreasing.

Time Complexity: O(n) per test case
Space Complexity: O(n) to store the array

Comparison Table:
Method | TC | SC | Best Use Case
--------------------------------------
Math   | O(n) | O(n) | Optimal

Final Recommended Solution:
*/

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    if (n % 2 != 0) {
        cout << "YES" << endl;
    } else {
        long long alternating_sum = 0;
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) alternating_sum += a[i];
            else alternating_sum -= a[i];
        }
        
        if (alternating_sum <= 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
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
