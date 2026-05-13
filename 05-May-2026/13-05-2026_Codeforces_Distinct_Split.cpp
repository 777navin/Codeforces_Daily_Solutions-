/*
Date: 13-05-2026
Problem Name: Distinct Split
Platform: Codeforces
Difficulty: 1000
Tags: Strings, Greedy, Hashing

Problem Summary:
We need to split a string 's' into two non-empty parts 'a' and 'b' to maximize 
the sum of unique characters in both parts: f(a) + f(b).

Methods to Solve:

1. Brute Force (Naive)
- Intuition: Check every possible split point.
- Approach: For every index i from 1 to n-1, split the string and count distinct chars using a set.
- Dry Run: For "aabb", split at "a"|"abb" (1+2=3), "aa"|"bb" (1+1=2), "aab"|"b" (2+1=3). Result: 3.
- Time Complexity: O(N^2)
- Space Complexity: O(N)
- Why better than previous method: N/A
- When to use: Never for N = 2e5. It will TLE.

2. Optimal (Two-Pass Frequency Arrays)
- Intuition: Instead of re-counting for every split, maintain two frequency maps and "shift" 
  characters from the right part to the left part.
- Approach: 
  1. Count total frequency of all chars in a 'right' array.
  2. Iterate through the string, adding the current char to 'left' and removing from 'right'.
  3. Keep track of 'distinct' counts for both sides in real-time.
  4. Track the maximum sum observed.
- Dry Run: "abcabcd" -> Start with Right:{a:2, b:2, c:2, d:1}, Left:{}. 
  Move 'a': Left{a:1}, Right{a:1, b:2, c:2, d:1} -> Sum: 1 + 4 = 5.
  Move 'b': Left{a:1, b:1}, Right{a:1, b:1, c:2, d:1} -> Sum: 2 + 4 = 6... and so on.
- Time Complexity: O(N)
- Space Complexity: O(1) (We only store 26 characters).
- Why better than previous method: Huge performance jump from O(N^2) to O(N).
- When to use: Best for string problems involving distinct counts and split points.

Comparison Table:
Method         | TC   | SC   | Best Use Case
--------------------------------------------------
Brute Force    | O(N^2)| O(N) | N < 1000
Two Frequency  | O(N)  | O(1) | Competitive Programming / Large N

Final Recommended Solution:
The Optimal O(N) approach is used here because the sum of N is 2*10^5.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Fast I/O for better performance in contests
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    // We only have 26 lowercase letters, so arrays are faster than maps
    vector<int> left_freq(26, 0), right_freq(26, 0);
    int distinct_l = 0, distinct_r = 0;

    // Fill the right side first
    for (char c : s) {
        if (right_freq[c - 'a'] == 0) distinct_r++;
        right_freq[c - 'a']++;
    }

    int ans = 0;
    
    // Slide the split point from left to right
    // Stop at n-1 because 'b' cannot be empty
    for (int i = 0; i < n - 1; i++) {
        int char_idx = s[i] - 'a';

        // Add s[i] to the left part
        if (left_freq[char_idx] == 0) distinct_l++;
        left_freq[char_idx]++;

        // Remove s[i] from the right part
        right_freq[char_idx]--;
        if (right_freq[char_idx] == 0) distinct_r--;

        // Update the max sum of distinct characters
        ans = max(ans, distinct_l + distinct_r);
    }

    cout << ans << "\n";
}

int main() {
    fast_io();
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
