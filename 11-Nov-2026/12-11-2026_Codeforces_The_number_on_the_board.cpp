/*
=========================================================
Date        : 12-11-2026
Problem Name: B. The number on the board
Platform    : Codeforces
Difficulty  : 1100
Tags        : greedy, sorting

Problem Summary:
- We are given a target sum $k$ and a large positive integer $n$ given as a string.
- The initial number had a digit sum of at least $k$, but someone changed some digits to form $n$.
- We need to find the minimum number of digits that could have been changed (i.e., minimum digits we need to increase to reach a digit sum of at least $k$).

Key Observation:
- To minimize the number of digits changed, we should always greedily increase the smallest available digits (0 through 8) to 9, because replacing a digit with 9 yields the maximum possible increase in the sum ($\Delta = 9 - \text{digit}$).
=========================================================
*/

/*
=========================================================
APPROACH EXPLANATION
=========================================================

1. Greedy Approach
   • Intuition: To maximize the gain in digit sum with a single digit modification, we should pick the smallest digits in $n$ and change them to 9.
   • Approach: 
     1. Calculate the initial sum of digits of $n$.
     2. If the current sum is already $\ge k$, output 0.
     3. Otherwise, store all digits of $n$ in a list and sort them in ascending order.
     4. Iterate through the sorted digits from smallest to largest, greedily replacing each digit $d$ with 9, updating the sum by adding $(9 - d)$, and incrementing our change count.
     5. Stop as soon as the sum reaches or exceeds $k$.
   • Why it Works: Greedily increasing the smallest digits maximizes the added value per digit change, thereby minimizing the total number of changes required.
   • Time Complexity (TC): O(L log L) where L is the length of the string $n$ (due to sorting the digits).
   • Space Complexity (SC): O(L) to store and sort the digits.

=========================================================
FINAL APPROACH
=========================================================
- The greedy approach is chosen because sorting the digits and greedily upgrading the smallest ones to 9 guarantees the minimum number of modifications. It is optimal and easily handles strings of length up to $10^5$ within the 2-second time limit.
*/

#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

void solve() {
    long long k;
    if (!(cin >> k)) return;
    string s;
    cin >> s;

    long long current_sum = 0;
    vector<int> digits;
    for (char c : s) {
        int d = c - '0';
        current_sum += d;
        digits.push_back(d);
    }

    if (current_sum >= k) {
        cout << 0 << "\n";
        return;
    }

    sort(digits.begin(), digits.end());

    int changes = 0;
    for (int d : digits) {
        current_sum += (9 - d);
        changes++;
        if (current_sum >= k) {
            break;
        }
    }

    cout << changes << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
