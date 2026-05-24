// 24-05-2026_Codeforces_1681A_Game_with_Cards.cpp

/*
Date: 24-05-2026
Problem Name: 1681A - Game with Cards
Platform: Codeforces
Difficulty: 800
Tags: Games, Greedy, Math

Problem Summary:
Alice and Bob play a turn-based game using cards with integer values. A player must always play a card that is strictly greater than the card played by their opponent on the previous turn. If a player cannot make a valid move, they lose. Given both players' decks and assuming optimal play, we need to determine the winner if Alice plays first, and the winner if Bob plays first.

Methods to Solve:
1. Optimal Approach (Max Element Comparison)

For EACH method include:

- Intuition: 
  Since both players play optimally, they will try to use their highest-value card to force the other player into a state where they have no valid moves left. The outcome of the game strictly depends on who possesses the absolute highest card. 

- Approach:
  1. Find the maximum card value in Alice's deck (`maxA`).
  2. Find the maximum card value in Bob's deck (`maxB`).
  3. If Alice goes first: She will optimally play her highest card `maxA`. 
     - If `maxA >= maxB`, Bob has no card strictly greater than `maxA` to beat it, so Alice wins.
     - If `maxA < maxB`, Bob will eventually play `maxB`, and Alice will have nothing to beat it, so Bob wins.
  4. If Bob goes first: He will optimally play his highest card `maxB`.
     - If `maxB >= maxA`, Alice has no card strictly greater than `maxB`, so Bob wins.
     - If `maxB < maxA`, Alice will play `maxA`, and Bob will have nothing to beat it, so Alice wins.
     
- Dry Run: 
  Alice's cards = [6, 8] -> maxA = 8
  Bob's cards = [6, 11, 6] -> maxB = 11
  - Alice goes first: Plays 8. Bob plays 11. Alice cannot beat 11. Bob wins.
  - Bob goes first: Plays 11. Alice cannot beat 11. Bob wins.
  Result: Bob, Bob.

- Time Complexity: 
  O(N + M) per test case, where N is the number of Alice's cards and M is the number of Bob's cards. We only need to iterate through the arrays once to find the maximum values.

- Space Complexity: 
  O(1) auxiliary space. We compute the maximums on the fly as we read the inputs, eliminating the need to store the arrays entirely.

- Why better than previous method: 
  N/A (This is the most optimal and straightforward approach without requiring sorting or simulations).

- When to use: 
  In game theory problems where a single, un-beatable dominant resource (the maximum element) dictates the state of the game.

Comparison Table:
Method             | TC       | SC   | Best Use Case
Optimal Approach   | O(N + M) | O(1) | Standard CP approach for greedy/game-theory array problems.

Final Recommended Solution: Optimal Approach (Max Element Comparison)
*/

#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int maxA = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        maxA = max(maxA, a);
    }

    int m;
    cin >> m;
    int maxB = 0;
    for (int i = 0; i < m; ++i) {
        int b;
        cin >> b;
        maxB = max(maxB, b);
    }

    // Determine winner if Alice plays first
    if (maxA >= maxB) {
        cout << "Alice\n";
    } else {
        cout << "Bob\n";
    }

    // Determine winner if Bob plays first
    if (maxB >= maxA) {
        cout << "Bob\n";
    } else {
        cout << "Alice\n";
    }
}

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    
    // Handle multiple test cases
    while (t--) {
        solve();
    }

    return 0;
}
