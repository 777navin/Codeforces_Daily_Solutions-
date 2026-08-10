/*
=========================================================
Date        : 10-08-2026
Problem Name: 1835A - k-th equality
Platform    : Codeforces
Difficulty  : 1700
Tags        : Math, Brute Force, Combinatorics

Problem Summary:
Find the k-th lexicographically smallest equality a + b = c, where 
a, b, and c have exact digit lengths A, B, and C respectively.
If fewer than k valid equalities exist, output -1.

Key Observation:
Since string lengths are strictly fixed, lexicographical order maps 
directly to the numerical order of 'a' and then 'b'. We can iterate 'a' 
and mathematically find the range of valid 'b' values for each 'a'.
=========================================================
*/

/*
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
1. Brute Force
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
• Intuition: Iterate through all possible values of 'a' and 'b'.
• Approach: Generate every valid 'a' (length A) and 'b' (length B), check if 'a + b' has length C, and count up to k.
• Why it Works: It strictly generates in lexicographical order.
• Time Complexity (TC): O(10^(A+B)), which results in TLE for A,B = 6.
• Space Complexity (SC): O(1).

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
2. Optimized Math/Counting
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
• Intuition: Instead of iterating 'b', we can instantly count how many valid 'b's exist for a chosen 'a'.
• Approach: Iterate over valid 'a'. For a fixed 'a', calculate the minimum and maximum possible 'b' such that 'b' has B digits and 'a+b' has C digits. Add the count of valid 'b's to a running total or subtract from k until we find the range containing the k-th answer.
• Why it Works: Bounding 'b' ensures we only count valid equations, processing entire blocks of 'b' in O(1) time per 'a'.
• Time Complexity (TC): O(10^A) per testcase, easily passing within the 1-second limit since large A values are bounded by max 5 testcases.
• Space Complexity (SC): O(1).
*/

/*
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
FINAL APPROACH
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
• The Optimized Math approach is chosen.
• It drops the inner loop over 'b', avoiding TLE, by calculating the exact contiguous bounds of 'b'.
• It efficiently pinpoints the exact equation without generating all combinations.
*/

#include <iostream>
#include <algorithm>

using namespace std;

// Helper to compute powers of 10 for bounds
long long power_of_10(int exp) {
    long long res = 1;
    for (int i = 0; i < exp; ++i) res *= 10;
    return res;
}

void solve() {
    int A, B, C;
    long long k;
    cin >> A >> B >> C >> k;

    // Numerical boundaries for the digit lengths
    long long min_a = power_of_10(A - 1);
    long long max_a = power_of_10(A) - 1;

    long long min_b_overall = power_of_10(B - 1);
    long long max_b_overall = power_of_10(B) - 1;

    long long min_c_overall = power_of_10(C - 1);
    long long max_c_overall = power_of_10(C) - 1;

    // Iterate through 'a' to find the lexicographically k-th answer
    for (long long a = min_a; a <= max_a; ++a) {
        // Find valid boundaries of 'b' for current 'a'
        long long min_b = max(min_b_overall, min_c_overall - a);
        long long max_b = min(max_b_overall, max_c_overall - a);

        if (min_b <= max_b) {
            long long valid_b_count = max_b - min_b + 1;
            
            // If the k-th element is within the current range of 'b's
            if (k <= valid_b_count) {
                long long b = min_b + k - 1;
                cout << a << " + " << b << " = " << a + b << "\n";
                return;
            }
            // Otherwise, decrement k and check the next 'a'
            k -= valid_b_count;
        }
    }
    
    // If the loop finishes without finding k elements
    cout << "-1\n";
}

int main() {
    // Fast I/O
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
