/*
    Problem: C. Bear and String Distance
    Platform: Codeforces
    Date: 2026-04-15

    Approach:
    We need to build a new string t such that total alphabet distance
    between s and t is exactly k.

    For each character:
    - Maximum distance possible from current character is:
      max(c - 'a', 'z' - c)
    - Greedily take as much distance as possible at current position.

    If moving left gives required distance, move left.
    Else move right.

    If after processing all characters k > 0, answer is impossible.

    Time Complexity: O(n)
    Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    string ans = s;

    for (int i = 0; i < n; i++) {
        int leftDist = s[i] - 'a';
        int rightDist = 'z' - s[i];
        int mx = max(leftDist, rightDist);

        int use = min(k, mx);

        if (leftDist >= rightDist) {
            if (use <= leftDist)
                ans[i] = s[i] - use;
            else
                ans[i] = s[i] + use;
        } else {
            if (use <= rightDist)
                ans[i] = s[i] + use;
            else
                ans[i] = s[i] - use;
        }

        k -= use;
    }

    if (k > 0)
        cout << -1 << '\n';
    else
        cout << ans << '\n';

    return 0;
}
