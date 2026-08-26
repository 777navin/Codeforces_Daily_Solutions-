/*
=========================================================
Date        : 26-08-2026
Problem Name: Vlad Building Beautiful Array (1833C)
Platform    : Codeforces
Difficulty  : 800
Tags        : greedy, math, sortings

Problem Summary:
Determine if it is possible to transform an array `a` into a beautiful 
array `b` where all elements are positive and share the same parity (all even or all odd).
Each element `b[i]` can be either `a[i]` or `a[i] - a[j]` for any `j`.

Key Observation:
If all elements are already even, or if the smallest element in the entire array is odd, 
it is always possible to make all elements odd (or all even). Otherwise, it is impossible.
=========================================================
*/

/*
=========================================================
APPROACH 1: Most Optimal (Single Pass Parity & Min Element Check)
=========================================================

• Intuition:
  - To make all elements odd: Odd numbers remain unchanged (`odd - nothing`). An even number can become odd via `even - odd` if an odd number strictly smaller than it exists.
  - To make all elements even: Even numbers remain unchanged. An odd number can become even via `odd - odd` if an odd number strictly smaller than it exists, but the smallest odd number has no smaller odd to subtract from, making it impossible unless the array has no odd numbers at all.
  - Therefore, if the minimum element overall is odd, we can always make all elements odd. If there are no odd numbers, all elements are already even.

• Approach:
  - Find the global minimum element and track if any odd number exists in the array.
  - If no odd number exists, answer YES (all are already even).
  - If the global minimum element is odd, answer YES (all can be made odd).
  - Otherwise, answer NO.

• Why it Works:
  - An even number `e > min_odd` can be transformed to `e - min_odd > 0` (odd).
  - An odd number `o` can stay as `o` (odd).
  - Hence, having `min_element` be odd guarantees every element can be represented as a positive odd integer.

• Time Complexity (TC) : O(n) per testcase
• Space Complexity (SC): O(1) auxiliary space
=========================================================
*/

/*
=========================================================
FINAL APPROACH:
- Chosen because it solves the parity constraints in a single O(n) pass without sorting.
- Optimal in both time O(n) and auxiliary space O(1), easily handling sum(n) <= 2e5.
=========================================================
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    int min_val = 2e9;
    bool has_odd = false;
    
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x < min_val) {
            min_val = x;
        }
        if (x % 2 != 0) {
            has_odd = true;
        }
    }
    
    // If no odd numbers exist, all elements are already even.
    // If the global minimum is odd, all elements can be made odd.
    if (!has_odd || min_val % 2 != 0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
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
