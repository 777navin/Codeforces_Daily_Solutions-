/*
Date: 12-05-2026
Problem Name: Scenes From a Memory (1562B)
Platform: Codeforces
Difficulty: 1000
Tags: Number Theory, Greedy, Brute Force

Problem Summary:
Given a number 'n' (without zeros), find the shortest subsequence of digits that 
forms a non-prime number (composite or 1). It is guaranteed that such a 
subsequence exists for the given test cases.

Methods to Solve:
1. Greedy / Observation (Optimal Approach)
   - Intuition: A non-prime can be very small. We check for 1-digit non-primes 
     first, then 2-digit non-primes.
   - Approach: 
     a) Scan the string for any digit that is not prime: {1, 4, 6, 8, 9}. 
        If found, the answer is length 1.
     b) If all digits are prime {2, 3, 5, 7}, check all possible 2-digit 
        subsequences. Since 27, 33, 35, 57, 77, etc., are non-prime, and 
        the digits are limited, a 2-digit non-prime is guaranteed to exist.
   - Dry Run: 
     Input: 237
     Digits: '2', '3', '7'. None are in {1, 4, 6, 8, 9}.
     Subsequences: 23 (prime), 27 (composite! 3*9).
     Output: 2 \n 27.
   - Time Complexity: O(T * (K + 100)) where K is length of number. Since we only 
     check 1-digit and 2-digit combinations, it's effectively linear.
   - Space Complexity: O(K) to store the string.
   - Why better than previous method: This is more efficient than checking all 
     possible subsequences, as the answer is mathematically bounded to a max length of 2.
   - When to use: Always, for this specific constraint.

Comparison Table:
Method           | TC     | SC   | Best Use Case
--------------------------------------------------
Optimal (Greedy) | O(K)   | O(K) | Standard Competitive Programming

Final Recommended Solution:
The Greedy/Observation approach checking for length 1 and then length 2 is 
sufficient and optimal.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Fast I/O Setup
 */
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

/**
 * Primality test for small numbers
 */
bool is_prime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void solve() {
    int k;
    cin >> k;
    string n;
    cin >> n;

    // 1. Check for 1-digit non-primes: 1, 4, 6, 8, 9
    for (int i = 0; i < k; i++) {
        if (n[i] == '1' || n[i] == '4' || n[i] == '6' || n[i] == '8' || n[i] == '9') {
            cout << 1 << "\n";
            cout << n[i] << "\n";
            return;
        }
    }

    // 2. Check for 2-digit non-primes: 
    // Since only {2, 3, 5, 7} are left, we check pairs.
    for (int i = 0; i < k; i++) {
        for (int j = i + 1; j < k; j++) {
            int num = (n[i] - '0') * 10 + (n[j] - '0');
            if (!is_prime(num)) {
                cout << 2 << "\n";
                cout << num << "\n";
                return;
            }
        }
    }
}

int main() {
    fast_io();
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}
