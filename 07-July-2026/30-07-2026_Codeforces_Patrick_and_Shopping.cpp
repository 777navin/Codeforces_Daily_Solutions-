/*
=========================================================
Date        : 30-07-2026
Problem Name: Patrick and Shopping
Platform    : Codeforces
Difficulty  : 800 (Easy)
Tags        : Implementation, Geometry, Math

Problem Summary:
Patrick needs to visit two shops from his house and return back home.
He is given three road lengths: d1 (house to shop 1), d2 (house to shop 2), 
and d3 (between shop 1 and shop 2). Calculate the minimum total distance required.

Key Observation:
There are only four possible valid paths to visit both shops and return home.
The minimum distance is simply the minimum among all four valid path lengths.
=========================================================
*/

#include <iostream>
#include <algorithm>

using namespace std;

/*
---------------------------------------------------------
1. Most Optimal Approach
---------------------------------------------------------
• Intuition:
  Patrick starts at house H and needs to visit Shop 1 (S1) and Shop 2 (S2), then return to H.
  The four possible routes are:
  1. H -> S1 -> S2 -> H : d1 + d3 + d2
  2. H -> S1 -> H -> S2 -> H : 2 * d1 + 2 * d2
  3. H -> S1 -> S2 -> S1 -> H : 2 * d1 + 2 * d3
  4. H -> S2 -> S1 -> S2 -> H : 2 * d2 + 2 * d3

• Approach:
  Calculate the total distance for each of the four possible routes using basic arithmetic.
  Find and print the minimum value among the four paths.

• Why it Works:
  Since there are only three nodes (House, Shop 1, Shop 2) and Patrick must visit both shops,
  these four paths cover all valid ways to traverse the graph and return home.

• Time Complexity (TC): O(1) - Constant number of basic arithmetic operations.
• Space Complexity (SC): O(1) - Uses a constant amount of memory.
---------------------------------------------------------
*/

/*
---------------------------------------------------------
FINAL APPROACH SELECTION
---------------------------------------------------------
• Why this approach is chosen:
  It directly evaluates all valid routes exhaustively in constant time.
• Why it is better than previous ones:
  Since the graph size is fixed (3 locations), checking all 4 valid paths guarantees 
  the optimal answer without complex graph algorithms or overhead.
---------------------------------------------------------
*/

void solve() {
    long long d1, d2, d3;
    if (!(cin >> d1 >> d2 >> d3)) return;

    long long path1 = d1 + d2 + d3;
    long long path2 = 2 * (d1 + d2);
    long long path3 = 2 * (d1 + d3);
    long long path4 = 2 * (d2 + d3);

    long long min_distance = min({path1, path2, path3, path4});

    cout << min_distance << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
