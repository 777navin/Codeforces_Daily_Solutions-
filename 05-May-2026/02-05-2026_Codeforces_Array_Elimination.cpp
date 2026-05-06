/*
Date: 02-05-2026
Problem Name: A. Array Elimination
Platform: Codeforces (Round 751 Div. 1)
Difficulty: 1000
Tags: Bitmask, Greedy, Math, Number Theory

Problem Summary:
Given an array of n non-negative integers. An "elimination" operation with parameter k 
consists of:
1. Choosing k distinct indices.
2. Calculating x = a[i1] & a[i2] & ... & a[ik].
3. Subtracting x from each of the k chosen elements.
Goal: Find all possible values of k (1 <= k <= n) such that we can make all elements 0.

Methods to Solve:
1. Bitwise Frequency Analysis (Optimal Approach)

---

Method 1: Bitwise Frequency Analysis
- Intuition: The bitwise AND operation (x) can only subtract a value if that specific bit 
  is present in ALL k chosen elements. To eliminate a specific bit position (say the i-th bit) 
  from the entire array, we must be able to pick k elements that have that bit set, repeatedly, 
  until the total count of that bit across the array reaches 0.
- Approach: 
  1. Count the frequency of each bit (from 0 to 29) across all elements in the array.
  2. Let `cnt[i]` be the number of elements where the i-th bit is set.
  3. For a value k to be valid, k must be a divisor of the Greatest Common Divisor (GCD) 
     of all non-zero `cnt[i]` values. 
  4. If all `cnt[i]` are 0, all k from 1 to n are valid.
- Dry Run:
  Array: [13, 7, 25, 19] (Binary: 01101, 00111, 11001, 10011)
  Bit 0: Count 4 | Bit 1: Count 2 | Bit 2: Count 2 | Bit 3: Count 2 | Bit 4: Count 2
  GCD(4, 2, 2, 2, 2) = 2.
  Possible k: Divisors of 2 -> {1, 2}.
- Time Complexity: O(n * 30 + GCD_log) per test case.
- Space Complexity: O(30) to store bit counts.
- Why better: This is the only efficient way to handle n up to 200,000.
- When to use: Always, for bitwise subtraction/elimination problems.

Comparison Table:
Method             | TC         | SC   | Best Use Case
-------------------------------------------------------
Bit Frequency + GCD| O(N * 30)  | O(1) | Optimal / CP Standard

Final Recommended Solution: Bitwise Frequency Analysis with Fast I/O.
*/

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

/**
 * @brief Fast I/O and Logic for Codeforces competitive programming.
 */
using namespace std;

// Standard GCD function (C++17 has std::gcd)
long long calculate_gcd(long long a, long long b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

void solve() {
    int n;
    if (!(cin >> n)) return;
    
    vector<int> a(n);
    vector<int> bit_counts(31, 0);
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        for (int bit = 0; bit < 31; ++bit) {
            if ((a[i] >> bit) & 1) {
                bit_counts[bit]++;
            }
        }
    }
    
    int common_gcd = 0;
    for (int i = 0; i < 31; ++i) {
        common_gcd = std::gcd(common_gcd, bit_counts[i]);
    }
    
    // If common_gcd is 0, all elements are already 0, so all k work.
    // Otherwise, all divisors of the GCD are valid k values.
    for (int k = 1; k <= n; ++k) {
        if (common_gcd == 0 || common_gcd % k == 0) {
            cout << k << " ";
        }
    }
    cout << "\n";
}

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
