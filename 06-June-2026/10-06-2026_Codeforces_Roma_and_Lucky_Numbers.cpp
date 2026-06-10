// 10-06-2026_Codeforces_Roma_and_Lucky_Numbers.cpp

/*
Date: 10-06-2026
Problem Name: Roma and Lucky Numbers
Platform: Codeforces
Difficulty: 800
Tags: implementation, strings

Problem Summary:
Given n positive integers, determine how many of these integers have at most k lucky digits. 
A lucky digit is defined as 4 or 7.

Methods to Solve:
1. Iterative Digit Extraction
   - Intuition: For each number, count the occurrences of digits '4' and '7' by extracting digits one by one or converting to string.
   - Approach: Iterate through the given list, convert each number to a string (or use modulo operator), count '4's and '7's, and check against k.
   - Dry Run (n=3, k=4, nums=[1, 2, 4]):
     - 1: count=0, 0 <= 4 (True)
     - 2: count=0, 0 <= 4 (True)
     - 4: count=1, 1 <= 4 (True)
     - Answer: 3
   - Time Complexity: O(n * log(max_ai)) where log(max_ai) is the number of digits.
   - Space Complexity: O(1) extra space.
   - When to use: Standard approach for small constraints.

Comparison Table:
Method | TC | SC | Best Use Case
Iterative Extraction | O(n * log(ai)) | O(1) | General constraint handling

Final Recommended Solution:
Iterative digit checking is optimal given the constraints (n, k <= 100).
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Function to count lucky digits (4 and 7) in a given number.
 */
int countLuckyDigits(int num) {
    int count = 0;
    string s = to_string(num);
    for (char c : s) {
        if (c == '4' || c == '7') {
            count++;
        }
    }
    return count;
}

void solve() {
    int n, k;
    if (!(cin >> n >> k)) return;

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (countLuckyDigits(a) <= k) {
            ans++;
        }
    }
    cout << ans << endl;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
