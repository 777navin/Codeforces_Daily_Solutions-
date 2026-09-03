/*
=========================================================
Date        : 03-09-2026
Problem Name: Elimination
Platform    : Codeforces (1445B)
Difficulty  : 900
Tags        : greedy, math

Problem Summary:
At least 100 participants qualify for the finals based on their total score across two contests.
In contest 1, the 100th place has score 'a' and all top 100 have at least 'b' in contest 2.
In contest 2, the 100th place has score 'c' and all top 100 have at least 'd' in contest 1.
Find the minimum possible cutoff score (score of the 100th participant overall).

Key Observation:
Every participant in the top 100 of contest 1 has total score at least a + b, and
every participant in the top 100 of contest 2 has total score at least c + d.
=========================================================
*/

/*
---------------------------------------------------------
APPROACH 1: Most Optimal (Greedy / Math Observation)
---------------------------------------------------------
• Intuition:
  - There are 100 participants who scored >= a in contest 1 and >= b in contest 2.
    Each of these 100 participants has a sum of scores >= (a + b).
  - Similarly, there are 100 participants who scored >= d in contest 1 and >= c in contest 2.
    Each of these 100 participants has a sum of scores >= (c + d).

• Approach:
  - Since at least 100 people achieve a sum of at least (a + b), the 100th highest score cannot be less than (a + b).
  - Similarly, since at least 100 people achieve a sum of at least (c + d), the cutoff cannot be less than (c + d).
  - Hence, cutoff >= max(a + b, c + d).
  - We can construct a valid distribution of participants where exactly max(a + b, c + d) is attained by the 100th participant.

• Why it Works:
  - By Pigeonhole Principle and ranking properties, at least 100 participants achieve a sum of >= a + b, 
    and at least 100 achieve >= c + d. The lower bound max(a + b, c + d) is always achievable.

• Time Complexity (TC): O(1) per testcase.
• Space Complexity (SC): O(1) auxiliary space.
---------------------------------------------------------
*/

/*
---------------------------------------------------------
FINAL APPROACH:
The problem directly reduces to computing max(a + b, c + d) because both groups 
independently guarantee at least 100 participants with totals of at least (a + b) and (c + d).
It runs in strictly O(1) time and space per testcase, which easily passes within the 1.0s limit.
---------------------------------------------------------
*/

#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << max(a + b, c + d) << "\n";
}

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
