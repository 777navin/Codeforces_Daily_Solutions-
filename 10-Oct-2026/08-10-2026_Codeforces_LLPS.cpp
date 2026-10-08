/*
=========================================================
Date        : 08-10-2026
Problem Name: Lexicographically Largest Palindromic Subsequence (LLPS)
Platform    : Codeforces
Difficulty  : 800
Tags        : Strings, Greedy, Implementation

Problem Summary:
Given a string 's' of lowercase English letters, find its 
lexicographically largest palindromic subsequence.
The output string must be read the same forward and backward while
being as large as possible in lexicographical order.

Key Observation:
To maximize the string lexicographically, we only need to pick the 
largest character present in the string and repeat it as many times 
as it appears. Any single repeated character forms a palindrome.
=========================================================
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/*
---------------------------------------------------------
APPROACH 1: Brute Force (Generate All Subsequences)
---------------------------------------------------------
• Intuition:
  Generate all $2^N$ subsequences, check if each is a palindrome,
  and track the lexicographically largest one.

• Approach:
  Iterate through all bitmasks from $1$ to $2^N - 1$. Construct each
  subsequence, test if it is a palindrome, and update the answer string.

• Why it Works:
  It explores the complete search space, guaranteeing that the maximum
  palindromic subsequence is found.

• Time Complexity (TC):
  $O(2^N \times N)$, where $N$ is the length of string $s$.

• Space Complexity (SC):
  $O(N)$ for storing string subsequences.
---------------------------------------------------------
*/

/*
---------------------------------------------------------
APPROACH 2: Greedy (Frequency of Maximum Character) - Optimal
---------------------------------------------------------
• Intuition:
  A string made entirely of a single repeated character (e.g., "zzz")
  is always a palindrome. To maximize lexicographically, we must start
  with the largest character in the input string.

• Approach:
  Find the maximum character $c$ in string $s$, count its occurrences $K$,
  and output $c$ repeated $K$ times.

• Why it Works:
  Any palindrome containing a character smaller than the maximum character
  will be lexicographically smaller than a palindrome consisting solely of
  the maximum character.

• Time Complexity (TC):
  $O(N)$ to iterate through string $s$.

• Space Complexity (SC):
  $O(1)$ auxiliary space.
---------------------------------------------------------
*/

/*
=========================================================
FINAL APPROACH CHOICE: Greedy (Approach 2)
=========================================================
• Approach 2 is chosen because $N \le 10$, and finding the maximum character
  and its frequency directly solves the problem in optimal linear time $O(N)$.
• It completely avoids exponential work $O(2^N \times N)$ required by Brute Force.
=========================================================
*/

void solve() {
    string s;
    if (!(cin >> s)) return;

    char max_char = 'a';
    for (char c : s) {
        if (c > max_char) {
            max_char = c;
        }
    }

    int count = 0;
    for (char c : s) {
        if (c == max_char) {
            count++;
        }
    }

    cout << string(count, max_char) << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}08-10-2026_Codeforces_LLPS.cpp
