/*
=========================================================
Date        : 22-08-2026
Problem Name: World Cup (996B)
Platform    : Codeforces
Difficulty  : 1300 (Div. 2 B)
Tags        : math, implementation, binary search

Problem Summary:
Allen cycles through n entrances starting from entrance 1 at minute 0.
Each minute, all queues decrease by 1 person, and Allen advances to the next entrance.
Determine which entrance Allen will first enter through when its queue reaches 0 upon arrival.

Key Observation:
Allen visits entrance i (0-indexed) at minutes t = i, i + n, i + 2n, ...
The earliest time he can enter gate i is the smallest t = i + k*n such that t >= a[i].
=========================================================
*/

/*
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
APPROACHES:
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

1. Simulation (Brute Force)
• Intuition:
  - Simulate each minute step-by-step, decrementing queues and moving Allen to the next entrance until he finds an empty queue.
• Approach:
  - Keep a global timer and an entrance pointer.
  - Check if a[curr] - timer <= 0; if yes, return curr + 1, else advance timer and curr = (curr + 1) % n.
• Why it Works:
  - Directly models the physical process described in the problem statement.
• Time Complexity (TC): O(max(a_i)) — Time Limit Exceeded for a_i up to 10^9.
• Space Complexity (SC): O(n) to store the initial queue sizes.

2. Mathematical Calculation (Most Optimal)
• Intuition:
  - Allen only visits entrance i at time instants t ≡ i (mod n).
  - Instead of simulating round by round, directly calculate the first valid round k where Allen's arrival time exceeds or equals the queue size.
• Approach:
  - For each entrance i (0-indexed):
    - If a[i] <= i, Allen enters on round 0 at time t_i = i.
    - If a[i] > i, the number of full cycles needed is k = ceil((a[i] - i) / n), and entrance time is t_i = i + k * n.
  - Find the entrance i that yields the minimum t_i.
• Why it Works:
  - Each entrance provides a unique arrival timestamp. The entrance with the smallest entry timestamp is guaranteed to be visited first.
• Time Complexity (TC): O(n) to iterate through all n entrances once.
• Space Complexity (SC): O(1) auxiliary space beyond the input array.

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
FINAL APPROACH:
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
• Approach 2 (Mathematical Calculation) is chosen because it avoids simulation loops entirely.
• It computes the answer in a single linear pass of O(n) time, running well within the 1.0-second limit.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Optimize standard I/O operations for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    int bestEntrance = 1;
    long long minTime = -1;

    for (int i = 0; i < n; ++i) {
        long long a;
        cin >> a;

        long long entryTime;
        if (a <= i) {
            entryTime = i;
        } else {
            long long fullCycles = (a - i + n - 1) / n;
            entryTime = i + fullCycles * n;
        }

        if (minTime == -1 || entryTime < minTime) {
            minTime = entryTime;
            bestEntrance = i + 1;
        }
    }

    cout << bestEntrance << "\n";

    return 0;
}
