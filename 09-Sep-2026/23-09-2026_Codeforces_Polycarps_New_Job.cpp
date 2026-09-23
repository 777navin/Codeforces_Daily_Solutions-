/*
=========================================================
Date        : 23-09-2026
Problem Name: Polycarp's New Job (1101E)
Platform    : Codeforces
Difficulty  : 1500
Tags        : greedy, implementation

Problem Summary:
Polycarp receives bills of dimensions x * y and checks if all bills collected 
so far fit into a rectangular wallet of size h * w. Bills can be rotated by 90 degrees 
and can overlap freely inside the wallet.

Key Observation:
Since bills and wallets can rotate, standardize every rectangle so that side1 <= side2. 
A wallet (h, w) can hold all bills if and only if min(h, w) >= max_of_all_min(x, y) 
and max(h, w) >= max_of_all_max(x, y).
=========================================================
*/

/*
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
APPROACH EXPLANATION
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

1. Brute Force:
   • Intuition:
     Store every bill in a list. For each query, iterate through all previously added 
     bills and verify if each bill can fit into the wallet with or without rotation.
   • Approach:
     Maintain a vector of pairs. On type 1 queries, push (x, y). On type 2 queries, loop 
     through the entire vector and check (min(x, y) <= min(h, w) && max(x, y) <= max(h, w)).
   • Why it Works:
     It directly validates the condition for every bill independently.
   • Time Complexity:
     O(n^2) overall in the worst case, leading to TLE since n <= 5 * 10^5.
   • Space Complexity:
     O(n) to store all incoming bills.

2. Most Optimal (Running Maximums):
   • Intuition:
     A wallet can hold all bills if and only if it can accommodate the bill with the largest 
     smaller dimension and the bill with the largest larger dimension.
   • Approach:
     Orient all rectangles so that the shorter dimension is x' = min(x, y) and the longer 
     dimension is y' = max(x, y). Maintain global running maximums: max_x and max_y.
     For queries with wallet (h, w), reorient h' = min(h, w) and w' = max(h, w).
     Check if max_x <= h' and max_y <= w'.
   • Why it Works:
     Orienting both bills and wallets in a canonical sorted orientation minimizes constraints 
     and allows tracking only the tightest bound across all bills in O(1) time.
   • Time Complexity:
     O(1) per query, leading to O(n) total runtime.
   • Space Complexity:
     O(1) auxiliary space, requiring no bill storage.
*/

/*
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
FINAL APPROACH
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
• Why this approach is chosen:
  It processes each insertion and query in O(1) time using minimal auxiliary space, 
  which easily passes within the 3.0s time limit for n = 5 * 10^5 queries.
• Why it is better than the previous ones:
  Eliminates storing all historical rectangles and avoids the O(n^2) time complexity of the brute force.
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    int max_smaller = 0;
    int max_larger = 0;

    while (n--) {
        char type;
        int a, b;
        cin >> type >> a >> b;

        int smaller = min(a, b);
        int larger = max(a, b);

        if (type == '+') {
            // Update the maximum required dimensions
            max_smaller = max(max_smaller, smaller);
            max_larger = max(max_larger, larger);
        } else if (type == '?') {
            // Check if current maximums fit into the given wallet
            if (max_smaller <= smaller && max_larger <= larger) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }

    return 0;
}
