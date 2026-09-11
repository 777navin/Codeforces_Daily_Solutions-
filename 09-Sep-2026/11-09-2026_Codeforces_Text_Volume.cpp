/*
=========================================================
Date        : 11-09-2026
Problem Name: Text Volume
Platform    : Codeforces
Difficulty  : 800
Tags        : implementation, strings

Problem Summary:
Given an integer n denoting the length of a string containing space-separated words.
The volume of a word is defined as the count of uppercase Latin letters in it.
Find and output the maximum volume among all words in the text.

Key Observation:
Since words are separated by spaces, reading word-by-word naturally isolates each word.
The answer is simply the maximum count of uppercase letters found in any single word.
=========================================================
*/

/*
=========================================================
APPROACH 1: Token-by-Token Linear Scan (Optimal)
=========================================================
• Intuition:
  Input consists of words separated by spaces. Reading tokens one by one using 
  standard input stream splits the words automatically without manual parsing.

• Approach:
  1. Read the length n.
  2. While reading individual words (strings) from input, count uppercase letters in each word.
  3. Track and update the maximum count seen across all words.
  4. Output the maximum count.

• Why it Works:
  Standard formatted input `cin >> word` discards whitespace delimiters, perfectly 
  isolating each word to inspect character by character.

• Time Complexity (TC):
  O(n) - Every character of the text of length n is processed exactly once.

• Space Complexity (SC):
  O(L) - Storing one word at a time, where L <= n is the maximum word length.
=========================================================
*/

/*
=========================================================
FINAL APPROACH CHOICE:
Token-by-token stream parsing is chosen because it avoids manual index tracking,
handles arbitrary whitespace cleanly, and achieves the theoretical lower bound 
of O(n) time and minimal auxiliary space.
=========================================================
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int main() {
    fast_io();

    int n;
    if (!(cin >> n)) return 0;

    int max_volume = 0;
    string word;

    // Read word by word until the stream ends
    while (cin >> word) {
        int current_volume = 0;
        for (char ch : word) {
            if (isupper(static_cast<unsigned char>(ch))) {
                current_volume++;
            }
        }
        max_volume = max(max_volume, current_volume);
    }

    cout << max_volume << "\n";

    return 0;
}
