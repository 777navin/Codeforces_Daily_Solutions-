/*
Date: 03-05-2026
Problem Name: Yet Another String Game
Platform: Codeforces
Difficulty: Easy (Div. 2 A)
Tags: Strings, Greedy, Game Theory

-------------------------------------------------
Problem Summary:
Alice and Bob alternately change characters of a string.
- Alice moves first, aiming for lexicographically smallest string.
- Bob moves second, aiming for lexicographically largest string.
- Each move: choose an unused index i and change s[i] to any other lowercase letter.

Both play optimally. Find the final string.

-------------------------------------------------
Methods to Solve:

1. Simulation with Optimal Choices
2. Direct Greedy Construction (Optimal)

-------------------------------------------------
Method 1: Simulation
- Intuition: Alternate moves, simulate each character change.
- Approach: For each index:
  - Alice’s turn → change to 'a' (smallest possible) unless already 'a', then 'b'.
  - Bob’s turn → change to 'z' (largest possible) unless already 'z', then 'y'.
- Dry Run: s="az"
  Alice: 'a'→'b' → "bz"
  Bob: 'z'→'y' → "by"
- TC: O(n)
- SC: O(1)
- Why better: Directly models the game.
- When to use: Always.

-------------------------------------------------
Method 2: Direct Greedy Construction
- Intuition: Since every index is chosen exactly once, we can directly construct the final string.
- Approach: Iterate over string:
  - If index is odd (Alice’s turn): make it 'a' if not 'a', else 'b'.
  - If index is even (Bob’s turn): make it 'z' if not 'z', else 'y'.
- Dry Run: s="bbbb"
  Alice: 'b'→'a', Bob: 'b'→'z', Alice: 'b'→'a', Bob: 'b'→'z' → "azaz".
- TC: O(n)
- SC: O(1)
- Why better: Cleaner, no explicit simulation state.
- When to use: Optimal solution.

-------------------------------------------------
Comparison Table:
Method        | TC   | SC   | Best Use Case
-------------------------------------------------
Simulation    | O(n) | O(1) | Step-by-step modeling
Greedy Direct | O(n) | O(1) | Clean optimal solution

-------------------------------------------------
Final Recommended Solution:
Method 2 (Direct Greedy Construction) — concise and optimal.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        for(int i=0; i<(int)s.size(); i++) {
            if(i % 2 == 0) { 
                // Alice's turn
                if(s[i] == 'a') s[i] = 'b';
                else s[i] = 'a';
            } else { 
                // Bob's turn
                if(s[i] == 'z') s[i] = 'y';
                else s[i] = 'z';
            }
        }
        cout << s << "\n";
    }
    return 0;
}
