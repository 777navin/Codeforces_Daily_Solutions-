/*
=========================================================
Date        : 07-07-2026
Problem Name: B. Xenia and Spies
Platform    : Codeforces
Difficulty  : 1500
Tags        : Greedy, Simulation, Implementation

Problem Summary:
- A spy has to move from position s to position f.
- In some time steps, Xenia watches a continuous segment.
- A spy inside the watched segment cannot send or receive the note.
- Print the action taken at every step using:
  'L' -> move left
  'R' -> move right
  'X' -> wait

Key Observation:
- The spy always wants to move directly toward the destination.
- Move only if BOTH the current position and the next position are not watched.
=========================================================
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
=========================================================
Approach 1: Brute Force
---------------------------------------------------------
Intuition:
- Try every possible action.

Approach:
- Explore all valid sequences.

Why it Works:
- Checks every possibility.

TC: Exponential
SC: Exponential

(Not feasible.)
=========================================================
*/

/*
=========================================================
Approach 2: Greedy Simulation (Optimal)
---------------------------------------------------------
Intuition:
- The shortest path is always moving directly toward f.
- Wait only when movement is blocked.

Approach:
- Simulate each time step.
- If the current event occurs at this time:
    - If current spy or next spy is watched -> wait ('X').
    - Otherwise move toward destination.
- If there is no event at this time, always move.

Why it Works:
- Waiting is only useful when movement is impossible.
- Any unnecessary wait increases total time.

TC: O(m + |f - s|)
SC: O(m)
=========================================================
*/

/*
=========================================================
Chosen Approach
---------------------------------------------------------
- Simple greedy simulation.
- Processes each event only once.
- Produces the minimum possible number of steps.
=========================================================
*/

struct Event {
    int time, left, right;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, s, f;
    cin >> n >> m >> s >> f;

    vector<Event> events(m);
    for (int i = 0; i < m; i++) {
        cin >> events[i].time >> events[i].left >> events[i].right;
    }

    string answer;

    int currentPos = s;
    int target = f;
    int direction = (target > currentPos) ? 1 : -1;

    int eventIndex = 0;
    int currentTime = 1;

    while (currentPos != target) {

        bool blocked = false;

        if (eventIndex < m && events[eventIndex].time == currentTime) {

            int L = events[eventIndex].left;
            int R = events[eventIndex].right;

            int nextPos = currentPos + direction;

            if ((currentPos >= L && currentPos <= R) ||
                (nextPos >= L && nextPos <= R)) {
                blocked = true;
            }

            eventIndex++;
        }

        if (blocked) {
            answer += 'X';
        } else {
            currentPos += direction;
            answer += (direction == 1 ? 'R' : 'L');
        }

        currentTime++;
    }

    cout << answer << '\n';

    return 0;
}
