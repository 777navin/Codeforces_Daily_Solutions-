/*
=========================================================
Date        : 16-08-2026
Problem Name: D. Table with Letters - 2
Platform    : Codeforces (Round 154 Div. 2, Problem 253D)
Difficulty  : 2000
Tags        : 2D Prefix Sum, Two Pointers, Sliding Window, Combinatorics

Problem Summary:
Given an n x m matrix of lowercase letters, find the number of subtables 
defined by top-left (r1, c1) and bottom-right (r2, c2) with r1 < r2 and c1 < c2 
such that all four corner characters are equal and the subtable contains at most k 'a' characters.
Note: Requires file I/O (input.txt, output.txt).

Key Observation:
Fix the top row r1 and bottom row r2 (O(n^2) pairs). For a fixed pair of rows, 
a column c can serve as a corner column only if grid[r1][c] == grid[r2][c].
Using a 2D prefix sum of 'a's, the count of 'a's in columns [c1, c2] is monotonic with respect to c2, 
allowing a two-pointer / sliding window approach to count valid pairs (c1, c2) in O(m).
=========================================================
*/

/*
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
APPROACH 1: Brute Force
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
• Intuition:
  Iterate over all possible pairs of top-left and bottom-right corners (r1, c1) and (r2, c2).
• Approach:
  Four nested loops for r1, r2, c1, c2; check if corners match and count 'a's inside.
• Why it Works:
  Directly checks all potential subtables against constraints.
• Time Complexity (TC): O(n^2 * m^2) - TLE for n, m <= 400
• Space Complexity (SC): O(1) auxiliary

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
APPROACH 2: Prefix Sum + Sliding Window (Optimal)
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
• Intuition:
  Fix row boundaries (r1, r2). Use 2D prefix sums for O(1) query of 'a's in any subrectangle.
  Use a sliding window (two pointers) over valid columns where grid[r1][c] == grid[r2][c].
• Approach:
  1. Precompute 2D prefix sums for count of 'a'.
  2. Iterate over all pairs (r1, r2) with 1 <= r1 < r2 <= n.
  3. Maintain a sliding window [L, R] across columns 1 to m.
  4. For each column R where grid[r1][R] == grid[r2][R], shrink L until 'a's in subtable <= k.
  5. Add frequency of matching character from active window to answer, then increment frequency of grid[r1][R].
• Why it Works:
  The number of 'a's is monotonically increasing as the right column expands, satisfying sliding window conditions.
• Time Complexity (TC): O(n^2 * m) -> ~400 * 400 * 400 / 2 = 3.2 * 10^7 operations (runs comfortably within 2s).
• Space Complexity (SC): O(n * m) for storing the grid and prefix sum table.
*/

/*
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
FINAL APPROACH SELECTION:
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
We implement the 2D Prefix Sum + Sliding Window approach (Approach 2).
It reduces the time complexity from O(n^2 * m^2) to O(n^2 * m), which easily passes 
within the time limit for n, m <= 400. File I/O via freopen is used as required by the problem.
*/

#include <iostream>
#include <vector>
#include <string>
#include <cstdio>

using namespace std;

static const int MAXN = 405;
int pref[MAXN][MAXN];
char grid[MAXN][MAXN];

// Returns the number of 'a's in rectangle (r1, c1) to (r2, c2)
inline int get_count(int r1, int c1, int r2, int c2) {
    return pref[r2][c2] - pref[r1 - 1][c2] - pref[r2][c1 - 1] + pref[r1 - 1][c1 - 1];
}

void solve() {
    int n, m, k;
    if (!(cin >> n >> m >> k)) return;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> grid[i][j];
            pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + (grid[i][j] == 'a' ? 1 : 0);
        }
    }

    long long total_subtables = 0;
    int freq[26];

    for (int r1 = 1; r1 < n; ++r1) {
        for (int r2 = r1 + 1; r2 <= n; ++r2) {
            for (int ch = 0; ch < 26; ++ch) {
                freq[ch] = 0;
            }

            int L = 1;
            for (int R = 1; R <= m; ++R) {
                // If column R has matching top and bottom letters
                if (grid[r1][R] == grid[r2][R]) {
                    // Shrink window from the left until the count of 'a's is <= k
                    while (L < R && get_count(r1, L, r2, R) > k) {
                        if (grid[r1][L] == grid[r2][L]) {
                            freq[grid[r1][L] - 'a']--;
                        }
                        L++;
                    }

                    // If valid subtable condition holds with previous matching columns
                    if (get_count(r1, L, r2, R) <= k) {
                        int char_idx = grid[r1][R] - 'a';
                        total_subtables += freq[char_idx];
                        freq[char_idx]++;
                    }
                }
            }
        }
    }

    cout << total_subtables << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Problem requires file I/O: input.txt and output.txt
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    solve();

    return 0;
}
