/*
Date: 30-04-2026
Problem Name: A. Koshary
Platform: Codeforces (Round 1096 Div. 3)
Difficulty: Easy / 800
Tags: Math, Greedy, Implementation

Problem Summary:
Yousef starts at (0, 0) and needs to reach (x, y). 
- Long steps: (a+2, b) or (a, b+2)
- Short step: (a+1, b) or (a, b+1) [Allowed AT MOST once during the journey]
Determine if (x, y) is reachable exactly.

Methods to Solve:

1. Parity & Remainder Analysis (Optimal)
- Intuition: Long steps always change a coordinate by 2, meaning they preserve the parity (even/odd status) of the coordinates. A single short step changes the parity of exactly one coordinate once.
- Approach: 
    - If no short step is used, both x and y must be even (x%2 == 0 and y%2 == 0).
    - If one short step is used, it can either make an odd x even or an odd y even. Thus, either (x%2 == 1 and y%2 == 0) OR (x%2 == 0 and y%2 == 1).
    - Combined: It is impossible to reach (x, y) if both x and y are odd (x%2 == 1 and y%2 == 1) because one short step can only flip the parity of one coordinate.
- Dry Run (x=1, y=1): 1%2=1, 1%2=1. Both odd. Output: NO.
- Dry Run (x=1, y=2): 1%2=1, 2%2=0. One odd. Output: YES (One short step on x, long steps on y).
- Time Complexity: O(1) per test case.
- Space Complexity: O(1).
- Why better: This is the most direct mathematical observation.
- When to use: Always, as it covers all constraints efficiently.

Comparison Table:
Method             | TC   | SC   | Best Use Case
-----------------------------------------------------
Parity Analysis    | O(1) | O(1) | Competitive Programming

Final Recommended Solution:
The Parity Analysis approach is optimal due to O(1) time complexity and simple implementation.
*/

#include <iostream>

using namespace std;

/**
 * Problem Logic:
 * Long steps (increment by 2) maintain parity.
 * Short step (increment by 1) flips parity.
 * Since only one short step is allowed, we can have at most one odd coordinate.
 * If both x and y are odd, it is impossible to reach the target.
 */
void solve() {
    int x, y;
    if (!(cin >> x >> y)) return;

    // If both x and y are odd, we would need two short steps (one for each).
    // But we are only allowed at most one short step.
    if ((x % 2 != 0) && (y % 2 != 0)) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
}

int main() {
    // Fast I/O for Competitive Programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}
