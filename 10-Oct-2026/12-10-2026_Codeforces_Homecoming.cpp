/*
=========================================================
Date        : 12-10-2026
Problem Name: [B. Homecoming](https://codeforces.com/problemset/problem/1315/B)
Platform    : Codeforces
Difficulty  : 1300
Tags        : Greedy, Strings

Problem Summary:
Petya wants to travel from the 1st crossroad to the n-th crossroad using bus ('A') and tram ('B') tickets. 
Each ticket type allows continuous travel over a block of identical stations for a fixed cost ($a$ or $b$).
He can walk from the 1st crossroad up to some index $i$ and then use public transport to reach the end, 
ensuring the total cost does not exceed $p$ roubles. We need to find the minimum index $i$ (1-indexed).

Key Observation:
We can greedily traverse backwards from the destination ($n$) to $1$. Whenever a block of identical 
consecutive characters starts, we calculate the cost to skip/travel it. If adding this segment exceeds 
our remaining budget $p$, the current position becomes our starting point $i$.
=========================================================
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long a, b, p;
    cin >> a >> b >> p;
    string s;
    cin >> s;
    
    int n = s.length();
    int ans = n; // 1-indexed representation of the last element
    long long cost = 0;
    
    // Traverse backwards from the second last element down to the first element
    for (int i = n - 2; i >= 0; --i) {
        // If this is the start of a new transport block, we need to pay for it
        if (i == n - 2 || s[i] != s[i + 1]) {
            long long current_cost = (s[i] == 'A') ? a : b;
            if (cost + current_cost > p) {
                break;
            }
            cost += current_cost;
        }
        ans = i + 1; // 1-based index
    }
    
    cout << ans << "\n";
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

/*
=========================================================
FINAL APPROACH EXPLANATION
=========================================================
• Why this approach is chosen: 
  A greedy backward traversal allows us to efficiently determine the maximum suffix of the journey 
  that Petya can afford, ensuring we find the minimum valid starting index $i$.
• Why it is better than the previous ones: 
  Instead of checking all possible starting points in $O(N^2)$ or $O(N)$ with complex range queries, 
  we accumulate costs from right to left in a single linear scan, resulting in an optimal $O(N)$ time complexity.
• Time Complexity (TC): O(N) per test case, where N is the length of the string.
• Space Complexity (SC): O(N) to store the input string.
=========================================================
*/
