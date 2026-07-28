/*
=========================================================
Date        : 28-07-2026
Problem Name: Elephant
Platform    : Codeforces
Difficulty  : 800
Tags        : math, greedy

Problem Summary:
An elephant needs to travel from point 0 to point x.
It can take steps of size 1, 2, 3, 4, or 5.
Find the minimum number of steps to reach exactly x.

Key Observation:
To minimize the total number of steps, always take the 
maximum possible step size (5) first.
=========================================================
*/

#include <iostream>

using namespace std;

/*
1. Brute Force (Simulation)
• Intuition: Keep taking the largest step (5) until the distance is zero.
• Approach: Use a loop to repeatedly subtract 5, then handle any remainder.
• Why it Works: Greedily taking the largest step minimizes total step count.
• Time Complexity (TC): O(N), where N is x / 5.
• Space Complexity (SC): O(1).

2. Most Optimal (Math)
• Intuition: Division gives the number of full 5-length steps. 
• Approach: Compute x / 5. If there is a remainder (x % 5 > 0), add 1 step. Alternatively, compute (x + 4) / 5.
• Why it Works: Mathematical division computes the greedy steps in a single operation.
• Time Complexity (TC): O(1).
• Space Complexity (SC): O(1).

Final Approach:
The mathematical approach ((x + 4) / 5) is chosen here. 
It is better because it executes in constant time O(1) without any loops.
This is the most efficient and concise way to solve the problem.
*/

void solve() {
    int x;
    cin >> x;
    
    // (x + 4) / 5 elegantly handles both exact multiples of 5 and remainders.
    cout << (x + 4) / 5 << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // The problem requires a single test case
    solve();
    
    return 0;
}
