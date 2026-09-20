/*
=========================================================
Date        : 20-09-2026
Problem Name: 817B - Makes And The Product
Platform    : Codeforces
Difficulty  : 1500
Tags        : combinatorics, sorting, math

Problem Summary:
Given an array of n positive integers, find the number of index 
triplets (i, j, k) with i < j < k such that the product 
a[i] * a[j] * a[k] is minimized.

Key Observation:
Since all numbers are positive, the minimum product must be formed by 
the three smallest values in the array. The answer depends only on the 
frequencies of these three smallest values.
=========================================================
*/

/*
---------------------------------------------------------
APPROACH 1: Brute Force
---------------------------------------------------------
• Intuition:
  Iterate through all possible triplets of indices, find the minimum 
  product, and count how many triplets achieve that minimum.

• Approach:
  Use three nested loops for indices i, j, k (0 <= i < j < k < n), 
  calculate their product, track the global minimum, and maintain a counter.

• Why it Works:
  It exhaustively evaluates every distinct index triplet defined in the problem.

• Time Complexity (TC): O(n^3) - TLE for n <= 10^5.
• Space Complexity (SC): O(1) - Auxiliary space.

---------------------------------------------------------
APPROACH 2: Optimal (Sorting + Combinatorics)
---------------------------------------------------------
• Intuition:
  Sorting the array brings the three smallest values to the first three positions: 
  a[0], a[1], and a[2]. The count of valid index triplets is purely a combinatorial 
  choice from the available counts of these distinct numbers.

• Approach:
  1. Sort the array in non-decreasing order.
  2. Inspect the values at index 0, 1, and 2:
     - Case 1: a[0] == a[1] == a[2]
       All three values are identical. If this value appears `c` times in total, 
       we choose any 3 elements: C(c, 3) = c * (c - 1) * (c - 2) / 6.
     - Case 2: a[0] == a[1] < a[2]
       The first two values are identical and the third is different. We must pick 
       the two identical elements, and choose 1 element equal to a[2]: C(count(a[2]), 1).
     - Case 3: a[0] < a[1] == a[2]
       The smallest is unique, and the next two are identical. We pick 1 element 
       equal to a[0] and choose 2 elements equal to a[1]: C(count(a[1]), 2) = c * (c - 1) / 2.
     - Case 4: a[0] < a[1] < a[2]
       All three values are distinct. We pick 1 of each: 1 * 1 * count(a[2]).

• Why it Works:
  All numbers are positive, so minimizing the product is strictly equivalent to 
  picking the three smallest values. Combinatorics counts all valid index sets directly.

• Time Complexity (TC): O(n log n) - Dominated by sorting.
• Space Complexity (SC): O(1) - In-place sorting (excluding input array).
*/

/*
=========================================================
FINAL APPROACH:
The Optimal Approach (Sorting + Combinatorics) is chosen because 
n can be up to 10^5, where an O(n^3) brute force will result in Time Limit Exceeded. 
Sorting takes O(n log n) time and counting frequencies takes O(n), 
which easily runs well within the 2.0-second time limit.
=========================================================
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    long long ans = 0;

    if (a[0] == a[2]) {
        // Case 1: All three smallest elements are identical (a[0] == a[1] == a[2])
        long long count = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] == a[0]) {
                count++;
            }
        }
        ans = count * (count - 1) * (count - 2) / 6;
    } else if (a[1] == a[2]) {
        // Case 2: a[0] < a[1] == a[2]
        long long count = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] == a[1]) {
                count++;
            }
        }
        ans = count * (count - 1) / 2;
    } else {
        // Case 3: a[0] <= a[1] < a[2] (covers a[0] == a[1] < a[2] and a[0] < a[1] < a[2])
        long long count = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] == a[2]) {
                count++;
            }
        }
        ans = count;
    }

    cout << ans << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
