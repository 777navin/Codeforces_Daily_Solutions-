/*
=========================================================
Date        : 16-11-2026
Problem Name: B. Counting-out Rhyme
Platform    : Codeforces
Difficulty  : 1300
Tags        : Implementation, Simulation, Math

Problem Summary:
There are n children standing in a circle numbered 1 to n, with child 1 initially as the leader.
In each of k steps, the current leader counts a_i steps clockwise and eliminates the child landed on.
The child immediately clockwise to the eliminated one becomes the new leader; print each eliminated child.

Key Observation:
Because the children form a circle, counting a_i steps clockwise among m remaining children
is equivalent to moving (a_i % m) positions forward from the current leader's index.
=========================================================
*/

/*
---------------------------------------------------------
APPROACH 1: Brute Force (Step-by-Step Simulation)
---------------------------------------------------------
• Intuition:
  Simulate the counting process literally one person at a time using a boolean array to mark eliminated children.

• Approach:
  Maintain a visited/eliminated array of size n and a current pointer. For each step, advance the pointer
  one by one, skipping already eliminated children, until a_i valid children are counted.

• Why it Works:
  Directly mirrors the problem rules without modular shortcuts. However, since a_i can be up to 10^9,
  stepping one by one times out (TLE).

• Time Complexity (TC): O(k * max(a_i)) -> TLE since a_i <= 10^9
• Space Complexity (SC): O(n)
*/

/*
---------------------------------------------------------
APPROACH 2: Optimized (Dynamic Array + Modulo Arithmetic)
---------------------------------------------------------
• Intuition:
  Instead of walking around eliminated children or taking full redundant laps around the circle,
  keep only active children in a list and use modulo arithmetic to jump straight to the target.

• Approach:
  Store children 1 to n in a std::vector. Track the current leader's 0-based index `leader_idx`.
  At each step, compute `elim_idx = (leader_idx + a_i) % circle.size()`, print `circle[elim_idx]`,
  erase that element from the vector, and set `leader_idx = elim_idx % circle.size()`.

• Why it Works:
  Removing an element shifts all subsequent elements left by 1, meaning the next clockwise child
  automatically lands at `elim_idx` (wrapping around to 0 if the last element was removed).

• Time Complexity (TC): O(n * k) (or O(n^2) worst case, which is ~10^4 operations for n <= 100)
• Space Complexity (SC): O(n)
*/

/*
---------------------------------------------------------
FINAL APPROACH RATIONALE
---------------------------------------------------------
Approach 2 (Dynamic Array + Modulo Arithmetic) is chosen because a_i can reach 10^9,
making step-by-step simulation impossible within the 1-second time limit. Using modulo
reduces each step to O(1) index calculation and O(n) vector deletion, running well under 1 ms for n <= 100.
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Optimize standard I/O operations for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    if (!(cin >> n >> k)) return 0;

    // Initialize the circle with children numbered 1 to n
    vector<int> circle(n);
    for (int i = 0; i < n; ++i) {
        circle[i] = i + 1;
    }

    // Child 1 (at index 0) starts as the leader
    int leader_idx = 0;

    for (int step = 0; step < k; ++step) {
        long long a_i;
        cin >> a_i;

        // Calculate the index of the child to be eliminated using modulo
        int current_size = static_cast<int>(circle.size());
        int elim_idx = (leader_idx + a_i) % current_size;

        // Output the eliminated child's number
        cout << circle[elim_idx] << (step == k - 1 ? "" : " ");

        // Remove the eliminated child from the circle
        circle.erase(circle.begin() + elim_idx);

        // After erasure, the next clockwise person shifts into elim_idx.
        // Taking modulo handles the wrap-around case if the last element was removed.
        leader_idx = elim_idx % static_cast<int>(circle.size());
    }

    cout << "\n";
    return 0;
}
