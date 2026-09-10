/*
=========================================================
Date        : 10-09-2026
Problem Name: Huge Boxes of Animal Toys (1425H)
Platform    : Codeforces
Difficulty  : 1300
Tags        : math, constructive algorithms

Problem Summary:
Chaneka has animal toys stored in four boxes based on their fun value:
- Box 1: (-inf, -1]
- Box 2: (-1, 0)
- Box 3: (0, 1)
- Box 4: [1, inf)
She pairs toys up and multiplies their values until only one toy remains.
Determine which boxes could possibly store the final super toy.

Key Observation:
- The total sign of the product is uniquely determined by whether (A + B) is odd (negative) or even (positive).
- A toy with absolute value >= 1 can be obtained if and only if (A + D) > 0, and < 1 if and only if (B + C) > 0.
=========================================================
*/

/*
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
APPROACH EXPLANATION
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

Approach: Parity & Absolute Value Reachability Analysis
• Intuition:
  - Multiplication preserves the sign rules: negative numbers count controls the final sign.
  - The final toy's value is the product of all original numbers, so its sign is negative if (A + B) is odd, and positive if (A + B) is even.
  - Furthermore, multiplying numbers with magnitude > 1 can yield magnitude > 1 (Box 1 or 4), while multiplying numbers with magnitude < 1 can yield magnitude < 1 (Box 2 or 3).
  - Box 1/4 requires at least one toy with absolute value > 1 (i.e., A + D > 0).
  - Box 2/3 requires at least one toy with absolute value < 1 (i.e., B + C > 0).

• Approach:
  - If (A + B) % 2 == 1, the final product must be negative, so only Box 1 and/or Box 2 are possible.
    - Box 1 is possible if A + D > 0.
    - Box 2 is possible if B + C > 0.
  - If (A + B) % 2 == 0, the final product must be positive, so only Box 3 and/or Box 4 are possible.
    - Box 3 is possible if B + C > 0.
    - Box 4 is possible if A + D > 0.

• Why it Works:
  - We can freely choose the values in each open interval to make magnitudes arbitrarily large or small, provided at least one element with |x| > 1 or |x| < 1 is available to pull the overall product into that range.

• Time Complexity (TC):
  - O(1) per testcase.
  - Total Time: O(T), which easily runs within 2.0s for T = 50,000.

• Space Complexity (SC):
  - O(1) auxiliary memory.

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
FINAL APPROACH
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
Chosen Approach: Parity & Absolute Value Reachability Analysis
- It directly evaluates the mathematical invariants (sign and magnitude limits) in O(1) time.
- It is optimal in both runtime and memory, requiring zero simulation.
*/

#include <iostream>

using namespace std;

void solve() {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;

    bool has_large = (a + d > 0);
    bool has_small = (b + c > 0);

    bool ans[4] = {false, false, false, false};

    if ((a + b) % 2 == 1) {
        // Final value must be negative -> Box 1 or Box 2
        if (has_large) ans[0] = true;
        if (has_small) ans[1] = true;
    } else {
        // Final value must be positive -> Box 3 or Box 4
        if (has_small) ans[2] = true;
        if (has_large) ans[3] = true;
    }

    for (int i = 0; i < 4; ++i) {
        cout << (ans[i] ? "Ya" : "Tidak") << (i == 3 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }

    return 0;
}
