/*
=========================================================
Date        : 23-07-2026
Problem Name: Put Knight!
Platform    : Codeforces
Difficulty  : 1400
Tags        : Games, Math

Problem Summary:
Petya and Gena play a game on an n x n chessboard placing knights such that 
no two knights attack each other. Moves alternate starting with Petya. 
The player who cannot place a knight loses. Determine who wins for a given n.

Key Observation:
For an even board (n % 2 == 0), the second player (Gena, output 1) can always mirror 
the first player's move across the center. For an odd board (n % 2 == 1), the first 
player (Petya, output 0) takes the center square on move 1 and then mirrors Gena's moves.
Note: This problem specifically requires reading from input.txt and writing to output.txt.
=========================================================
*/

#include <iostream>
#include <cstdio>

using namespace std;

/*
=========================================================
Approach 1: Parity / Mirroring Strategy with File I/O
=========================================================

• Intuition:
  - Mirroring strategy guarantees a win: second player wins for even n, first player for odd n.
  - Unlike standard Codeforces problems, this problem mandates reading from input.txt 
    and writing to output.txt in both local and online environments.

• Approach:
  - Unconditionally redirect stdin/stdout to "input.txt" and "output.txt" using freopen.
  - Read integer T (number of test cases).
  - For each test case n: if n is even print 1, else print 0.

• Why it Works:
  - Symmetric strategy holds for all board sizes.
  - Removing `#ifndef ONLINE_JUDGE` around `freopen` satisfies the judge's requirement 
    for file-based I/O on Codeforces test servers.

• Time Complexity (TC) : O(1) per testcase.
• Space Complexity (SC): O(1) auxiliary space.
*/

/*
=========================================================
Final Approach Choice
=========================================================
- Mathematical parity check (n % 2 == 0) gives the correct answer in O(1).
- Unconditional file I/O redirection is required because Codeforces expects output.txt 
  to be generated directly on their judging servers.
*/

void solve() {
    int n;
    if (!(cin >> n)) return;
    if (n % 2 == 0) {
        cout << 1 << "\n";
    } else {
        cout << 0 << "\n";
    }
}

int main() {
    // Redirect standard I/O to files as mandated by Problem 120E
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }

    return 0;
}
