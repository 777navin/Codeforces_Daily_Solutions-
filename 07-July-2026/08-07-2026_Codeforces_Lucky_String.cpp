/*
=========================================================
Date        : 08-07-2026
Problem Name: Lucky String (110B)
Platform    : Codeforces
Difficulty  : 1000
Tags        : Constructive Algorithms, Strings

Problem Summary:
Find the lexicographically minimal string of length n where the absolute difference between the indices of any two identical adjacent characters is a lucky number (e.g., 4 or 7).

Key Observation:
Since the smallest lucky number is 4, we can safely repeat a 4-character sequence. Repeating the pattern "abcd" ensures identical characters are always exactly 4 indices apart while maintaining lexicographical minimality.
=========================================================
*/

#include <iostream>
#include <string>

using namespace std;

/*
---------------------------------------------------------
Approach 1: Constructive Pattern Generation
---------------------------------------------------------
• Intuition:
  The smallest allowed distance between identical characters is 4. To get the lexicographically smallest string, we cycle through the first four English letters: 'a', 'b', 'c', and 'd'.

• Approach:
  - Use a base repeating string "abcd".
  - Loop n times, and for each position i, output the character at index `i % 4`.

• Why it Works:
  Any identical characters will have an exact distance of 4 (which is a lucky number). By strictly using the first 4 letters, the resulting string is guaranteed to be lexicographically minimal.

• Time Complexity (TC):
  - O(n) because we execute a single loop of size n to print the characters.

• Space Complexity (SC):
  - O(1) auxiliary space as we are directly printing the output and only storing a constant size pattern.
---------------------------------------------------------
*/

/*
=========================================================
FINAL APPROACH CHOICE
=========================================================
• The constructive pattern approach is chosen because it perfectly matches the mathematical property of the problem.
• It provides the most optimal O(n) time and O(1) space solution without any complex string manipulation.
=========================================================
*/

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (cin >> n) {
        string pattern = "abcd";
        for (int i = 0; i < n; ++i) {
            cout << pattern[i % 4];
        }
        cout << "\n";
    }

    return 0;
}
