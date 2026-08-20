/*
=========================================================
Date        : 20-08-2026
Problem Name: Mike and Fax (548A)
Platform    : Codeforces
Difficulty  : 1100 (Div. 2 A)
Tags        : strings, implementation, brute force

Problem Summary:
Given a string s and an integer k, determine if s can be 
split into exactly k non-overlapping palindromic substrings 
of equal length.

Key Observation:
The length of s must be evenly divisible by k; each substring 
must have length |s| / k and satisfy the palindrome property.
=========================================================
*/

/*
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
APPROACH: Direct Substring Palindrome Verification
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
• Intuition:
  - If |s| is not divisible by k, it's impossible to form k equal parts.
  - Otherwise, each segment has length L = |s| / k. We simply verify
    if all k contiguous segments are palindromes.

• Approach:
  1. Check if n % k != 0. If true, print "NO".
  2. Compute segment length L = n / k.
  3. For each segment starting at index i * L (0 <= i < k), check if 
     the substring from i * L to (i + 1) * L - 1 is a palindrome.
  4. If all k segments are palindromes, print "YES"; otherwise, print "NO".

• Why it Works:
  - The problem strictly requires equal-length segments that partition the original string in order.

• Time Complexity (TC): O(|s|) - Each character is visited at most twice during palindrome checks.
• Space Complexity (SC): O(1) - Checked in-place using indices without additional memory allocations.
*/

/*
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
FINAL APPROACH SELECTION
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
This approach directly checks the problem constraints in optimal linear 
time and O(1) auxiliary space, making it both minimal and most optimal.
*/

#include <iostream>
#include <string>

using namespace std;

// Function to check if substring s[left...right] is a palindrome
bool isPalindrome(const string& s, int left, int right) {
    while (left < right) {
        if (s[left] != s[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

void solve() {
    string s;
    if (!(cin >> s)) return;
    
    int k;
    cin >> k;

    int n = s.length();

    // Length must be divisible by k
    if (n % k != 0) {
        cout << "NO\n";
        return;
    }

    int segment_len = n / k;
    for (int i = 0; i < k; i++) {
        int start = i * segment_len;
        int end = start + segment_len - 1;
        if (!isPalindrome(s, start, end)) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
