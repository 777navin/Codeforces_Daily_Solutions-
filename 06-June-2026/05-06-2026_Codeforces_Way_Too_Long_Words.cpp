// File: 05-06-2026_Codeforces_Way_Too_Long_Words.cpp

/*
Date: 05-06-2026
Problem Name: Way Too Long Words
Platform: Codeforces
Difficulty: 800
Tags: Strings

Problem Summary:
Given a list of words, if a word's length is strictly greater than 10, replace it with an 
abbreviation consisting of the first letter, the count of characters between the first 
and last letters, and the last letter. Otherwise, keep the word as is.

Methods to Solve:
1. Direct Simulation: Check the length of the string, and if > 10, construct 
   the abbreviation using string indexing and length.

For Method 1 (Direct Simulation):
- Intuition: Simple string manipulation based on length conditions.
- Approach: Read the string, check length. If length > 10, print s[0], length-2, s[last].
- Dry Run: "internationalization" (len 20) -> 'i' + "18" + 'n' -> "i18n".
- Time Complexity: O(n) where n is the total number of characters across all words.
- Space Complexity: O(1) (excluding storage for the input string).
- Why better: It is the optimal way to process the requirement directly.
- When to use: Always, given the constraints.

Comparison Table:
Method | TC | SC | Best Use Case
-------|----|----|--------------
Direct | O(N) | O(1) | Standard string processing

Final Recommended Solution: Simple string manipulation with conditional logic.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Function to process and print the word based on Codeforces rules.
 */
void solve() {
    string word;
    cin >> word;

    if (word.length() > 10) {
        // Print first char, the middle count, and the last char
        cout << word.front() << (word.length() - 2) << word.back() << "\n";
    } else {
        // Print the word as it is
        cout << word << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    while (n--) {
        solve();
    }

    return 0;
}
