/*
Date: 26-06-2026
Problem Name: Similar Pairs
Platform: Codeforces
Difficulty: 1100
Tags: Constructive Algorithms, Greedy, Sorting, Math

Problem Summary:
Given an even number of integers, partition them into pairs such that each pair is 'similar'.
Two numbers are similar if they have the same parity or if their absolute difference is exactly 1.

Methods to Solve:
1. Greedy Approach (Optimal)

For Greedy Approach:
- Intuition: 
  If the number of even integers is even, the number of odd integers must also be even. 
  In this case, we can pair all evens together and all odds together, so the answer is always YES.
  If the number of evens (and odds) is odd, we need at least one pair of numbers (x, y) 
  such that |x - y| = 1 to 'convert' an even parity mismatch into a valid partition.
- Approach:
  Count total odds and evens. 
  If both are even, print YES.
  If both are odd, check if there exists at least one pair (x, y) such that abs(x - y) == 1.
  If such a pair exists, print YES, otherwise NO.
- Dry Run: 
  Array: [11, 14, 16, 12] -> 1 odd, 3 evens. Pair (11, 12) exists. YES.
  Array: [1, 8] -> 1 odd, 1 even. No |x-y|==1. NO.
- Time Complexity: O(n log n) due to sorting for checking adjacent difference.
- Space Complexity: O(1) beyond input storage.

Comparison Table:
Method | TC | SC | Best Use Case
Greedy | O(n log n) | O(1) | Optimal for constraints n <= 50

Final Recommended Solution
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int odd = 0, even = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] % 2 == 0) even++;
        else odd++;
    }

    // If counts are already even, we can pair evens with evens and odds with odds.
    if (even % 2 == 0 && odd % 2 == 0) {
        cout << "YES" << endl;
        return;
    }

    // If counts are odd, we need at least one pair with difference 1 to balance parities.
    sort(a.begin(), a.end());
    bool found = false;
    for (int i = 0; i < n - 1; ++i) {
        if (abs(a[i] - a[i + 1]) == 1) {
            found = true;
            break;
        }
    }

    if (found) cout << "YES" << endl;
    else cout << "NO" << endl;
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
