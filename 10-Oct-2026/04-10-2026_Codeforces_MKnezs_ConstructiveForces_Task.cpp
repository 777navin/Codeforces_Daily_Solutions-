/*
=========================================================
Date        : 04-10-2026
Problem Name: MKnez's ConstructiveForces Task
Platform    : Codeforces
Difficulty  : 900
Tags        : Constructive Algorithms, Math

Problem Summary:
Construct an array 's' of length 'n' consisting of non-zero integers such that for every 
adjacent pair, their sum equals the sum of all elements in the array. If no such array 
exists, output "NO".

Key Observation:
- For even n, alternating sequence [1, -1, 1, -1, ...] gives an array sum of 0, and 
  adjacent pair sums equal 0.
- For odd n = 3, no non-zero solution exists.
- For odd n > 3, we can set values k = n/2 to construct alternating values:
  [k - 1, -k, k - 1, -k, ..., k - 1]. Adjacent sums will be -1, matching the total array sum.
=========================================================
*/

#include <iostream>
#include <vector>

using namespace std;

/*
=========================================================
APPROACH EXPLANATION
=========================================================

1. Constructive Parity Approach

• Intuition:
  Adjacent pair sum must equal total array sum.
  - If n is even, pairs of (1, -1) cancel out, making total sum = 0 and adjacent sum = 0.
  - If n is odd, let n = 2k + 1. Total elements with value A is (k + 1), and value B is k.
    Total sum = (k + 1)A + kB. Adjacent sum = A + B.
    Solving (k + 1)A + kB = A + B yields k*A + (k - 1)B = 0.
    A valid non-zero choice is A = k - 1 and B = -k.
    When n = 3 (k = 1), A becomes 0, which is invalid since elements must be non-zero.

• Approach:
  - If n is even: Output alternating sequence of [1, -1, 1, -1, ...].
  - If n == 3: Output "NO".
  - If n is odd and n > 3: Set k = n / 2. Output alternating sequence of [k - 1, -k, k - 1, -k, ..., k - 1].

• Why it Works:
  - Even n: Array sum = (n/2)*1 + (n/2)*(-1) = 0. Adjacent sum = 1 + (-1) = 0. Matches.
  - Odd n (n > 3): Total sum = (k + 1)*(k - 1) + k*(-k) = k^2 - 1 - k^2 = -1. 
    Adjacent sum = (k - 1) + (-k) = -1. Matches.

• Time Complexity (TC) : O(N) per test case, to print the array.
• Space Complexity (SC): O(1) auxiliary space (excluding standard output stream).
=========================================================
*/

/*
=========================================================
FINAL APPROACH
=========================================================
• Chosen because it solves the construction in deterministic O(N) time with O(1) extra memory.
• Directly handles both even and odd length constraints using simple algebraic properties.
=========================================================
*/

void solve() {
    int n;
    cin >> n;

    if (n % 2 == 0) {
        cout << "YES\n";
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) cout << 1 << " ";
            else cout << -1 << " ";
        }
        cout << "\n";
    } else if (n == 3) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        int k = n / 2;
        int a = k - 1;
        int b = -k;
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) cout << a << " ";
            else cout << b << " ";
        }
        cout << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
