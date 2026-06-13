/*
Date: 13-06-2026
Problem Name: Long Long
Platform: Codeforces
Difficulty: 800
Tags: greedy, math, implementation

Problem Summary:
Given an array of n integers, we can multiply any subarray by -1 as many times as we want.
We need to find:
1. The maximum possible sum of the array elements.
2. The minimum number of operations required to achieve this maximum sum.

Methods to Solve:
1. Optimal Approach (Greedy):
   - Intuition: To maximize the sum, we want all elements to be non-negative. If we have a sequence of negative numbers, we can flip them to positive in one operation. Zeros can be included in a flip without changing the sum, which helps to merge adjacent negative segments into a single operation.
   - Approach: Iterate through the array. Whenever we encounter a negative number, start a new operation. Continue this operation as long as the numbers are negative or zero. Once we hit a positive number, the operation ends.
   - Dry Run: [1, -2, 0, 3, -1]
     - Abs sum = 1+2+0+3+1 = 7.
     - Negative segments: [-2, 0] and [-1]. Total 2 operations.
   - Time Complexity: O(n)
   - Space Complexity: O(1)

Comparison Table:
Method | TC | SC | Best Use Case
Optimal Greedy | O(n) | O(1) | All cases

Final Recommended Solution: Use the Greedy approach to identify contiguous segments of negative numbers (including zeros that connect them).
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    long long max_sum = 0;
    int operations = 0;
    bool in_negative_segment = false;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        max_sum += abs(a[i]);

        if (a[i] < 0) {
            if (!in_negative_segment) {
                operations++;
                in_negative_segment = true;
            }
        } else if (a[i] > 0) {
            in_negative_segment = false;
        }
        // If a[i] == 0, we stay in the current state (in_negative_segment remains same)
    }

    cout << max_sum << " " << operations << endl;
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
