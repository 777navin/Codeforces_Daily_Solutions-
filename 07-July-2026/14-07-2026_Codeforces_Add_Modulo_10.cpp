/*
=========================================================
Date        : 14-07-2026
Problem Name: E. Add Modulo 10
Platform    : Codeforces
Difficulty  : 1400 (Rating)
Tags        : Math, Number Theory, Implementation

Problem Summary:
Given an array of n integers, we can repeatedly perform the operation 
a_i = a_i + (a_i % 10). We need to determine if it is possible to make 
all elements in the array equal by applying this operation any number of times.

Key Observation:
Numbers ending in 0 or 5 will always converge to a constant number ending in 0.
Numbers ending in 1, 2, 3, 4, 6, 7, 8, 9 cycle through last digits 2 -> 4 -> 8 -> 6 -> 2 
adding 20 every full cycle, meaning they can only be equalized if their values modulo 20 match.
=========================================================
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
---------------------------------------------------------
APPROACH 1: Modulo 20 and Base Normalization (Optimized)
---------------------------------------------------------
• Intuition:
  The operation behaves differently based on whether the last digit is part of a 
  regenerative cycle or leads to a trap state (0). By advancing every number to its 
  next stable state, we can reduce the problem to checking uniform congruency.

• Approach:
  1. For each element, if it ends in 5, advance it once by adding 5 so it ends in 0. 
     Elements ending in 0 cannot change further.
  2. For elements not ending in 0, advance them until their last digit becomes 2. 
     Since the cycle (2 -> 4 -> 8 -> 6) spans a net increase of 20, check if all 
     numbers share the exact same value modulo 20.
  3. If all elements ending in 0 match exactly, or all elements in the cycle match 
     modulo 20, return true; otherwise false.

• Why it Works:
  Advancing all non-zero-ending elements to end in 2 allows a direct comparison in 
  a period-20 system. Elements transitioning to 0 can never change again, so they must 
  be strictly identical to all other elements.

• Time Complexity (TC) : O(N) per testcase, since each element is advanced at most 5 times.
• Space Complexity (SC): O(1) auxiliary space beyond storing the input array.
*/

// Final Approach Selection:
// This is the optimal approach for this problem. It avoids simulating high values by exploiting 
// the repeating cycles of the modulo operation, meeting the strict 2.0-second time limit for N = 200,000.

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    bool has_zero = false;
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        
        // Normalize 5 to 0
        if (a[i] % 10 == 5) {
            a[i] += 5;
        }
        
        // If it ends in 0, it can never change anymore
        if (a[i] % 10 == 0) {
            has_zero = true;
        } else {
            // Cycle until the last digit is 2
            while (a[i] % 10 != 2) {
                a[i] += (a[i] % 10);
            }
        }
    }
    
    // Check consistency
    if (has_zero) {
        // If there is a 0, all elements must have been transformed to the exact same value
        for (int i = 1; i < n; ++i) {
            if (a[i] != a[0]) {
                cout << "NO\n";
                return;
            }
        }
    } else {
        // If there are no 0s, all elements must match modulo 20 (since they all end in 2)
        for (int i = 1; i < n; ++i) {
            if (a[i] % 20 != a[0] % 20) {
                cout << "NO\n";
                return;
            }
        }
    }
    
    cout << "YES\n";
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
