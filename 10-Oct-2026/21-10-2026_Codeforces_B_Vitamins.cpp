/*
=========================================================
Date        : 21-10-2026
Problem Name: B. Vitamins
Platform    : Codeforces
Difficulty  : 1200
Tags        : bitmask, dp, implementation, greedy

Problem Summary:
- A shop sells $n$ juices, each with a price and a set of vitamins (subset of A, B, C).
- Petya needs to obtain all three vitamins (A, B, and C) by buying a combination of juices.
- Find the minimum total price required to get all three vitamins, or print -1 if it's impossible.

Key Observation:
- Since there are only 3 vitamins, there are $2^3 = 8$ possible vitamin masks (0 to 7).
- We can precompute the minimum cost for each of the 8 masks and check all valid combinations of 1, 2, or 3 juices.
=========================================================
*/

/*
=========================================================
APPROACH 1: Minimum Cost Tracking with Bitmasks

• Intuition:
  - Each juice provides a subset of vitamins which can be represented as a bitmask from 1 to 7.
  - We can store the minimum cost for each of the 8 possible vitamin masks.

• Approach:
  - Initialize an array `min_cost` of size 8 with a large infinity value (`1e15` to prevent overflow).
  - For each juice, convert its vitamin string to a bitmask and update `min_cost[mask] = min(min_cost[mask], price)`.
  - Check all possible combinations of 1, 2, or 3 juices whose bitmasks bitwise OR to 7 (covers A, B, and C).
  - Print the minimum cost found, or -1 if no valid combination exists.

• Why it Works:
  - With only 3 vitamins, checking all combinations of masks ($8 \times 8 \times 8$) is extremely efficient and covers all possible optimal selections of juices.
  - Using `long long` and a large infinity value (`1e15`) prevents integer overflow issues that occur with standard `1e9`.

• Time Complexity (TC): O(N + 8^3), which runs in a fraction of a millisecond and well within the 2-second limit.
• Space Complexity (SC): O(1), as the `min_cost` array is fixed at size 8.
=========================================================
*/

/*
=========================================================
FINAL APPROACH SELECTION:
- Precomputing minimum costs for each mask and iterating through valid combinations using `long long` ensures correctness and avoids the integer overflow issue from the previous attempt.
=========================================================
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const long long INF = 1e15;

int getMask(const string& s) {
    int mask = 0;
    for (char c : s) {
        if (c == 'A') mask |= 1;
        else if (c == 'B') mask |= 2;
        else if (c == 'C') mask |= 4;
    }
    return mask;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<long long> min_cost(8, INF);

    for (int i = 0; i < n; ++i) {
        long long c;
        string s;
        cin >> c >> s;
        int mask = getMask(s);
        min_cost[mask] = min(min_cost[mask], c);
    }

    long long ans = INF;

    // 1. Check single juice covering all 3 vitamins
    ans = min(ans, min_cost[7]);

    // 2. Check pairs of juices
    for (int i = 1; i < 8; ++i) {
        for (int j = 1; j < 8; ++j) {
            if ((i | j) == 7) {
                ans = min(ans, min_cost[i] + min_cost[j]);
            }
        }
    }

    // 3. Check triplets of juices
    for (int i = 1; i < 8; ++i) {
        for (int j = 1; j < 8; ++j) {
            for (int k = 1; k < 8; ++k) {
                if ((i | j | k) == 7) {
                    ans = min(ans, min_cost[i] + min_cost[j] + min_cost[k]);
                }
            }
        }
    }

    if (ans >= INF) {
        cout << -1 << "\n";
    } else {
        cout << ans << "\n";
    }

    return 0;
}
