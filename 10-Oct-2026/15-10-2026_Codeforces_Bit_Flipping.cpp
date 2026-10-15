/*
=========================================================
Date        : 15-10-2026
Problem Name: Bit Flipping
Platform    : Codeforces
Difficulty  : 1300
Tags        : Greedy, Strings, Implementation

Problem Summary:
Given a binary string and exactly k moves where selecting a bit flips all other bits, 
we need to find the lexicographically largest string possible after using all k moves, 
along with the number of times each bit is selected.

Key Observation:
The number of times bit i flips is k - f[i]. Its final parity determines whether 
its initial state is inverted, and we can greedily prioritize turning bits to '1' from left to right.
=========================================================
*/

/*
=========================================================
APPROACH EXPLANATION
=========================================================

1. Greedy Approach
• Intuition:
  - To make the string lexicographically largest, we want the leftmost characters to be '1'.
• Approach:
  - Iterate from left to right. If the effective bit is '0' and we have remaining moves, spend 1 move on it.
  - Dump any leftover moves onto the last element to preserve the total move count k and correct parity.
• Why it Works:
  - Greedily fixing characters from left to right guarantees the highest possible lexicographical order.
• Time Complexity (TC): O(n) per test case
• Space Complexity (SC): O(n) to store the result string and operation counts

=========================================================
FINAL APPROACH
=========================================================
- The greedy approach is chosen because making optimal local choices from left to right 
  achieves the global maximum lexicographical string in linear time.
- It is much more efficient than brute force, fitting comfortably within the time limits for large inputs.
=========================================================
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve() {
    int n;
    long long k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<int> ans(n, 0);
    long long rem = k;

    // Greedily pick elements from left to right to maximize '1's
    for (int i = 0; i < n - 1 && rem > 0; ++i) {
        int original = s[i] - '0';
        int current = original ^ (k % 2);
        if (current == 0) {
            ans[i] = 1;
            rem--;
        }
    }

    // Add all remaining moves to the last element
    ans[n - 1] += rem;

    // Construct the final string based on total flips for each bit
    string final_s = "";
    for (int i = 0; i < n; ++i) {
        int flips = k - ans[i];
        int bit = (s[i] - '0') ^ (flips % 2);
        final_s += to_string(bit);
    }

    // Output results
    cout << final_s << "\n";
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
