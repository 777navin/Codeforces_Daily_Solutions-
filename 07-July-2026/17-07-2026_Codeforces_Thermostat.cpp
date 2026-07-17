/*
=========================================================
Date        : 17-07-2026
Problem Name: C. Thermostat
Platform    : Codeforces
Difficulty  : 1100
Tags        : math, greedy, implementation

Problem Summary:
We need to change the temperature of a thermostat from an initial value 'a' to a 
target value 'b'. The temperature must stay within the range [l, r], and each 
individual change must have an absolute difference of at least 'x' (|current - next| >= x).
Find the minimum operations required, or return -1 if it is impossible.

Key Observation:
Since we want the minimum steps, the shortest paths will always involve either 
moving directly to 'b', or bouncing off the extreme boundaries 'l' or 'r' to 
maximize the temperature jump size.
=========================================================
*/

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

/*
---------------------------------------------------------
Approach 1: Direct Boundary Greedy (Most Optimal)
---------------------------------------------------------
• Intuition:
  The shortest path between two values with a minimum jump constraint involves 
  either jumping directly or using the absolute boundaries ('l' or 'r') to maximize 
  the distance of our transitions.

• Approach:
  Check reachable states step-by-step:
  - 0 steps: If a == b, no movement needed.
  - 1 step : If |a - b| >= x, jump directly.
  - 2 steps: Try jumping via boundary 'l' (a -> l -> b) or boundary 'r' (a -> r -> b).
  - 3 steps: Try jumping using both boundaries (a -> r -> l -> b) or (a -> l -> r -> b).
  - Otherwise, it is impossible to reach 'b' under the constraints.

• Why it Works:
  Boundaries 'l' and 'r' offer the maximum possible jump distances from any point. 
  If 'b' cannot be reached within 3 jumps using these extreme structural elements, 
  it cannot be reached at all because any intermediate elements provide smaller jump distances.

• Time Complexity (TC) : O(1) per test case
• Space Complexity (SC): O(1)
*/

// Final Approach Explanation:
// This greedy check exhaustively handles all minimal step configurations (0 to 3 steps) 
// using the boundary extremes. It operates in O(1) time and space, making it perfectly optimal.

void solve() {
    long long l, r, x;
    long long a, b;
    cin >> l >> r >> x;
    cin >> a >> b;

    // Case 0: Already at the target temperature
    if (a == b) {
        cout << 0 << "\n";
        return;
    }

    // Case 1: Direct jump is valid
    if (abs(a - b) >= x) {
        cout << 1 << "\n";
        return;
    }

    // Case 2: Jump via a single boundary (either 'l' or 'r')
    // Option A: a -> l -> b
    if (abs(a - l) >= x && abs(b - l) >= x) {
        cout << 2 << "\n";
        return;
    }
    // Option B: a -> r -> b
    if (abs(r - a) >= x && abs(r - b) >= x) {
        cout << 2 << "\n";
        return;
    }

    // Case 3: Jump via both boundaries
    // Option A: a -> r -> l -> b
    if (abs(r - a) >= x && abs(r - l) >= x && abs(b - l) >= x) {
        cout << 3 << "\n";
        return;
    }
    // Option B: a -> l -> r -> b
    if (abs(a - l) >= x && abs(r - l) >= x && abs(r - b) >= x) {
        cout << 3 << "\n";
        return;
    }

    // Otherwise, reaching b is impossible
    cout << -1 << "\n";
}

int main() {
    // Fast I/O for Competitive Programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
