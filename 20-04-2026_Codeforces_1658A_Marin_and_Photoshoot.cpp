// Date: 20-04-2026
// Problem: Codeforces 1658A - Marin and Photoshoot
// Language: C++

#include <bits/stdc++.h>
using namespace std;

/*
==================================================
Problem Summary:
We have a binary string:
0 = male
1 = female

Need minimum additional people inserted anywhere so that
for every contiguous segment of length >= 2,
number of males never exceeds number of females.

Need minimum insertions.
==================================================
*/

/*
==================================================
Key Observation:
Only bad patterns are:

1. "00"
Two adjacent males.
Need 2 females inserted.
Contribution = +2

2. "010"
Male, female, male.
Need 1 extra female.
Contribution = +1

Count all such patterns.
==================================================
*/

/*
==================================================
Approach:
1. Traverse string and count every "00" -> add 2
2. Traverse string and count every "010" -> add 1
3. Print answer

Time Complexity: O(n)
Space Complexity: O(1)
==================================================
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        int ans = 0;

        // Count pattern "00"
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == '0' && s[i + 1] == '0') {
                ans += 2;
            }
        }

        // Count pattern "010"
        for (int i = 0; i < n - 2; i++) {
            if (s[i] == '0' && s[i + 1] == '1' && s[i + 2] == '0') {
                ans += 1;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}

/*
==================================================
Example:
Input:
3
3
000
3
010
3
111

Output:
4
1
0
==================================================
*/
