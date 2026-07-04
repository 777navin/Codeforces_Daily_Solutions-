/*
Date        : 04-07-2026
Problem Name: Make it Divisible by 25
Platform    : Codeforces
Difficulty  : 900
Tags        : brute force, greedy, math, strings

Problem Summary
Given a positive integer n, we want to make it divisible by 25 by removing the minimum number of digits.
A number is divisible by 25 if its last two digits are "00", "25", "50", or "75".

Constraints
1 <= t <= 10^4
25 <= n <= 10^18

Key Observation
Since we only need to care about the last two digits of the resulting number being 00, 25, 50, or 75,
we can iterate through the string representation of n from right to left to find the first occurrence
of these pairs and calculate the cost to bring them to the end of the string.
*/

#include <bits/stdc++.h>

using namespace std;

/

Approach: Greedy Search

Intuition: To make a number divisible by 25, the number must end with 00, 25, 50, or 75.

We look for these patterns from the end of the string.

For a target pair like "50":

Find the rightmost '0'.

From the position of that '0', find the rightmost '5' to its left.

The number of deletions required is: (total_digits - 1 - index_of_0) + (index_of_0 - index_of_5 - 1).
*/

int solve_for_pair(string n, string target) {
int n_len = n.length();
int count = 0;
int found_count = 0;

int last_digit = target[1];
int first_digit = target[0];

int pos1 = -1;
int pos2 = -1;

// Find rightmost last digit
for (int i = n_len - 1; i >= 0; i--) {
    if (n[i] == last_digit) {
        pos1 = i;
        break;
    }
}

if (pos1 == -1) return 1e9;

// Find rightmost first digit before pos1
for (int i = pos1 - 1; i >= 0; i--) {
    if (n[i] == first_digit) {
        pos2 = i;
        break;
    }
}

if (pos2 == -1) return 1e9;

// Cost: (digits after pos1) + (digits between pos2 and pos1)
return (n_len - 1 - pos1) + (pos1 - pos2 - 1);
}

void solve() {
string n;
cin >> n;

int ans = 1e9;
ans = min(ans, solve_for_pair(n, "00"));
ans = min(ans, solve_for_pair(n, "25"));
ans = min(ans, solve_for_pair(n, "50"));
ans = min(ans, solve_for_pair(n, "75"));

cout << ans << endl;
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

Method      | Idea                    | Time | Space | Difficulty | Recommended
Greedy      | Search for last 2 digits| O(N) | O(1)  | Easy       | Yes
Final Recommended Approach
The Greedy approach is the most efficient because we only need to perform a constant number of passes
(4, for each target pair) over the digits of the number. Since the number has at most 18-19 digits,
this is extremely fast and well within the time limits.
