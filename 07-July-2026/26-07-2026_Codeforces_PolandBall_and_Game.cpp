/*
=========================================================
Date        : 26-07-2026
Problem Name: 755B - PolandBall and Game
Platform    : Codeforces
Difficulty  : 1100
Tags        : games, strings, data structures, greedy

Problem Summary:
Two players take turns saying words they know without repeating. 
They might know some common words. The first player who cannot 
say a new word loses. Determine the winner given optimal play.

Key Observation:
Players will always prioritize saying shared words first to 
deplete the opponent's options. The parity of the count of 
shared words determines who gains the advantage from them.
=========================================================

1. Optimal Strategy using Hash Set
   - Intuition: A shared word helps the current player and removes an option for the opponent. Both players greedily pick shared words first.
   - Approach: Insert all of PolandBall's words into a hash set. Then count how many of EnemyBall's words exist in this set (shared words).
   - Why it Works: If the number of shared words is odd, PolandBall says the last shared word, giving him an effective +1 advantage. We can check if `n > m - (shared % 2)`.
   - Time Complexity (TC): O((N + M) * L), where N, M are word counts and L is max word length, for hashing and lookups.
   - Space Complexity (SC): O(N * L) to store PolandBall's words in the unordered_set.

=========================================================
Final Approach Justification:
We choose the Hash Set approach because it perfectly models 
the optimal game theory strategy in linear time with respect 
to input size. It efficiently handles the string lookups and 
provides the result mathematically without a slow simulation.
=========================================================
*/

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;

    unordered_set<string> polandWords;
    string word;

    for (int i = 0; i < n; ++i) {
        cin >> word;
        polandWords.insert(word);
    }

    int shared = 0;
    for (int i = 0; i < m; ++i) {
        cin >> word;
        if (polandWords.count(word)) {
            shared++;
        }
    }

    // If shared words are odd, PolandBall gets the advantage of the last shared word.
    // This effectively reduces EnemyBall's winning threshold by 1.
    if (n > m - (shared % 2)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // The problem doesn't specify multiple test cases per file, 
    // just a single run per execution.
    solve();
    
    return 0;
}
