/*
=========================================================
Date        : 08-11-2026
Problem Name: Yet Another Promotion
Platform    : Codeforces
Difficulty  : 800
Tags        : Greedy, Math

Problem Summary:
- Buy at least n kilograms of potatoes.
- Day 1 costs a coins per kg.
- Day 2 costs b coins per kg.
- On day 1, buying m kg gives 1 kg free.

Key Observation:
- Every (m + 1) kg promotion bundle costs m * a.
- Remaining kilograms can be purchased at min(a, b).
- Compare this strategy with buying everything on day 2.
=========================================================

Approach 1: Brute Force

- Intuition:
  Try every possible combination of purchases.
- Approach:
  Enumerate quantities purchased on both days.
- Why it Works:
  All possible purchase combinations are considered.
- TC: O(n)
- SC: O(1)

Approach 2: Greedy (Optimized)

- Intuition:
  Use as many complete promotion bundles as possible.
- Approach:
  q = n / (m + 1)
  r = n % (m + 1)

  Promotion cost = q * m * a
  Remaining cost = r * min(a, b)

  Compare this with n * b.

- Why it Works:
  Complete promotion bundles provide the best
  first-day deal, while remaining kilograms are
  purchased at the cheaper individual price.

- TC: O(1) per test case.
- SC: O(1).

=========================================================
Final Approach:
Use the Greedy approach.
It calculates the maximum number of complete
promotion bundles and purchases the remainder
at the cheapest price. Compare against buying
everything on the second day.
=========================================================
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll a, b, n, m;
    cin >> a >> b;
    cin >> n >> m;

    ll bundles = n / (m + 1);
    ll remaining = n % (m + 1);

    ll promotionCost = bundles * m * a;
    ll remainingCost = remaining * min(a, b);

    ll promotionStrategy = promotionCost + remainingCost;
    ll secondDayStrategy = n * b;

    cout << min(promotionStrategy, secondDayStrategy) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
