/*
Date: 03-06-2026
Problem Name: A. Equality
Platform: Codeforces
Difficulty: 800
Tags: Strings, Implementation, Greedy

Problem Summary:
You are given a string `s` of length `n` containing only the first `k` uppercase letters of the English alphabet. You need to find the length of the longest "good" subsequence, where a subsequence is considered good if every character from the first `k` letters of the alphabet appears an equal number of times.

Methods to Solve:
1. Optimal Approach (Frequency Counting)

---
Method 1: Optimal Approach (Frequency Counting)
- Intuition:
  To make a subsequence where all `k` letters appear exactly the same number of times, the maximum number of times any character can appear is restricted by the character that appears the least frequently in the original string. The minimum frequency acts as a bottleneck.
  
- Approach:
  1. Initialize an array of size `k` to store the frequency of each of the first `k` characters.
  2. Iterate over the string `s` and increment the count for each character.
  3. Find the minimum frequency value across all `k` characters.
  4. The maximum possible length of the good subsequence is this minimum frequency multiplied by `k`.

- Dry Run (n=9, k=3, s="ACAABCCAB"):
  - Read `s`, iterate characters.
  - Frequencies: 'A' -> 4, 'B' -> 2, 'C' -> 3
  - Minimum frequency among first 3 letters = min(4, 2, 3) = 2
  - Answer = 2 * 3 = 6

- Time Complexity: O(n + k). It takes O(n) to iterate through the string to count frequencies, and O(k) to find the minimum frequency. 
- Space Complexity: O(k). We use an array of size `k` to store the frequencies. Space is very minimal (at most 26 integers).
- Why better than previous method: This is the most optimal linear-time direct mathematical approach.
- When to use: When a problem involves balancing items based on the limiting (minimum) factor.

Comparison Table:
Method             | TC       | SC   | Best Use Case
Optimal Approach   | O(n + k) | O(k) | Best for any scale of inputs within constraints.

Final Recommended Solution: Optimal Approach (Frequency Counting)
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    // Array to store the frequencies of the first k uppercase letters
    vector<int> freq(k, 0);

    // Count frequencies of each character
    for (char c : s) {
        freq[c - 'A']++;
    }

    // Find the minimum frequency among the first k letters
    int min_freq = freq[0];
    for (int i = 1; i < k; i++) {
        min_freq = min(min_freq, freq[i]);
    }

    // The longest good subsequence length
    cout << min_freq * k << "\n";
}

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // This specific problem (Codeforces 1038A) has single testcase per execution
    // If it required multiple testcases, we would wrap this in a while(t--) loop.
    solve();

    return 0;
}
