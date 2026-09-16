/*
=========================================================
Date        : 16-09-2026
Problem Name: Bear and Two Paths
Platform: Codeforces
Difficulty: 1600
Tags: Constructive Algorithms, Graphs

Problem Summary:
Find two distinct paths between pairs of cities (a to b, and c to d) using at most k edges.
Both paths must visit all n cities exactly once.
There are no direct roads allowed between (a, b) and (c, d).

Key Observation:
The absolute minimum number of unique edges required to form such paths is n + 1.
If n == 4 or k <= n, it is mathematically impossible to construct valid paths.
=========================================================
*/

/*
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
1. Optimal Construction
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
• Intuition:
  To minimize the total number of unique edges, both paths must share as many intermediate edges as possible.
  Creating a long, common central chain of intermediate nodes allows us to reuse edges effectively.

• Approach:
  Check if n == 4 or k <= n; if so, return -1.
  Collect all cities excluding a, b, c, and d into a shared sequence.
  Construct Path 1: a -> c -> [shared sequence] -> d -> b.
  Construct Path 2: c -> a -> [shared sequence] -> b -> d.

• Why it Works:
  Both paths share the entire middle sequence, leading to exactly n + 1 unique edges.
  Since n >= 5, there is at least one node in the shared sequence, preventing any forbidden direct connections between (a,b) and (c,d).

• Time Complexity (TC):
  O(N) - We only iterate from 1 to n to gather the remaining nodes and then print the results.

• Space Complexity (SC):
  O(N) - We use a vector to store the remaining n - 4 nodes.
*/

/*
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
FINAL APPROACH
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
• We use the Optimal Construction because it acts as a direct, deterministic formula.
• It entirely bypasses complex and expensive graph traversals, yielding the guaranteed minimum edges.
• The O(N) complexity is perfectly optimal for the constraints (n <= 1000).
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    if (!(cin >> n >> k)) return 0;

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    // Minimum required unique edges is n + 1
    // n = 4 forces forbidden connections or exceeds minimum paths
    if (n == 4 || k <= n) {
        cout << -1 << "\n";
        return 0;
    }

    // Gather all intermediate cities excluding a, b, c, and d
    vector<int> rem;
    for (int i = 1; i <= n; i++) {
        if (i != a && i != b && i != c && i != d) {
            rem.push_back(i);
        }
    }

    // Print Path 1: a -> c -> (intermediate cities) -> d -> b
    cout << a << " " << c << " ";
    for (int x : rem) {
        cout << x << " ";
    }
    cout << d << " " << b << "\n";

    // Print Path 2: c -> a -> (intermediate cities) -> b -> d
    cout << c << " " << a << " ";
    for (int x : rem) {
        cout << x << " ";
    }
    cout << b << " " << d << "\n";

    return 0;
}
