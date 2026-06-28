/*
Date: 28-06-2026
Problem Name: k-th divisor
Platform: Codeforces
Difficulty: 1400
Tags: Math, Number Theory, Sorting

Problem Summary:
Given two integers n and k (1 <= n <= 10^15, 1 <= k <= 10^9), find the k-th smallest divisor of n. 
If the number of divisors is less than k, output -1.

Methods to Solve:
1. Brute Force (Iterate 1 to n):
   - Intuition: Check every number from 1 to n.
   - Time Complexity: O(n) - Too slow for n=10^15.

2. Optimal Approach (Iterate up to sqrt(n)):
   - Intuition: Divisors always come in pairs. If 'i' is a divisor, then 'n/i' is also a divisor. 
     By iterating up to sqrt(n), we can collect all divisors efficiently.
   - Approach: 
     a. Iterate i from 1 to sqrt(n).
     b. If i divides n:
        - Add 'i' to a list.
        - If 'i*i != n', add 'n/i' to the list.
     c. Sort the list of divisors.
     d. If list size < k, return -1, else return the (k-1)-th element.
   - Time Complexity: O(sqrt(n))
   - Space Complexity: O(number of divisors)

Comparison Table:
Method | TC | SC | Best Use Case
-------|----|----|--------------
Brute Force | O(n) | O(1) | Small n
Optimal | O(sqrt(n)) | O(d(n)) | Large n (up to 10^15)

Final Recommended Solution: Optimal Approach (O(sqrt(n)))
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

void solve() {
    ll n, k;
    if (!(cin >> n >> k)) return;

    vector<ll> divisors;

    // Iterate up to sqrt(n) to find all divisors
    for (ll i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (i * i != n) {
                divisors.push_back(n / i);
            }
        }
    }

    // Sort divisors to find the k-th smallest
    sort(divisors.begin(), divisors.end());

    if (k > divisors.size()) {
        cout << -1 << endl;
    } else {
        cout << divisors[k - 1] << endl;
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
