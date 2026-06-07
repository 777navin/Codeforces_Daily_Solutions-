/*
Date: 07-06-2026
Problem Name: Card Game
Platform: Codeforces
Difficulty: 800
Tags: implementation, games, greedy

Problem Summary:
Two players have a set of cards with distinct values from 1 to n. 
In each turn, both players pick one card blindly. The player with the 
higher card value takes both cards. The game continues until one player 
has no cards left. Given the initial distribution of cards, determine 
if the first player wins assuming optimal play.

Methods to Solve:
1. Optimal Greedy Approach

For the Optimal Greedy Approach:
- Intuition: Since both players want to win and all card values are distinct, 
  the player who holds the card with the maximum value (n) can always win 
  the round whenever they play that card. Because they can choose to play 
  this card at any time, they can secure a win in any round against any 
  other card. By playing the maximum card, they effectively control the game.
- Approach: Check if the first player possesses the maximum value card (n). 
  If they do, they win. Otherwise, the second player wins.
- Time Complexity: O(k1 + k2) per test case, where k1, k2 are the number of cards.
- Space Complexity: O(1) (excluding input storage).
- When to use: When the game state depends entirely on the possession of the 
  highest value element in a set.

Comparison Table:
Method | TC | SC | Best Use Case
-------|----|----|--------------
Greedy | O(N) | O(1) | Optimal Strategy

Final Recommended Solution: Check if max(cards_player1) == n.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Fast I/O setup
 */
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve() {
    int n, k1, k2;
    cin >> n >> k1 >> k2;

    int max_p1 = 0;
    for (int i = 0; i < k1; ++i) {
        int card;
        cin >> card;
        max_p1 = max(max_p1, card);
    }

    // We still need to consume the input for the second player
    for (int i = 0; i < k2; ++i) {
        int card;
        cin >> card;
    }

    // Logic: If Player 1 holds the highest card (n), they can always win.
    if (max_p1 == n) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    fast_io();

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
