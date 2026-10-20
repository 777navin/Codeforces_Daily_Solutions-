/*
=========================================================
Date        : 20-10-2026
Problem Name: Train
Platform: Codeforces
Difficulty: 1500
Tags: implementation, graphs, games

Problem Summary:
- A stowaway and a controller move through an n-wagon train over several minutes.
- The controller moves deterministically back and forth from head to tail.
- When the train moves, the stowaway can stay or move to an adjacent wagon. When idle at a station, the stowaway leaves and re-enters any wagon.
- Determine if the controller catches the stowaway or if the stowaway successfully reaches the terminal station.

Key Observation:
- Since n is small (up to 50) and the number of minutes is at most 200, we can simulate minute by minute while maintaining all possible valid positions of the stowaway.
=========================================================
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    if (!(cin >> n >> m >> k)) return 0;

    string direction;
    cin >> direction;

    string s;
    cin >> s;

    // Controller direction: 1 for moving towards tail (n), -1 for moving towards head (1)
    int c_dir = (direction == "to tail") ? 1 : -1;
    int c_pos = k;
    
    // Set of possible positions where the stowaway could be. Initially just {m}.
    set<int> stowaway_pos = {m};

    int time_len = s.length();
    for (int t = 0; t < time_len; ++t) {
        // Check if controller is currently in the same wagon as any possible stowaway position
        for (int pos : stowaway_pos) {
            if (pos == c_pos) {
                cout << "Controller " << (t + 1) << "\n";
                return 0;
            }
        }

        // If it's the last minute and the train is idle, stowaway wins
        if (t == time_len - 1) {
            cout << "Stowaway\n";
            return 0;
        }

        char train_state = s[t]; // '0' for moving, '1' for idle

        if (train_state == '0') {
            // Train is moving: stowaway can stay or move to adjacent wagons
            set<int> next_pos;
            for (int pos : stowaway_pos) {
                next_pos.insert(pos);
                if (pos > 1) next_pos.insert(pos - 1);
                if (pos < n) next_pos.insert(pos + 1);
            }
            stowaway_pos = next_pos;
        } else {
            // Train is idle: stowaway leaves and can re-enter any wagon (1 to n)
            stowaway_pos.clear();
            for (int i = 1; i <= n; ++i) {
                stowaway_pos.insert(i);
            }
        }

        // Check again after stowaway movement
        for (int pos : stowaway_pos) {
            if (pos == c_pos) {
                cout << "Controller " << (t + 1) << "\n";
                return 0;
            }
        }

        // Controller moves
        c_pos += c_dir;
        if (c_pos == 1 || c_pos == n) {
            c_dir = -c_dir; // Reverse direction at endpoints
        }
    }

    cout << "Stowaway\n";
    return 0;
}

/*
=========================================================
FINAL APPROACH EXPLANATION
=========================================================

• Why this approach is chosen:
  - The problem constraints are very small ($n \le 50$, time string length $\le 200$), making a direct simulation of all reachable states extremely efficient.
  - Using a `std::set` to track all possible valid wagon positions of the stowaway at any given minute accurately handles the branching choices.

• Why it is better than the previous ones:
  - It avoids complex backtracking or global search by directly tracking state sets level-by-level, ensuring correctness and optimal $O(T \cdot N)$ complexity.

• Time Complexity (TC):
  - $O(T \cdot N)$ where $T$ is the length of the string ($\le 200$) and $N$ is the number of wagons ($\le 50$). This runs well within the 2.0-second limit.

• Space Complexity (SC):
  - $O(N)$ to store the set of possible wagon positions for the stowaway.
=========================================================
*/
