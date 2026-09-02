/*
=========================================================
Date        : 02-09-2026
Problem Name: Three Sevens (1798B)
Platform    : Codeforces
Difficulty  : 1000
Tags        : greedy, implementation, data structures

Problem Summary:
A lottery is held for m days with a list of participants each day.
Each day exactly one winner is chosen who cannot participate on any subsequent day.
Find a valid sequence of winners for all m days, or determine if it is impossible (-1).

Key Observation:
A participant can be declared the winner on day i if and only if day i is the LAST day they participate.
Iterating backwards from day m to day 1 allows deterministic selection of winners.
=========================================================
*/

/*
---------------------------------------------------------
APPROACH 1: Brute Force Simulation
---------------------------------------------------------
• Intuition:
  - Try choosing every possible participant on day i and verify whether they appear in any future day > i.
• Approach:
  - For each day i from 1 to m, pick an available participant not yet used and check days i+1 to m.
• Why it Works:
  - Directly tests the non-reappearance constraint for every picked winner.
• Time Complexity (TC): O(m * sum(n_i)) in the worst case without hash tracking, potentially TLE.
• Space Complexity (SC): O(sum(n_i)) to store participants.

---------------------------------------------------------
APPROACH 2: Backward Traversal with Set / Visited Array (Most Optimal)
---------------------------------------------------------
• Intuition:
  - Process days in reverse order from day m down to 1.
  - A person who won on day i cannot appear on any day j > i; thus, any participant already seen on days > i cannot win on day i.
• Approach:
  - Iterate days from m down to 1.
  - Find the first participant on day i who has not appeared in days > i.
  - If found, designate them as day i's winner. If no such participant exists, output -1.
  - Add all participants of day i to a "seen" set/array.
• Why it Works:
  - Working backwards naturally satisfies the future-appearance constraint in a single pass.
• Time Complexity (TC): O(sum(n_i)) per testcase using a boolean visited array or hash set.
• Space Complexity (SC): O(max(a_i,j)) or O(sum(n_i)) for tracking seen elements.
*/

/*
---------------------------------------------------------
FINAL APPROACH:
---------------------------------------------------------
• Chosen Approach: Backward Traversal with Visited Array / Set.
• Why Chosen: It runs in strictly linear time proportional to the sum of elements, avoiding quadratic scans.
• Optimality: Guarantees an O(sum(n_i)) time complexity well within the 2.0-second limit.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int m;
    cin >> m;

    vector<vector<int>> days(m);
    int max_val = 50000;

    for (int i = 0; i < m; ++i) {
        int n;
        cin >> n;
        days[i].resize(n);
        for (int j = 0; j < n; ++j) {
            cin >> days[i][j];
            if (days[i][j] > max_val) {
                max_val = days[i][j];
            }
        }
    }

    vector<int> winners(m);
    vector<bool> seen(max_val + 1, false);
    bool possible = true;

    for (int i = m - 1; i >= 0; --i) {
        int winner = -1;
        for (int participant : days[i]) {
            if (!seen[participant] && winner == -1) {
                winner = participant;
            }
            seen[participant] = true;
        }

        if (winner == -1) {
            possible = false;
            break;
        }
        winners[i] = winner;
    }

    if (!possible) {
        cout << -1 << "\n";
    } else {
        for (int i = 0; i < m; ++i) {
            cout << winners[i] << (i == m - 1 ? "" : " ");
        }
        cout << "\n";
    }
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
