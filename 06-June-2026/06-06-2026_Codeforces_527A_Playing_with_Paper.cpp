/*
Date: 06-06-2026
Problem Name: 527A - Playing with Paper
Platform: Codeforces
Difficulty: 1100
Tags: Math, Number Theory, Implementation

Problem Summary:
Given a rectangular sheet of paper of size a x b (assume a >= b). 
We repeatedly cut out the largest possible square (b x b) from it. 
This process continues until we are left with a square piece. 
Calculate the total number of square pieces (ships) obtained.

Methods to Solve:
1. Brute Force (Simulation):
   - Intuition: Keep subtracting the smaller side from the larger side until a side 
     becomes zero.
   - Approach: While b > 0, count += a/b, then a = a % b, swap(a, b).
   - Time Complexity: O(log(min(a, b))) - Similar to the Euclidean Algorithm.
   - Space Complexity: O(1).

Comparison Table:
Method      | TC                | SC   | Best Use Case
------------|-------------------|------|--------------
Subtraction | O(a/b)            | O(1) | Slow for large a, b
Division    | O(log(min(a, b))) | O(1) | Optimal for all inputs

Final Recommended Solution:
The division-based approach (Euclidean algorithm) is necessary to pass 
the time constraints for large inputs.
*/

#include <iostream>
#include <algorithm>

using namespace std;

/**
 * Function to solve the Playing with Paper problem.
 * Using division (a/b) instead of repeated subtraction to handle 
 * large numbers efficiently.
 */
void solve() {
    long long a, b;
    if (!(cin >> a >> b)) return;

    long long total_squares = 0;

    // We need to keep reducing the rectangle
    while (b > 0) {
        // Add the number of squares of size (b x b) that can be cut from (a x b)
        total_squares += (a / b);

        // Standard Euclidean Algorithm step
        long long remainder = a % b;
        a = b;
        b = remainder;
    }

    cout << total_squares << endl;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // The problem doesn't specify multiple test cases, 
    // but the logic here handles a single pair as per standard Codeforces A-problems.
    solve();

    return 0;
}
