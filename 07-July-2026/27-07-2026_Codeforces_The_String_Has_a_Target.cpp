/*
=========================================================
Date        : 27-07-2026
Problem Name: 1805B - The String Has a Target
Platform    : Codeforces
Difficulty  : 800
Tags        : greedy, strings

Problem Summary:
Given a string, you can choose exactly one character and move it to the beginning.
Find the lexicographically smallest string possible after exactly one such operation.

Key Observation:
To make the string as small as possible, the first character must be the smallest available.
Choosing the last occurrence of this minimum character minimizes the rest of the string.
=========================================================
*/

/*
1. Brute Force
• Intuition: Try moving every character to the front and compare all resulting strings.
• Approach: Loop through all indices, create a new string for each, and keep track of the minimum string.
• Why it Works: It exhaustively checks all valid operations.
• Time Complexity (TC): O(N^2) - N operations, each takes O(N) to build and compare.
• Space Complexity (SC): O(N) - To store intermediate strings during generation.

2. Most Optimal
• Intuition: The first character dictates the lexicographical order the most. We need the smallest character at the front.
• Approach: Find the smallest character in the string. If there are duplicates, pick the one with the highest index. Move it to the front.
• Why it Works: Moving the last occurrence of the smallest character shifts the prefix right, ensuring the smallest possible characters stay as early as possible without disrupting smaller prefixes.
• Time Complexity (TC): O(N) - Single pass to find the minimum character and another to print.
• Space Complexity (SC): O(1) - No extra space required other than basic variables.
*/

/*
Final Approach:
The Most Optimal approach is chosen because the sum of N is up to 10^5.
An O(N^2) brute force will cause a Time Limit Exceeded (TLE) error.
The greedy O(N) approach runs well within the 1-second time limit and is easy to implement.
*/

#include <iostream>
#include <string>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    // Find the index of the smallest character
    // If there are multiple, we take the one that appears last
    int min_idx = 0;
    for (int i = 1; i < n; i++) {
        if (s[i] <= s[min_idx]) {
            min_idx = i;
        }
    }

    // Print the smallest character first
    cout << s[min_idx];
    
    // Print the rest of the string, skipping the character at min_idx
    for (int i = 0; i < n; i++) {
        if (i != min_idx) {
            cout << s[i];
        }
    }
    cout << "\n";
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
