/*
File Name: 24-04-2026_Codeforces_1485B_Replace_and_Keep_Sorted.cpp

Date: 24-04-2026
Problem Name: Replace and Keep Sorted
Platform: Codeforces
Contest: Round #701 (Div. 2)
Problem Code: 1485B
Difficulty: Medium
Tags: Prefix Sum, Binary Thinking, Arrays, Math, Queries

============================================================

Problem Summary:

Given a strictly increasing array a[1...n], and integer k.

For each query [l, r], consider subarray:
[a_l, a_{l+1}, ..., a_r]

We need count of arrays b such that:

1. b is strictly increasing
2. Same length as queried subarray
3. Each value in [1, k]
4. Differs from original subarray in exactly one position

Return answer for each query.

============================================================

Core Observation:

For any position i in [l, r], if we replace a[i], the new value must:

- keep array strictly increasing
- stay between neighbors
- be different from a[i]

Allowed values for replacement at position i:

For internal positions:
(a[i-1] + 1) ... (a[i+1] - 1), excluding a[i]

Count = a[i+1] - a[i-1] - 2

For left boundary i = l:
1 ... a[l+1]-1, excluding a[l]

Count = a[l+1] - 2

For right boundary i = r:
a[r-1]+1 ... k, excluding a[r]

Count = k - a[r-1] - 1

If l == r:
Any value from 1..k except a[l]
Answer = k - 1

============================================================

Efficient Formula:

For segment [l, r]:

ans =
(a[l+1] - 2)
+
(k - a[r-1] - 1)
+
sum of internal positions i=l+1..r-1:
(a[i+1] - a[i-1] - 2)

We preprocess:

gain[i] = a[i+1] - a[i-1] - 2   for 2 <= i <= n-1

Prefix sums allow O(1) query.

============================================================

Dry Run:

a = [1,2,4,5], k=5

Query [2,3] => [2,4]

left replace count  = a[3]-2 = 2
right replace count = 5-a[2]-1 = 2

Total = 4

============================================================

Complexities:

Preprocessing:
Time  O(n)
Space O(n)

Each Query:
Time  O(1)

Total:
O(n + q)

============================================================
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    ll k;
    cin >> n >> q >> k;

    vector<ll> a(n + 2, 0);

    for (int i = 1; i <= n; i++) cin >> a[i];

    // Prefix for internal contributions
    vector<ll> pref(n + 2, 0);

    for (int i = 2; i <= n - 1; i++) {
        ll gain = a[i + 1] - a[i - 1] - 2;
        pref[i] = pref[i - 1] + gain;
    }

    while (q--) {
        int l, r;
        cin >> l >> r;

        if (l == r) {
            cout << (k - 1) << '\n';
            continue;
        }

        ll ans = 0;

        // Left boundary position l
        ans += (a[l + 1] - 2);

        // Right boundary position r
        ans += (k - a[r - 1] - 1);

        // Internal positions l+1 ... r-1
        if (l + 1 <= r - 1) {
            ans += pref[r - 1] - pref[l];
        }

        cout << ans << '\n';
    }

    return 0;
}
