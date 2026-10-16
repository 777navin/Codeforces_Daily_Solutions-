/*
=========================================================
Date        : 16-10-2026
Problem Name: Lord of the Values
Platform: Codeforces
Difficulty: Medium
Tags: Constructive Algorithms, Math

Problem Summary:
Given an array of $n$ integers (where $n$ is even), we can perform operations that transform pairs of elements $(a_i, a_j)$ into various linear combinations. 
Our goal is to make all elements in the array equal to 0 using at most $6n$ operations.

Key Observation:
By choosing appropriate pairs and operations, we can systematically invert the signs or equate elements to cancel them out within the operation limit.
=========================================================
*/

/*
=========================================================
APPROACH EXPLANATION
=========================================================

1. Optimized Constructive Algorithm
   • Intuition: Since $n$ is even, we can process elements in pairs $(i, i+1)$ for $i = 1, 3, 5, \dots$.
   • Approach: For each pair, apply a fixed sequence of 6 operations that transforms $(a_i, a_j)$ into $(-a_i, -a_j)$ or zeros them out step-by-step.
   • Why it Works: The chosen sequence of operations guarantees that after 6 steps per pair, both values reach 0 or desired invariant states without exceeding $6n$ operations.
   • Time Complexity (TC): O(N)
   • Space Complexity (SC): O(1)
=========================================================
*/

/*
=========================================================
FINAL APPROACH
=========================================================
We use the direct constructive pairing approach because it runs in linear time with O(1) extra space and strictly adheres to the operation limits.
It avoids heavy simulation or search by leveraging mathematical invariants for each adjacent pair.
=========================================================
*/

#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    // Since n is even, we can process elements in pairs: (1, 2), (3, 4), ..., (n-1, n)
    // Each pair takes 6 operations. Total operations = 3 * n <= 6n.
    cout << 3 * n << "\n";
    for (int i = 1; i <= n; i += 2) {
        // Operation 1: v_i = v_i + v_j
        cout << 1 << " " << i << " " << i + 1 << "\n";
        // Operation 2: v_j = v_j - v_i
        cout << 2 << " " << i << " " << i + 1 << "\n";
        // Operation 3: v_j = v_j + v_i
        cout << 1 << " " << i << " " << i + 1 << "\n";
        // Operation 4: v_i = v_i + v_j
        cout << 1 << " " << i << " " << i + 1 << "\n";
        // Operation 5: v_j = v_j - v_i
        cout << 2 << " " << i << " " << i + 1 << "\n";
        // Operation 6: v_j = v_j + v_i
        cout << 1 << " " << i << " " << i + 1 << "\n";
    }
}

int main() {
    // Optimize standard I/O operations for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
