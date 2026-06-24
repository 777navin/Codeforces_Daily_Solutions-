/*
Date: 24-06-2026
Problem Name: George and Accommodation (467A)
Platform: Codeforces
Difficulty: 800
Tags: Implementation, Math

Problem Summary:
George and Alex want to live in the same dormitory room. Given 'n' rooms, 
along with the current number of people living in each room (p_i) and the 
maximum capacity of each room (q_i), find how many rooms have enough 
available space to accommodate both of them (at least 2 free spots).

Methods to Solve:
1. Optimal Approach (Single Pass Simulation)

---------------------------------------------------------------------------
Method 1: Optimal Approach
---------------------------------------------------------------------------
- Intuition: 
    Both George and Alex need to fit in the same room. Therefore, a room is 
    only valid if its total capacity minus its current occupancy is strictly 
    greater than or equal to 2.

- Approach: 
    1. Initialize a counter `available_rooms` to 0.
    2. Read the total number of rooms `n`.
    3. Loop `n` times. In each iteration, read `p` (current occupants) and 
       `q` (capacity).
    4. If `q - p >= 2`, increment the `available_rooms` counter.
    5. Print the final counter.

- Dry Run (small example):
    Input:
    3
    1 1
    2 2
    3 3

    Execution:
    Room 1: p=1, q=1 -> Capacity left = 0 < 2  -> Valid? No
    Room 2: p=2, q=2 -> Capacity left = 0 < 2  -> Valid? No
    Room 3: p=3, q=3 -> Capacity left = 0 < 2  -> Valid? No
    Output: 0

- Time Complexity: $O(N)$
  We iterate through the 'n' rooms exactly once.
- Space Complexity: $O(1)$
  We only use a few integer variables to keep track of the count and inputs.

- Why better than previous method: 
  This is the most straightforward and optimal way to solve the problem.
- When to use: 
  Standard $O(N)$ simulation and counting problems.

Comparison Table:
Method             | TC      | SC      | Best Use Case
-------------------|---------|---------|---------------------------------
Optimal Approach   | $O(N)$  | $O(1)$  | Best and only necessary approach

Final Recommended Solution: Optimal Approach
*/

#include <iostream>

using namespace std;

// Fast I/O for competitive programming
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int main() {
    // Optimize standard I/O operations for performance
    fast_io();

    int n;
    if (!(cin >> n)) return 0; // Read number of rooms

    int available_rooms = 0;

    // Iterate through each room's data
    while (n--) {
        int p, q;
        cin >> p >> q;

        // Check if the room has space for both George and Alex (at least 2 free spots)
        if (q - p >= 2) {
            available_rooms++;
        }
    }

    // Output the total number of valid rooms
    cout << available_rooms << "\n";

    return 0;
}
