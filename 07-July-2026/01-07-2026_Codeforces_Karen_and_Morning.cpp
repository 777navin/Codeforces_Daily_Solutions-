/*
Date        : 01-07-2026
Problem Name: Karen and Morning
Platform    : Codeforces
Difficulty  : 1000
Tags        : Implementation, Brute Force

Problem Summary
Given a time in "hh:mm" format (24-hour), find the minimum number of minutes to wait until the time becomes a palindrome.

Constraints
00 <= hh <= 23
00 <= mm <= 59

Key Observation
Since the time cycle is short (24 hours * 60 minutes = 1440 minutes), we can simply simulate the process minute by minute until the time is a palindrome.
*/

#include <bits/stdc++.h>

using namespace std;

/*

Approach: Simulation (Brute Force)

Intuition:

The total number of minutes in a day is small (1440). We can increment

the current time by one minute repeatedly and check if it is a palindrome

until we find one.

Approach:

Read input in hh:mm format.

Convert to integer total minutes or handle hours and minutes separately.

Use a loop to increment time by 1 minute.

Convert the new time to a string (ensuring leading zeros).

Check if the string equals its reverse.

Return the counter of minutes elapsed.

Time Complexity: O(1) - The maximum iterations will never exceed 1440.

Space Complexity: O(1) - Constant space used.
*/

bool isPalindrome(int h, int m) {
string s = (h < 10 ? "0" : "") + to_string(h) + ":" + (m < 10 ? "0" : "") + to_string(m);
string rs = s;
reverse(rs.begin(), rs.end());
return s == rs;
}

void solve() {
string s;
cin >> s;
int h = stoi(s.substr(0, 2));
int m = stoi(s.substr(3, 2));

int minutes = 0;
while (!isPalindrome(h, m)) {
    m++;
    if (m == 60) {
        m = 0;
        h++;
    }
    if (h == 24) {
        h = 0;
    }
    minutes++;
}
cout << minutes << endl;
}

int main() {
// Fast I/O
ios_base::sync_with_stdio(false);
cin.tie(NULL);

solve();

return 0;
}

