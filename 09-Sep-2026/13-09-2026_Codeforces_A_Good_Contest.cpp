/*
=========================================================
Date        : 13-09-2026
Problem Name: A. A Good Contest
Platform    : Codeforces
Difficulty  : 800
Tags        : implementation

Problem Summary:
Anton wants to know if he performed well in a contest.
A performance is good if he outscored at least one participant
who was rated red (>= 2400) before the contest and whose rating
increased strictly after the contest.

Key Observation:
We only need to check if there exists any participant i where
before_i >= 2400 and after_i > before_i.
=========================================================
*/

/*
---------------------------------------------------------
APPROACH 1: Single Pass Simulation (Optimal)
---------------------------------------------------------
• Intuition:
  The condition requires finding at least one user that satisfies two criteria:
  initial rating at least 2400, and a strictly positive rating change.

• Approach:
  - Read the number of participants n.
  - Iterate through all n entries, reading the handle, before rating, and after rating.
  - If before >= 2400 and after > before, flag the performance as good.
  - Output "YES" if flagged, otherwise "NO".

• Why it Works:
  The problem statement asks whether Anton outscored "some" participant
  meeting the criteria, which translates directly to an existential check.

• Time Complexity (TC):
  O(n) — A single linear pass through all n participants.

• Space Complexity (SC):
  O(1) — Only a few primitive variables and strings processed on the fly.
---------------------------------------------------------
*/

/*
---------------------------------------------------------
FINAL APPROACH:
---------------------------------------------------------
• Why this approach is chosen:
  It operates in a single pass in O(n) time and O(1) auxiliary space,
  which easily fits the constraint n <= 100 and the 1.0 second time limit.
• Why it is better than previous ones:
  It avoids allocating additional storage (like arrays or vectors)
  and processes each record directly as it is read.
---------------------------------------------------------
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    bool good_contest = false;

    for (int i = 0; i < n; ++i) {
        string name;
        int before, after;
        cin >> name >> before >> after;

        if (before >= 2400 && after > before) {
            good_contest = true;
        }
    }

    if (good_contest) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}
