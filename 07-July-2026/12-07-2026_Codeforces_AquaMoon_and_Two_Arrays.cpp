/*
=========================================================
Date        : 12-07-2026
Problem Name: AquaMoon and Two Arrays
Platform    : Codeforces
Difficulty  : 800
Tags        : Greedy, Math, Implementation

Problem Summary:
We are given two arrays 'a' and 'b' of the same size 'n'. We can perform an 
operation where we decrease an element a[i] by 1 and increase an element a[j] 
by 1, ensuring all elements remain non-negative. We need to determine if we 
can make array 'a' equal to array 'b' and output the sequence of operations.

Key Observation:
Since each operation decreases one element and increases another, the total sum 
of array 'a' remains invariant. Thus, a solution exists if and only if the sum 
of elements in 'a' equals the sum of elements in 'b', and we track the precise 
indices needing increments and decrements.
=========================================================
*/

#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

using namespace std;

/*
=========================================================
APPROACH: Greedy Index Matching (Optimized)
=========================================================
• Intuition:
  - If the sum of array 'a' is not equal to the sum of array 'b', it's impossible 
    to transform 'a' into 'b' because our operations preserve the total sum.
  - If the sums match, any position where a[i] > b[i] needs net decrements, and 
    any position where a[i] < b[i] needs net increments. We can simply match 
    these up greedily.

• Approach:
  - Calculate the sum of both arrays to check for validity.
  - Traverse the arrays and collect indices that need to be decreased into a 
    list `dec` and indices that need to be increased into a list `inc`.
  - Pair elements from `dec` and `inc` sequentially until all differences are resolved.

• Why it Works:
  - Because the net deficit equals the net surplus, every decrement can be perfectly 
    matched with a corresponding increment, ensuring the array elements match 'b' 
    exactly at the end.

• Time Complexity (TC) : O(n + sum(a_i)) -> Since the sum of elements <= 100, 
  the total operations are small and bounded by O(n).
• Space Complexity (SC): O(n) to store the indices for increments and decrements.
=========================================================
*/

/*
Final Approach Choice:
This approach is chosen because it directly solves the problem in a single pass 
to identify differences, followed by a linear pairing step. It satisfies all 
constraints optimally and adheres to the structural rules of the game.
*/

void solve() {
    int n;
    cin >> n;
    
    vector<int> a(n), b(n);
    int sum_a = 0, sum_b = 0;
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum_a += a[i];
    }
    
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        sum_b += b[i];
    }
    
    // If total sums do not match, transformation is impossible
    if (sum_a != sum_b) {
        cout << -1 << "\n";
        return;
    }
    
    vector<int> inc, dec;
    for (int i = 0; i < n; ++i) {
        if (a[i] > b[i]) {
            int diff = a[i] - b[i];
            while (diff--) {
                dec.push_back(i + 1); // 1-based indexing for output
            }
        } else if (a[i] < b[i]) {
            int diff = b[i] - a[i];
            while (diff--) {
                inc.push_back(i + 1); // 1-based indexing for output
            }
        }
    }
    
    // Total operations count
    cout << dec.size() << "\n";
    for (size_t k = 0; k < dec.size(); ++k) {
        cout << dec[k] << " " << inc[k] << "\n";
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
