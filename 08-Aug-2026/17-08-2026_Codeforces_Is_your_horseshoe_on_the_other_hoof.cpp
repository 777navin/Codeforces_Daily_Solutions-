/*
=========================================================
Date        : 17-08-2026
Problem Name: 228A - Is your horseshoe on the other hoof?
Platform    : Codeforces
Difficulty  : 800
Tags        : implementation

Problem Summary:
Valera has 4 horseshoes, each with a color represented by an integer.
He wants all 4 horseshoes to have distinct colors.
Find the minimum number of horseshoes he needs to purchase.

Key Observation:
If Valera already possesses `k` distinct colors among his 4 horseshoes,
he needs to buy `4 - k` new horseshoes with distinct colors.
=========================================================
*/

/*
---------------------------------------------------------
APPROACH 1: Sorting & Linear Scan
---------------------------------------------------------
• Intuition:
  Sorting the 4 numbers groups duplicates together, making them easy to count.

• Approach:
  Read the 4 integers into an array, sort it, and count adjacent equal elements.

• Why it Works:
  Every pair of adjacent equal elements represents a duplicate shoe that must be replaced.

• Time Complexity (TC): O(1) — Sorting 4 elements takes constant time O(4 log 4).
• Space Complexity (SC): O(1) — Minimal auxiliary space used.

---------------------------------------------------------
APPROACH 2: Hash Set / Unique Elements (Optimal)
---------------------------------------------------------
• Intuition:
  A `std::set` or `std::unordered_set` automatically filters out duplicate color values.

• Approach:
  Insert all 4 shoe colors into a set, then the answer is simply `4 - set.size()`.

• Why it Works:
  The set contains only unique colors (`k`). To have 4 unique colors, exactly `4 - k` distinct shoes need to be bought.

• Time Complexity (TC): O(1) — Inserting 4 elements takes constant time.
• Space Complexity (SC): O(1) — Stores at most 4 elements.
---------------------------------------------------------
*/

/*
---------------------------------------------------------
FINAL APPROACH:
Using `std::set` is concise, completely avoids manual duplicate checking,
and directly conveys the intent of finding unique color counts in O(1) time and space.
---------------------------------------------------------
*/

#include <iostream>
#include <set>

using namespace std;

void solve() {
    set<int> unique_colors;
    for (int i = 0; i < 4; ++i) {
        int color;
        cin >> color;
        unique_colors.insert(color);
    }
    
    cout << 4 - static_cast<int>(unique_colors.size()) << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
