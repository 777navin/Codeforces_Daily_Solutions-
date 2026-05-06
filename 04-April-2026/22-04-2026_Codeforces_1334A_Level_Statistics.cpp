/*
File Name: 22-04-2026_Codeforces_1334A_Level_Statistics.cpp

Date: 22-04-2026
Problem Name: A. Level Statistics
Platform: Codeforces
Contest: Codeforces Round 1334 (Div.2)
Difficulty: 1200 (Approx)
Tags:
Implementation, Greedy, Math, Validation

=========================================================
Problem Summary:

Polycarp records game stats multiple times.

Each record contains:
(p[i], c[i])

Where:
p[i] = total plays
c[i] = total clears

Rules:
1. Plays can only increase or stay same.
2. Clears can only increase or stay same.
3. Clears can never exceed plays.
4. Increase in clears between two records cannot exceed
   increase in plays.

Need to determine whether recorded sequence is valid.

=========================================================
Methods to Solve:

1. Direct Validation (Optimal)
---------------------------------------------------------
Check every consecutive pair.

For previous:
(prevP, prevC)

Current:
(curP, curC)

Conditions:
- curP >= prevP
- curC >= prevC
- curC <= curP
- (curC - prevC) <= (curP - prevP)

If any fail => NO

Else YES

---------------------------------------------------------
Dry Run:

(1,0) -> (1000,3)

plays increased = 999
clears increased = 3

3 <= 999 valid

---------------------------------------------------------
Time Complexity:
O(n) per test case

Space Complexity:
O(1)

=========================================================
Comparison Table:

Method              TC        SC      Best Use
------------------------------------------------
Simulation          O(n)      O(1)    Best / Required

=========================================================
Final Recommended Solution:
Single pass validation.

=========================================================
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    int prevP = 0, prevC = 0;
    bool valid = true;

    for (int i = 0; i < n; i++) {
        int p, c;
        cin >> p >> c;

        if (c > p) valid = false;                    // clears > plays
        if (p < prevP) valid = false;               // plays decreased
        if (c < prevC) valid = false;               // clears decreased
        if ((c - prevC) > (p - prevP)) valid = false; // clears increased too much

        prevP = p;
        prevC = c;
    }

    cout << (valid ? "YES" : "NO") << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}
