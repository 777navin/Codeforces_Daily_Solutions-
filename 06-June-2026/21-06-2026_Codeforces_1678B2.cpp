/**
 * Date: 22-06-2026
 * Problem Name: 1678B2 - Tokitsukaze and Good 01-String (hard version)
 * Platform: Codeforces
 * Difficulty: 1800
 * Tags: Greedy, Strings, Two Pointers
 * * Problem Summary:
 * You are given a binary string `s` of even length `n`. A string is "good" if it can 
 * be partitioned into contiguous subsegments of identical characters, where each 
 * subsegment has an even length. You can flip '0' to '1' or '1' to '0'. 
 * Find the minimum operations to make the string good. Additionally, among all 
 * solutions with the minimum operations, find the minimum number of subsegments 
 * the resulting string can be divided into.
 * * Methods to Solve:
 * 1. Brute Force (Backtracking on divergent pairs)
 * 2. Optimal Approach (Greedy / Pairing Observation)
 * * ==============================================================================
 * Method 1: Brute Force (Backtracking)
 * ==============================================================================
 * Intuition: 
 * Since every subsegment must be of even length, the string can naturally be broken 
 * down into pairs (s[0]s[1], s[2]s[3], ...). If a pair has different characters 
 * (e.g., '01' or '10'), we MUST flip one character to make them match (yielding '00' or '11').
 * We can try all possible valid assignments (00 or 11) for these mismatched pairs and count
 * the resulting subsegments to find the minimum.
 * * Approach:
 * - Identify all mismatched pairs. Each requires exactly 1 operation.
 * - Use recursion to try converting each mismatched pair to '00' and '11'.
 * - Evaluate the total contiguous subsegments for each generated string.
 * - Return the minimum subsegment count.
 * * Dry Run (small example): s = "1001"
 * - Pairs: (1,0) and (0,1). Ops = 2.
 * - Try "00" & "00" -> "0000" (1 segment)
 * - Try "00" & "11" -> "0011" (2 segments)
 * - Try "11" & "00" -> "1100" (2 segments)
 * - Try "11" & "11" -> "1111" (1 segment)
 * - Min segments = 1.
 * * Time Complexity: O(2 ^ (number of divergent pairs)) - Exponential, will TLE for N = 2*10^5.
 * Space Complexity: O(N) for recursion stack and string copies.
 * Why better than previous method: N/A (Baseline).
 * When to use: Never for large inputs, only for verification on small constraints.
 * * ==============================================================================
 * Method 2: Optimal Approach (Greedy / Pairing Observation)
 * ==============================================================================
 * Intuition:
 * As observed, we must process the string in adjacent pairs (s[2i], s[2i+1]). 
 * - If s[2i] != s[2i+1], it requires exactly 1 operation. We can flexibly turn it 
 * into '00' or '11' without increasing the operation count. To minimize subsegments, 
 * we should always make it match the nearest surrounding "fixed" pairs.
 * - If s[2i] == s[2i+1], it requires 0 operations and is considered "fixed".
 * Therefore, the "flexible" pairs act as wildcards and can just extend the current 
 * contiguous block. The number of subsegments only increases when we transition 
 * from a fixed '00' pair to a fixed '11' pair, or vice versa.
 * * Approach:
 * 1. Initialize `ops = 0`, `subsegments = 1` (minimum possible is 1 for a non-empty string).
 * 2. Maintain a `last_fixed` variable to track the character of the last identical pair (initialized to -1).
 * 3. Iterate through `s` in steps of 2:
 * a. If `s[i] != s[i+1]`, increment `ops`.
 * b. If `s[i] == s[i+1]`:
 * - If `last_fixed` is not -1 and `last_fixed != s[i]`, we are forced to break the contiguous segment. Increment `subsegments`.
 * - Update `last_fixed = s[i]`.
 * 4. Print `ops` and `subsegments`.
 * * Dry Run: s = "1110011000"
 * pairs: (11), (10), (01), (10), (00)
 * - pair 1 (11): ops=0, last_fixed='1', subsegments=1
 * - pair 2 (10): ops=1 (diff)
 * - pair 3 (01): ops=2 (diff)
 * - pair 4 (10): ops=3 (diff)
 * - pair 5 (00): ops=3, matches? No ('1' != '0'). subsegments=2, last_fixed='0'
 * Result: 3 ops, 2 subsegments.
 * * Time Complexity: O(N) - We traverse the string exactly once.
 * Space Complexity: O(1) - Only a few tracking variables are used.
 * Why better than previous method: Drastically reduces time complexity from exponential to linear.
 * When to use: Always optimal for this problem.
 * * ==============================================================================
 * Comparison Table:
 * Method         | TC           | SC   | Best Use Case
 * ------------------------------------------------------------------------------
 * Brute Force    | O(2^(N/2))   | O(N) | Debugging / understanding the state space.
 * Optimal Greedy | O(N)         | O(1) | Competitive programming, full constraints.
 * * Final Recommended Solution: Method 2 (Optimal Greedy)
 */

#include <iostream>
#include <string>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int ops = 0;
    int subsegments = 1;
    char last_fixed = -1; // -1 represents no fixed pair encountered yet

    for (int i = 0; i < n; i += 2) {
        if (s[i] != s[i + 1]) {
            // Mismatched pair requires 1 operation.
            // We can treat this pair as a wildcard, so it doesn't add a new subsegment.
            ops++;
        } else {
            // Matching pair requires 0 operations. It enforces its value.
            if (last_fixed != -1 && last_fixed != s[i]) {
                // We transitioned from one fixed type to another (e.g., '11' -> '00')
                subsegments++;
            }
            last_fixed = s[i];
        }
    }

    cout << ops << " " << subsegments << "\n";
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
