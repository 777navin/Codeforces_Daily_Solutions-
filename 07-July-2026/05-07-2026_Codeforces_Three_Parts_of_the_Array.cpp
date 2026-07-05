/*
Date        : 05-07-2026
Problem Name: Three Parts of the Array
Platform    : Codeforces
Difficulty  : 1200
Tags        : Two Pointers, Binary Search, Prefix Sum

Problem Summary
Given an array d of n integers, split it into three consecutive parts (first, second, third) such that the sum of the first part equals the sum of the third part. Parts can be empty. Maximize the sum of the first part.

Constraints
1 <= n <= 2 * 10^5
1 <= di <= 10^9

Key Observation
Since all elements are positive (1 <= di), the prefix sum of the first part is monotonically increasing, and the suffix sum of the third part is monotonically increasing as we include more elements from the ends. We can use two pointers starting from both ends to find the matching sum efficiently.
*/

#include <bits/stdc++.h>

using namespace std;

/

APPROACH: Two Pointers

Intuition:

Maintain two pointers, 'l' at the beginning and 'r' at the end of the array.

Keep track of the current sum of the first part (sum1) and the third part (sum3).

If sum1 < sum3, we need to increase sum1, so move 'l' forward.

If sum1 > sum3, we need to increase sum3, so move 'r' backward.

If sum1 == sum3, we found a potential answer. Update the maximum and move both pointers.

Time Complexity: O(n)

Space Complexity: O(1)
*/

int main() {
// Fast I/O
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int n;
cin >> n;

vector<long long> d(n);
for (int i = 0; i < n; ++i) {
    cin >> d[i];
}

long long max_sum = 0;
long long sum1 = 0;
long long sum3 = 0;

int l = 0;
int r = n - 1;

while (l <= r) {
    if (sum1 <= sum3) {
        sum1 += d[l];
        l++;
    } else {
        sum3 += d[r];
        r--;
    }

    if (sum1 == sum3) {
        max_sum = sum1;
    }
}

cout << max_sum << endl;

return 0;
}

/*
Method          | Idea                 | Time | Space | Difficulty | Recommended
Two Pointers    | Shrink from ends     | O(n) | O(1)  | Easy       | Yes
Binary Search   | Search in Prefix Sum | O(n log n) | O(n) | Medium | No
FINAL RECOMMENDED APPROACH:
The Two Pointers approach is the most optimal because it traverses the array only once,
achieving linear time complexity O(n) with constant extra space O(1), which is well
within the limits for n = 2*10^5.
*/
