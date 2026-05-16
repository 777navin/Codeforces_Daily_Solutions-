/*
Date: 16-05-2026
Problem Name: Launch of Collider
Platform: Codeforces (699A)
Difficulty: Easy / 1000
Tags: Implementation, Two Pointers, Greedy

Problem Summary:
n particles are placed on a 1D line at even integer coordinates. Each particle 
moves either Left (L) or Right (R) at a constant speed of 1 m/µs. We need to 
find the earliest time any two particles collide. If no collision occurs, return -1.
A collision only happens if a particle moving Right ('R') is to the left of a 
particle moving Left ('L').

Methods to Solve:
1. Optimal Approach (Single Pass)

- Intuition:
  Since all particles move at the same speed, a collision can only happen 
  between two adjacent particles if the left one moves Right ('R') and the 
  right one moves Left ('L'). The distance between them decreases at a 
  relative speed of 2 m/µs (1m/µs + 1m/µs). 

- Approach:
  1. Traverse the direction string from left to right.
  2. Look for the pattern "RL" in adjacent particles.
  3. If found, calculate the time to collide: (coordinate[i+1] - coordinate[i]) / 2.
  4. Track the minimum time among all such "RL" pairs.
  5. If no "RL" pair exists, output -1.

- Dry Run:
  Input: 4, RLRL, [2, 4, 6, 10]
  - Pair (0,1): 'R' and 'L'. Distance = 4 - 2 = 2. Time = 2/2 = 1. MinTime = 1.
  - Pair (1,2): 'L' and 'R'. No collision.
  - Pair (2,3): 'R' and 'L'. Distance = 10 - 6 = 4. Time = 4/2 = 2. MinTime = min(1, 2) = 1.
  Result: 1.

- Time Complexity: O(n), where n is the number of particles.
- Space Complexity: O(n) to store the coordinates.
- Why better than previous method: This is the most efficient linear scan.
- When to use: Always, as the input is already sorted by coordinates.

Comparison Table:
Method           | TC   | SC   | Best Use Case
Optimal Scan     | O(n) | O(n) | Standard competitive programming constraints.

Final Recommended Solution:
The Optimal Scan is the most efficient way to solve this in a single pass.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

/**
 * Problem: Launch of Collider (Codeforces 699A)
 * Solution by: Gemini
 */

void solve() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return;

    string directions;
    cin >> directions;

    vector<long long> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }

    long long min_time = LLONG_MAX;
    bool found = false;

    // Check adjacent particles for "RL" pattern
    for (int i = 0; i < n - 1; ++i) {
        if (directions[i] == 'R' && directions[i + 1] == 'L') {
            long long collision_time = (x[i + 1] - x[i]) / 2;
            if (collision_time < min_time) {
                min_time = collision_time;
            }
            found = true;
        }
    }

    if (found) {
        cout << min_time << endl;
    } else {
        cout << -1 << endl;
    }
}

int main() {
    // Single test case as per Codeforces problem type
    solve();
    return 0;
}
