/*
=========================================================
Date        : 25-07-2026
Problem Name: A and B and Compilation Errors (519B)
Platform    : Codeforces
Difficulty  : 1100
Tags        : bitmasks, data structures, implementation, math, sortings

Problem Summary:
Given three arrays of sizes n, n-1, and n-2 representing compilation error codes, where one error is removed in each subsequent array. The order of errors is shuffled. Find the two removed errors.

Key Observation:
Since exactly one element is removed at each step, and the order is completely random, using properties like Sum or XOR will easily reveal the missing element without needing to sort or store the entire arrays.
=========================================================
*/

/*
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
APPROACH 1: Sorting
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
• Intuition: If we sort the arrays, the remaining elements will align until the missing element is encountered.
• Approach: Sort all three arrays. Iterate and compare array 1 with array 2 to find the first missing element, and array 2 with array 3 for the second.
• Why it Works: Sorting forces the same elements into the same positions, making the missing element stand out at the first mismatch.
• Time Complexity (TC): O(N log N) due to sorting.
• Space Complexity (SC): O(N) to store the arrays.

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
APPROACH 2: Sum Difference
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
• Intuition: The sum of elements in the first array minus the second array gives the removed element.
• Approach: Keep a running sum using a 64-bit integer (long long) for all three sequences and find their differences.
• Why it Works: Addition is commutative, so order doesn't matter. The difference in total sums must exactly equal the missing value.
• Time Complexity (TC): O(N) since we just iterate through the inputs.
• Space Complexity (SC): O(1) if we compute sums on the fly.

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
APPROACH 3: Bitwise XOR (Most Optimal)
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
• Intuition: XORing two identical numbers gives 0. XORing all elements of the first and second array leaves only the missing number.
• Approach: Compute the XOR sum of the first array and second array. The result is the first error. Repeat for the second and third array.
• Why it Works: XOR is commutative and associative (A ^ B ^ A = B). It inherently ignores order and extracts the single unpaired element.
• Time Complexity (TC): O(N) in a single pass.
• Space Complexity (SC): O(1) processing input on the fly.

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
FINAL APPROACH
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
We choose the Bitwise XOR approach (Approach 3).
It operates in optimal O(N) time and O(1) auxiliary space without requiring large data types like `long long` to prevent overflow, making it the most robust and efficient solution for competitive programming.
*/

#include <iostream>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    
    int val;
    int xor1 = 0, xor2 = 0, xor3 = 0;
    
    // Read first compilation errors
    for (int i = 0; i < n; ++i) {
        cin >> val;
        xor1 ^= val;
    }
    
    // Read second compilation errors
    for (int i = 0; i < n - 1; ++i) {
        cin >> val;
        xor2 ^= val;
    }
    
    // Read third compilation errors
    for (int i = 0; i < n - 2; ++i) {
        cin >> val;
        xor3 ^= val;
    }
    
    // First missing element
    cout << (xor1 ^ xor2) << "\n";
    
    // Second missing element
    cout << (xor2 ^ xor3) << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // Single test case for this problem
    solve();
    
    return 0;
}
