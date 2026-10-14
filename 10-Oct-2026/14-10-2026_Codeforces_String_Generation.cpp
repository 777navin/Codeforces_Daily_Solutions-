/*
=========================================================
Date        : 14-10-2026
Problem Name: A. String Generation
Platform    : Codeforces
Difficulty  : 800
Tags        : Constructive Algorithms, Strings

Problem Summary:
- Given string length n and maximum palindrome length limit k.
- Generate a string of length n using only characters 'a', 'b', and 'c'.
- Ensure no substring is a palindrome of length strictly greater than k.

Key Observation:
- Since k >= 1, printing a repeating pattern like "abc" will never create a palindrome substring of length greater than 3.
- Thus, simply cycling through 'a', 'b', and 'c' for length n always satisfies the condition for any valid k.
=========================================================
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    
    // Intuition:
    // - To prevent any palindrome substring from exceeding length k, we can print characters in a cyclic pattern.
    // - Since the minimum possible value of k is 1, repeating characters like "abc" ensures that no palindromic substring exceeds length 3, which is always <= k.
    
    // Approach:
    // - Loop from i = 0 to n - 1.
    // - Print characters by mapping index to "abc" using modulo 3.
    
    // Why it Works:
    // - Characters repeat every 3 indices, avoiding long identical sequences or palindrome blocks.
    
    // Time Complexity (TC): O(N) per test case, where N is the length of the string.
    // Space Complexity (SC): O(1) auxiliary space (excluding the output string).
    
    string s = "";
    string pattern = "abc";
    for (int i = 0; i < n; i++) {
        s += pattern[i % 3];
    }
    cout << s << "\n";
}

int main() {
    // Optimizing input/output operations for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
