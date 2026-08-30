/*
=========================================================
Date        : 30-08-2026
Problem Name: Hotelier (1200A)
Platform    : Codeforces
Difficulty  : 800
Tags        : implementation, brute force, strings

Problem Summary:
A hotel has 10 rooms (numbered 0 to 9) initially empty.
Customers enter from the left ('L') taking the leftmost available room,
or from the right ('R') taking the rightmost available room.
When a digit '0'-'9' appears, the customer in that specific room leaves.
Output the final state of all 10 rooms.

Key Observation:
Since there are only 10 rooms, we can directly simulate every event using a 
boolean array or string of size 10 in O(1) time per event.
=========================================================
*/

/*
---------------------------------------------------------
APPROACH 1: Direct Simulation (Optimal)
---------------------------------------------------------
• Intuition:
  The number of rooms is fixed at 10, so a linear scan across 10 elements per event is extremely fast and straightforward.

• Approach:
  - Maintain a boolean array `rooms` of size 10 initialized to 0 (all empty).
  - For 'L', find the first index from 0 to 9 with `rooms[i] == 0` and set it to 1.
  - For 'R', find the first index from 9 down to 0 with `rooms[i] == 0` and set it to 1.
  - For a digit `d` ('0'-'9'), set `rooms[d - '0'] = 0`.
  - Finally, print all 10 room statuses sequentially.

• Why it Works:
  The constraints guarantee valid operations (empty room available for 'L'/'R', and occupied room for departures), so standard greedy placement directly reflects the hotel state.

• Time Complexity (TC) : O(n * 10) = O(n), where n is the number of events.
• Space Complexity (SC): O(1) auxiliary space (fixed array of size 10).
---------------------------------------------------------
*/

/*
=========================================================
FINAL APPROACH SELECTION:
- Direct simulation with a fixed 10-element array is optimal.
- It requires minimal memory, runs in linear time with respect to the input length, and eliminates unnecessary complexity.
=========================================================
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    
    string s;
    cin >> s;
    
    vector<int> rooms(10, 0);
    
    for (char c : s) {
        if (c == 'L') {
            for (int i = 0; i < 10; ++i) {
                if (rooms[i] == 0) {
                    rooms[i] = 1;
                    break;
                }
            }
        } else if (c == 'R') {
            for (int i = 9; i >= 0; --i) {
                if (rooms[i] == 0) {
                    rooms[i] = 1;
                    break;
                }
            }
        } else {
            int room_idx = c - '0';
            rooms[room_idx] = 0;
        }
    }
    
    for (int i = 0; i < 10; ++i) {
        cout << rooms[i];
    }
    cout << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    
    return 0;
}
