/*
=========================================================
Date        : 24-10-2026
Problem Name: Super-Permutation
Platform    : Codeforces
Difficulty  : 1200
Tags        : math, constructive algorithms, number theory

Problem Summary:
- Given an integer n, find a permutation of numbers from 1 to n such that the prefix sums modulo n, when incremented by 1, also form a permutation of length n.
- If no such super-permutation exists, output -1.

Key Observation:
- For any odd n > 1, it is mathematically impossible to form a super-permutation, so the answer is -1.
- For even n, a valid sequence can be constructed using a precise alternating pattern of extremes.
=========================================================
*/

/*
=========================================================
APPROACH 1: Constructive Algorithm (Optimal)

• Intuition:
  - The prefix sums modulo n must cover all residues from 0 to n-1 uniquely.
  - For odd n > 1, the total sum modulo n is always 0, leading to duplicate residues, making it impossible.
• Approach:
  - If n = 1, output 1.
  - If n > 1 and n is odd, output -1.
  - If n is even, construct the permutation by placing n at the first position, followed by alternating elements using the pattern: n, n-1, 2, n-3, 4, n-5, etc.
• Why it Works:
  - This specific construction pattern ensures that all prefix sums modulo n are distinct, satisfying the permutation condition when incremented by 1.
• Time Complexity (TC): O(n) per test case.
• Space Complexity (SC): O(1) auxiliary space.
=========================================================
*/

/*
=========================================================
FINAL APPROACH:
- We use the constructive approach because it runs in linear time with O(1) extra space and correctly covers all constraints for even and odd test cases.
=========================================================
*/

#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;

    // For n > 1 and n is odd, a super-permutation does not exist.
    if (n > 1 && n % 2 != 0) {
        cout << -1 << "\n";
        return;
    }

    // For n = 1
    if (n == 1) {
        cout << 1 << "\n";
        return;
    }

    // For even n, generate using the correct constructive pattern
    for (int i = 1; i <= n; ++i) {
        if (i % 2 != 0) {
            if (i == 1) {
                cout << n << " ";
            } else {
                cout << i - 1 << " ";
            }
        } else {
            cout << n - (i - 1) << " ";
        }
    }
    cout << "\n";
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
