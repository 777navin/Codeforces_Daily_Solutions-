/*
=========================================================
Date        : 07-10-2026
Problem Name: Seating Arrangements (easy version)
Platform    : Codeforces
Difficulty  : 1100
Tags        : Greedy, Sorting, Data Structures

Problem Summary:
There are m seats in a single row (n = 1) and m people with given sight levels.
People enter one by one in the given order and occupy their assigned seats.
When a person moves to their seat, their inconvenience is the number of already occupied seats they pass by.
We need to assign seats to minimize the total inconvenience while satisfying that smaller sight levels get smaller seat indices.

Key Observation:
Since n = 1, smaller sight levels must strictly get smaller seat indices. For people with equal sight levels,
assigning larger seat indices to earlier-arriving people (or processing them such that earlier people sit further right among equal values)
ensures that an earlier person with the same sight level doesn't block a later person with the same sight level, minimizing total inconvenience.
=========================================================
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
=========================================================
APPROACH 1: Simulation using Sorting and Inversion Counting (Optimal)
=========================================================

• Intuition:
  To minimize inconvenience for people with equal sight levels, we should assign larger seat numbers to people who arrive earlier among equals.
  This prevents earlier people from blocking later ones with the same sight value.

• Approach:
  1. Store each person's sight level along with their initial 0-based arrival index.
  2. Sort the array primarily by sight level in ascending order. For equal sight levels, sort by arrival index in descending order.
  3. The position in the sorted array determines the assigned seat for each person.
  4. Iterate through the assigned seats and for each seat, count how many previously seated people occupy lower seat indices.

• Why it Works:
  Sorting with descending index order for ties maximizes seat numbers for earlier arrivals, making them sit to the right of later arrivals with equal sight.
  Counting occupied seats to the left for each person arriving in original order directly yields the exact total inconvenience.

• Time Complexity (TC) : O(m^2) per testcase, which takes at most ~9 * 10^4 operations total and easily passes within 1.0s.
• Space Complexity (SC): O(m) to store person details and seating state.
=========================================================
*/

/*
=========================================================
FINAL APPROACH SELECTION
=========================================================
• Why this approach is chosen:
  It directly models the optimal seat assignment rule and efficiently calculates inconvenience.
• Why it is better than previous ones:
  Since m <= 300, an O(m^2) simulation per testcase is extremely simple, clean, and optimal within the constraints.
=========================================================
*/

struct Person {
    int sight;
    int id;
};

void solve() {
    int n, m;
    cin >> n >> m; // n = 1 in easy version
    
    vector<Person> a(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i].sight;
        a[i].id = i;
    }

    // Sort by sight ascending; for ties, sort by arrival index descending
    sort(a.begin(), a.end(), [](const Person& x, const Person& y) {
        if (x.sight != y.sight) {
            return x.sight < y.sight;
        }
        return x.id > y.id;
    });

    // pos[i] stores the seat index (0 to m-1) assigned to person i
    vector<int> pos(m);
    for (int seat = 0; seat < m; ++seat) {
        pos[a[seat].id] = seat;
    }

    int total_inconvenience = 0;
    vector<bool> occupied(m, false);

    // Process people in arrival order
    for (int i = 0; i < m; ++i) {
        int seat = pos[i];
        // Count occupied seats to the left
        for (int j = 0; j < seat; ++j) {
            if (occupied[j]) {
                total_inconvenience++;
            }
        }
        occupied[seat] = true;
    }

    cout << total_inconvenience << "\n";
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
