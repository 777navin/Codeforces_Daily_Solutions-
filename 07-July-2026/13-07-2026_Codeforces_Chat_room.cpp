/*
=========================================================
Date        : 13-07-2026
Problem Name: A. Chat room
Platform    : Codeforces
Difficulty  : 1000
Tags        : Greed, Strings

Problem Summary:
Vasya types a word and wants to see if he managed to say "hello". 
It is considered a success if we can delete some characters from 
his typed string to form the exact sequence "hello".

Key Observation:
We need to check if "hello" exists as a subsequence within the 
given string, preserving the relative order of the characters.
=========================================================
*/

#include <iostream>
#include <string>

using namespace std;

/*
---------------------------------------------------------
Approach 1: Two-Pointer Subsequence Matching (Optimal)
---------------------------------------------------------
• Intuition:
  We can sequentially look for the characters 'h', 'e', 'l', 'l', 'o' 
  in the given string. If we find the current target character, we move 
  our target pointer to the next character of "hello".

• Approach:
  Maintain a pointer index for the target string "hello". Iterate through 
  each character of the input string. If the current character matches 
  target[index], increment index. If index reaches 5, "hello" is found.

• Why it Works:
  Since we only advance the target pointer when a match is found sequentially, 
  it correctly validates if "hello" is a subsequence of the input string.

• Time Complexity (TC) : O(N), where N is the length of the string (up to 100).
• Space Complexity (SC): O(1), as we only use a few tracking variables.
---------------------------------------------------------
*/

/*
Final Approach Choice:
This approach is chosen because it directly solves the problem in a single pass 
with optimal O(N) time complexity and minimal memory usage. No complex data structures 
or multi-pass algorithms are required.
*/

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    if (cin >> s) {
        string target = "hello";
        int target_ptr = 0;

        // Iterate through the input string to find the subsequence
        for (char c : s) {
            if (c == target[target_ptr]) {
                target_ptr++;
            }
            // If we matched all 5 characters of "hello", we can stop early
            if (target_ptr == 5) {
                break;
            }
        }

        // Output results based on whether the whole target string was matched
        if (target_ptr == 5) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
