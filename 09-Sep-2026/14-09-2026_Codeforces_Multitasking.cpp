/*
=========================================================
Date        : 14-09-2026
Problem Name: B. Multitasking
Platform    : Codeforces
Difficulty  : 1500
Tags        : constructive algorithms, sortings

Problem Summary:
Given n arrays of size m, sort all of them simultaneously in 
either ascending (k=0) or descending (k=1) order. 
You can specify at most m(m-1)/2 pairs of indices (i, j), 
and elements at i and j will be swapped if val[i] > val[j].

Key Observation:
Since we are allowed exactly m(m-1)/2 operations, we can apply a 
universal sorting network (like Selection Sort) that sorts ANY array.
=========================================================
*/

/*
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
1. Optimal Approach (Universal Sorting Network)
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
• Intuition
  Instead of looking at the values of the n arrays to find a specific set of 
  swaps, we can blindly generate all pairs needed to sort an array in the worst case.
• Approach
  Iterate through all pairs (i, j) such that 1 <= i < j <= m.
  If k = 0 (ascending), emit pair (i, j). It swaps if val[i] > val[j].
  If k = 1 (descending), emit pair (j, i). It swaps if val[j] > val[i].
• Why it Works
  This mirrors the exact comparisons of Selection Sort. By comparing every element 
  with all subsequent elements, it unconditionally routes numbers to their correct sorted positions.
• Time Complexity (TC)
  O(n*m + m^2) -> O(n*m) to read the input matrices, and O(m^2) to print the pairs.
• Space Complexity (SC)
  O(1) -> We only need a few variables for indices; no extra arrays are stored.
*/

/*
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
FINAL APPROACH
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
• The universal sorting network approach is chosen because it operates optimally 
  within the m(m-1)/2 operations limit without needing to process the actual array values.
• It is highly efficient and guarantees correct sorting for any possible input variation.
*/

#include <iostream>

using namespace std;

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, k;
    if (!(cin >> n >> m >> k)) return 0;
    
    // Read the n arrays
    // We don't actually need to store or use their values 
    // because our sequence of swaps is universal.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
        }
    }
    
    // The number of operations will always be exactly m * (m - 1) / 2
    cout << (m * (m - 1)) / 2 << "\n";
    
    // Generate the universal sequence of pairs
    for (int i = 1; i <= m; i++) {
        for (int j = i + 1; j <= m; j++) {
            if (k == 0) {
                // Ascending order: swap if the earlier element is strictly greater
                cout << i << " " << j << "\n";
            } else {
                // Descending order: swap if the later element is strictly greater
                cout << j << " " << i << "\n";
            }
        }
    }
    
    return 0;
}
