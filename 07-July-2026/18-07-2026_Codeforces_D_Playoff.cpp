/*
=========================================================
Date        : 18-07-2026
Problem Name: D. Playoff
Platform    : Codeforces
Difficulty  : 1500
Tags        : Combinatorics, Games, Greedy, Math

Problem Summary:
We have 2^n teams playing an elimination tournament over n phases.
A binary string s of length n dictates each phase: '0' means the team with the 
lower skill level wins, and '1' means the team with the higher skill level wins.
We need to find all winning skill levels x (from 1 to 2^n) that can win the tournament 
under some initial permutation of teams.

Key Observation:
Each '1' in the string forces the champion to beat at least one team in that phase, 
meaning the champion must be strictly greater than a certain number of teams. Conversely, 
each '0' forces the champion to be strictly smaller than a certain number of teams.
=========================================================
*/

#include <iostream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

/*
=========================================================
APPROACH EXPLANATION
=========================================================
1. Optimized (Combinatorics & Bitmasking)
   • Intuition:
     Let the number of '1's in the string be 'ones' and the number of '0's be 'zeros'.
     To win a phase dominated by '1', a team must beat a lower-skilled team. To survive all 
     '1' phases, the champion must be superior to at least 2^(ones) - 1 other teams.
     Similarly, to survive all '0' phases, there must be at least 2^(zeros) - 1 teams with 
     higher skill levels than the champion.
   • Approach:
     Count the total number of '1's and '0's in the string s.
     The minimum possible skill level that can win is 1 + (2^(ones) - 1) = 2^(ones).
     The maximum possible skill level that can win is 2^n - (2^(zeros) - 1).
     Every skill level between this minimum and maximum bound can be constructed to win.
   • Why it Works:
     A team needs to dominate a minimum structural subtree of elements smaller than itself 
     for the '1's, and be dominated by a structural subtree of elements larger than itself 
     for the '0's. The bounds are tight, and any element within the range can satisfy the tournament tree.
   • Time Complexity (TC): O(N) to count characters in the string.
   • Space Complexity (SC): O(1) auxiliary space.
=========================================================
*/

/*
=========================================================
FINAL APPROACH CHOICE
=========================================================
• The dynamic range/combinatorial bound approach is chosen because it directly 
  computes the mathematical limits of the winning teams in O(N) time.
• It avoids simulating tournament permutations, which would be completely 
  infeasible due to the O((2^N)!) factorial complexity.
=========================================================
*/

void solve() {
    int n;
    if (!(cin >> n)) return;
    string s;
    cin >> s;

    int ones = 0;
    int zeros = 0;
    for (char c : s) {
        if (c == '1') {
            ones++;
        } else {
            zeros++;
        }
    }

    // Smallest winning team index (1-based)
    int min_winning = (1 << ones);
    // Largest winning team index (1-based)
    int max_winning = (1 << n) - (1 << zeros) + 1;

    // Output all winning integers in ascending order
    for (int i = min_winning; i <= max_winning; ++i) {
        cout << i << (i == max_winning ? "" : " ");
    }
    cout << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Codeforces problem D usually has a single testcase unless specified, 
    // but the structure supports standard execution.
    solve();

    return 0;
}
