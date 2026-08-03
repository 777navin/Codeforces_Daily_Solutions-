/*
=========================================================
Date        : 03-08-2026
Problem Name: Everybody Likes Good Arrays! (1777A)
Platform    : Codeforces
Difficulty  : 800 (Inferred)
Tags        : Greedy, Math

Problem Summary:
You are given an array of integers. You can multiply two adjacent 
elements of the same parity (both even or both odd) and replace 
them with their product. Find the minimum operations to make 
adjacent elements have different parities.

Key Observation:
Multiplying two numbers of the same parity yields a product of that 
same parity (Even * Even = Even, Odd * Odd = Odd). Therefore, we 
just need to count the number of adjacent elements with the same parity.
=========================================================
*/

/*
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
APPROACH EXPLANATION
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

1. Optimal Approach (Greedy Counting)
• Intuition: Since multiplying same-parity numbers keeps the parity 
  unchanged, any contiguous block of identical parity elements must 
  be reduced to a single element.
• Approach: Traverse the array starting from the second element. 
  Check if the current element and the previous element have the same 
  parity. If they do, increment an operation counter.
• Why it Works: Each operation reduces the size of a same-parity 
  segment by 1. The minimum operations required is exactly the total 
  number of adjacent same-parity pairs in the array.
• Time Complexity (TC): O(N) per test case, where N is the array size.
• Space Complexity (SC): O(N) to store the array, though it can be 
  optimized to O(1) if processed on the fly.

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
FINAL APPROACH
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
• Why this approach is chosen: It is the most optimal and direct way 
  to solve the problem in a single pass.
• Why it is better than the previous ones: It runs in linear time 
  and is perfectly suited for the given problem constraints.
*/

#include <iostream>
#include <vector>

using namespace std;

// Function to solve each test case
void solve() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int min_operations = 0;
    
    // Count adjacent elements with the same parity
    for (int i = 1; i < n; i++) {
        if ((a[i] % 2) == (a[i - 1] % 2)) {
            min_operations++;
        }
    }
    
    cout << min_operations << "\n";
}

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    // Process all test cases
    while (t--) {
        solve();
    }
    
    return 0;
}
