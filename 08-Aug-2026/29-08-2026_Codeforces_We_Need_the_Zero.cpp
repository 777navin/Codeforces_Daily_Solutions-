/*
=========================================================
Date        : 29-08-2026
Problem Name: We Need the Zero
Platform    : Codeforces
Difficulty  : 800
Tags        : Bitmasks, Greedy, XOR

Problem Summary:
Given an array `a` of length `n`, we want to find if there exists an integer `x` (0 <= x < 2^8) such that XOR-ing every element by `x` results in an array whose total XOR sum is 0.

Key Observation:
- For any number `n`, XOR-ing a number with itself an even number of times cancels it out, and an odd number of times leaves it.
- Specifically, if `n` is odd, choosing `x = total_xor` makes the resulting XOR sum 0. If `n` is even, `x` works only if the initial total XOR is 0, otherwise no such `x` exists.
=========================================================
*/

/*
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
APPROACH EXPLANATION
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

1. Optimized (Single Pass / Direct Calculation)
• Intuition: The effect of XOR-ing all elements in the array by `x` depends on the parity of the array length `n`.
• Approach: Compute the cumulative XOR sum of all elements in the array. If `n` is odd, the required `x` is simply the total XOR sum. If `n` is even, check if the total XOR sum is 0; if yes, `x = 0` works, otherwise it's impossible.
• Why it Works: Due to the properties of the XOR operation (associative and commutative), applying `x` to `n` elements XORs the total sum by `x` `n` times.
• Time Complexity (TC): O(n) per test case.
• Space Complexity (SC): O(1) auxiliary space.

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
FINAL APPROACH
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
We use the Optimized approach because it runs in linear time per testcase and directly evaluates the mathematical condition required by the XOR properties, perfectly fitting the constraints.
*/

#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int total_xor = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        total_xor ^= a[i];
    }

    if (n % 2 != 0) {
        cout << total_xor << "\n";
    } else {
        if (total_xor == 0) {
            cout << 0 << "\n";
        } else {
            cout << -1 << "\n";
        }
    }
}

int main() {
    // Optimize standard input/output streams for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
