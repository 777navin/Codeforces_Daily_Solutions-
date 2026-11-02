
/*
=========================================================
Date        : 02-11-2026
Problem Name: A. Newspaper Headline
Platform    : Codeforces
Difficulty  : 1500
Tags        : Greedy, Strings

Problem Summary:
- We are given two strings s1 and s2.
- We can concatenate multiple copies of s1.
- We must delete characters to obtain s2 as a subsequence.
- Find the minimum number of copies required, or -1.

Key Observation:
- Match characters of s2 from left to right in s1.
- Whenever the current copy cannot provide the next character,
  move to the next copy of s1.
=========================================================

APPROACH 1: Brute Force (Repeated Linear Search)

Intuition:
- Search for every character of s2 in the current copy of s1.

Approach:
- Scan s1 from the current position.
- If a character is unavailable, restart from the beginning.
- Count the number of copies used.

Why it Works:
- Greedily matching the earliest available character
  never makes the remaining subsequence harder to match.

TC: O(|s1| * |s2|) worst case.
SC: O(1).

---------------------------------------------------------

APPROACH 2: Optimized (Next Occurrence Table)

Intuition:
- Precompute the next occurrence of every character
  at every position in s1.

Approach:
- Build a next occurrence table for 26 lowercase letters.
- For every character in s2, find its next occurrence.
- If unavailable, increment the copy count and restart.
- Continue until all characters are matched.

Why it Works:
- Always selecting the earliest available occurrence
  maximizes the remaining positions for future characters.
- Therefore, the greedy solution uses the minimum copies.

TC: O(26 * |s1| + |s2|)
SC: O(26 * |s1|)

---------------------------------------------------------

FINAL APPROACH:
- Use the Next Occurrence Table.
- It avoids repeatedly scanning s1 for each character.
- Preprocessing takes O(26 * |s1|).
- Each character of s2 is processed in O(1).

=========================================================
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1, s2;
    cin >> s1 >> s2;

    int n = s1.size();
    int m = s2.size();

    // nextPos[i][c] = earliest position >= i
    // where character c occurs in s1.

    vector<array<int, 26>> nextPos(n + 1);

    nextPos[n].fill(-1);

    // Build the next occurrence table.
    for (int i = n - 1; i >= 0; i--) {
        nextPos[i] = nextPos[i + 1];
        nextPos[i][s1[i] - 'a'] = i;
    }

    // Check whether every required character exists.
    for (char ch : s2) {
        if (nextPos[0][ch - 'a'] == -1) {
            cout << -1 << '\n';
            return 0;
        }
    }

    int copies = 1;
    int pos = 0;

    // Greedily construct s2 as a subsequence.
    for (char ch : s2) {
        int c = ch - 'a';

        int idx = nextPos[pos][c];

        // Current copy cannot provide this character.
        if (idx == -1) {
            copies++;
            pos = 0;

            // Start searching from the next copy.
            idx = nextPos[pos][c];
        }

        // Move to the position after the matched character.
        pos = idx + 1;
    }

    cout << copies << '\n';

    return 0;
}

/*
=========================================================
Complexity Analysis:

Let:
n = length of s1
m = length of s2

Preprocessing:
O(26 * n)

Greedy Traversal:
O(m)

Total Time Complexity:
O(26 * n + m)

Space Complexity:
O(26 * n)

=========================================================
*/
