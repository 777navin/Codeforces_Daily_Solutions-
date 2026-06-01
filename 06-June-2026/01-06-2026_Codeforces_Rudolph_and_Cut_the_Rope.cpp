/*
Date: 01-06-2026
Problem Name: 1846A - Rudolph and Cut the Rope
Platform: Codeforces
Difficulty: 800
Tags: Math, Implementation, Greedy

Problem Summary:
There are `n` nails at different heights `a_i`, each with a rope of length `b_i` attached. 
A single candy is tied to the free ends of all ropes. To make the candy reach the ground 
(height <= 0), we need to cut the minimum number of ropes. A rope prevents the candy 
from reaching the ground if the nail's height is strictly greater than the rope's length.

Methods to Solve:
1. Optimal Approach (Greedy / Counting)

-------------------------------------------------------------------------------------
Method 1: Optimal Approach (Greedy / Counting)
-------------------------------------------------------------------------------------
Intuition:
A rope restricts the candy from falling to the ground only if its length is strictly 
less than the height of the nail it is attached to. If the length `b_i` is greater 
than or equal to the height `a_i`, the rope is long enough to reach the ground. 
Therefore, we only need to cut the ropes that are too short to reach the ground.

Approach:
1. For each test case, read the number of nails `n`.
2. Initialize a counter `cuts = 0`.
3. Loop `n` times to read the height `a` and length `b` of each rope.
4. If `a > b`, the rope holds the candy above the ground, so it must be cut (`cuts++`).
5. Print the total `cuts` required for the test case.

Dry Run (Test Case 1):
n = 3
Ropes: 
1) a=4, b=3 -> 4 > 3 (Too short, needs cut) -> cuts = 1
2) a=3, b=1 -> 3 > 1 (Too short, needs cut) -> cuts = 2
3) a=1, b=2 -> 1 <= 2 (Long enough, reaches ground) -> cuts = 2
Total cuts = 2.

Time Complexity:
O(N) per test case, where N is the number of nails. We process each nail exactly once.
Overall Time Complexity: O(T * N).

Space Complexity:
O(1) because we only use a few integer variables to keep track of the counts and inputs, 
requiring no extra scaling memory.

Why better than previous method:
This is the most optimal and direct approach possible, as every input pair must be 
read and processed at least once (O(N) is the lower bound).

When to use:
This is the standard and only necessary approach for this problem constraint.

Comparison Table:
Method             | TC      | SC   | Best Use Case
-----------------------------------------------------------------
Optimal Approach   | O(N)    | O(1) | Standard CP execution

Final Recommended Solution: Method 1
*/

#include <iostream>

using namespace std;

// Function to solve individual test cases
void solve() {
    int n;
    cin >> n;
    
    int min_cuts = 0;
    
    for (int i = 0; i < n; ++i) {
        int height, length;
        cin >> height >> length;
        
        // If the height of the nail is greater than the rope's length, 
        // the rope will suspend the candy in the air, so it must be cut.
        if (height > length) {
            min_cuts++;
        }
    }
    
    cout << min_cuts << "\n";
}

int main() {
    // Fast I/O for Competitive Programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    // Process each test case
    while (t--) {
        solve();
    }
    
    return 0;
}
