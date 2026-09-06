/*
=========================================================
Date        : 06-09-2026
Problem Name: Walking Robot (1154D)
Platform    : Codeforces
Difficulty  : 1500
Tags        : greedy

Problem Summary:
A robot travels along a linear path of n segments with a battery (capacity b) and an accumulator (capacity a).
Passing a segment costs 1 charge from either the accumulator or the battery.
Passing an exposed segment (s[i] = 1) using the battery recharges the accumulator by 1 (up to max capacity a).
Find the maximum number of segments the robot can traverse before exhausting both power sources.

Key Observation:
Accumulator charge is easily restored whenever sunlight is available, but battery charge can never be restored.
Therefore, prioritizing battery usage when it can recharge the accumulator maximizes total travel distance.
=========================================================
*/

/*
---------------------------------------------------------
APPROACH 1: Greedy Simulation (Optimal)
---------------------------------------------------------
• Intuition:
  - Battery charge cannot be replenished, but accumulator charge can be recharged using battery on sunny segments.
  - To gain free segments, we should spend battery on sunny segments whenever accumulator charge is not already full.

• Approach:
  - Maintain current charges cur_b = b and cur_a = a.
  - For each segment:
    1. If cur_a == 0 and cur_b == 0: terminate and return segments passed.
    2. If sunny (s[i] == 1): use battery if cur_b > 0 and cur_a < a (recharging accumulator by 1); otherwise use accumulator if cur_a > 0; else use battery.
    3. If not sunny (s[i] == 0): use accumulator first if cur_a > 0 to preserve irreplaceable battery power; otherwise use battery.
  - Count segments passed until out of moves or reaching n.

• Why it Works:
  - Using accumulator when it is already full on a sunny segment prevents wasting recharge potential.
  - Saving battery for segments where it actually recharges the accumulator strictly dominates using it on dark segments.

• Time Complexity (TC): O(n) - Single pass over the segments.
• Space Complexity (SC): O(1) - Only a few state variables beyond the input array.
---------------------------------------------------------
*/

/*
=========================================================
FINAL APPROACH:
Greedy Simulation is chosen because every segment decision depends solely on current capacities and local sunlight status. 
No backtracking or dynamic programming is necessary as the local greedy choice provably maximizes cumulative remaining energy.
=========================================================
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Optimize standard I/O operations for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, b, a;
    if (!(cin >> n >> b >> a)) return 0;

    vector<int> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }

    int cur_b = b;
    int cur_a = a;
    int ans = 0;

    for (int i = 0; i < n; ++i) {
        // If both energy sources are depleted, the robot cannot proceed
        if (cur_b == 0 && cur_a == 0) {
            break;
        }

        if (s[i] == 1) {
            // Segment is exposed to sunlight
            if (cur_b > 0 && cur_a < a) {
                // Use battery to recharge accumulator
                cur_b--;
                cur_a = min(a, cur_a + 1);
            } else if (cur_a > 0) {
                // Accumulator is full or battery is empty, use accumulator
                cur_a--;
            } else {
                // Only battery is available
                cur_b--;
            }
        } else {
            // Segment is not exposed to sunlight
            if (cur_a > 0) {
                // Prioritize accumulator to preserve battery
                cur_a--;
            } else {
                // Fall back to battery
                cur_b--;
            }
        }

        ans++;
    }

    cout << ans << "\n";

    return 0;
}
