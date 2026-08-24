/*
=========================================================
Date        : 24-08-2026
Problem Name: Tanya and Toys
Platform    : Codeforces
Difficulty  : 1200
Tags        : Greedy, Implementation, Sorting, Data Structures

Problem Summary:
Tanya already owns n distinct toy types, where toy i costs i bourles.
Given a budget of m bourles, choose the maximum number of new distinct 
toys to purchase without exceeding the total budget m.

Key Observation:
To maximize the count of purchased items, always greedily pick the cheapest 
available toy type (1, 2, 3, ...) that Tanya does not already possess.
=========================================================
*/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

/*
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
APPROACH 1: Sorting / Hash Set Greedy
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
• Intuition:
  - Each toy `x` costs `x` bourles.
  - To maximize total toys bought, we should greedily buy the lowest-cost toys first.

• Approach:
  - Store Tanya's existing toys in an `unordered_set` or a sorted vector / `std::set`.
  - Iterate integer `toy = 1, 2, 3, ...`.
  - If `toy` is not owned and `toy <= remaining_budget`, add it to the answer and decrement budget by `toy`.
  - Stop when `toy > remaining_budget`.

• Why it Works:
  - Selecting any toy `y > x` instead of an available cheaper toy `x` only consumes more budget without giving a higher toy count.

• Time Complexity (TC):
  - O(N log N + K log N) or O(N + K) on average, where K is the number of toys bought (K <= sqrt(2 * 10^9) ≈ 45000).
• Space Complexity (SC):
  - O(N) to store owned toys.

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
FINAL APPROACH
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
• Uses a boolean lookup via `std::set` / sorted vector pointer to quickly check ownership.
• Greedily iterates starting from 1 to buy the maximum number of cheapest missing toys.
• Efficient and fits comfortably within the 1-second time limit since at most ~45,000 steps are needed.
*/

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long m;
    if (!(cin >> n >> m)) return 0;

    vector<int> owned(n);
    for (int i = 0; i < n; ++i) {
        cin >> owned[i];
    }

    sort(owned.begin(), owned.end());

    vector<int> bought;
    int owned_idx = 0;

    for (int toy = 1; ; ++toy) {
        if (m < toy) {
            break;
        }

        if (owned_idx < n && owned[owned_idx] == toy) {
            owned_idx++;
        } else {
            bought.push_back(toy);
            m -= toy;
        }
    }

    cout << bought.size() << "\n";
    for (size_t i = 0; i < bought.size(); ++i) {
        cout << bought[i] << (i + 1 == bought.size() ? "" : " ");
    }
    cout << "\n";

    return 0;
}
