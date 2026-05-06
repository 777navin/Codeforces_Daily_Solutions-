// 29-04-2026_Codeforces_Teleporters_Easy.cpp

/*
Date: 29-04-2026
Problem Name: G1. Teleporters (Easy Version)
Platform: Codeforces
Difficulty: 1100 (Approx)
Tags: Greedy, Sorting, Math

Problem Summary:
You start at point 0 on a number line. Teleporters are located at points 1 to n. 
Moving 1 unit costs 1 coin. Using a teleporter at point `i` costs `a_i` coins and 
instantly returns you to point 0. You have `c` coins. What is the maximum number 
of teleporters you can use? Once a teleporter is used, it cannot be used again.

Methods to Solve:
1. Brute Force (All Subsets) - O(2^N) [Conceptual]
2. Optimal Greedy Approach (Sorting) - O(N log N)

================================================================================
Method 1: Brute Force (Conceptual)
================================================================================
Intuition:
Generate all possible combinations of teleporters we could potentially visit. 
Calculate the total cost for each combination and track the maximum size of a 
valid combination that fits within `c` coins. 

Time Complexity: O(2^N)
Space Complexity: O(N) for recursion stack.
Why better than previous method: It isn't, but serves as a baseline.
When to use: Never for N = 2 * 10^5.

================================================================================
Method 2: Optimal Greedy Approach (Sorting)
================================================================================
Intuition:
Since using a teleporter always sends you back to point 0, the cost to use any 
teleporter `i` is completely independent of the other teleporters you choose.
To use teleporter `i`, you must walk `i` steps from 0 (costing `i` coins), and 
then pay the usage fee `a_i`. Thus, the total fixed cost to use teleporter `i` 
and return to 0 is `i + a_i`. 

To maximize the *number* of teleporters used, we should greedily pick the 
teleporters with the cheapest total round-trip cost until we run out of coins.

Approach:
1. For each teleporter `i` (from 1 to n), calculate its total cost: `cost[i] = i + a[i]`.
2. Store these costs in an array/vector.
3. Sort the costs in ascending order.
4. Iterate through the sorted costs:
   - If we have enough coins `c >= cost[i]`, subtract `cost[i]` from `c` and increment our count.
   - If `c < cost[i]`, we can't afford any more teleporters (since the array is sorted, 
     all subsequent ones will be even more expensive). Break early.
5. Return the count.

Dry Run (Small example):
n = 3, c = 10, a = [1, 2, 3]
- Teleporter 1: cost = 1 + a[1] = 1 + 1 = 2
- Teleporter 2: cost = 2 + a[2] = 2 + 2 = 4
- Teleporter 3: cost = 3 + a[3] = 3 + 3 = 6
Sorted Costs: [2, 4, 6]
- Try 2: c = 10 - 2 = 8. (Count = 1)
- Try 4: c = 8 - 4 = 4.  (Count = 2)
- Try 6: c = 4 < 6. Cannot afford. Break.
Max teleporters = 2.

Time Complexity: O(N log N) - Dominated by the sorting step.
Space Complexity: O(N) - To store the transformed costs array.

Why better than previous method: Drastically reduces time complexity, easily 
passing the 1-second time limit for N = 2*10^5.
When to use: Standard greedy choice when items have independent fixed costs and 
we want to maximize quantity.

================================================================================
Comparison Table:
Method               | TC         | SC   | Best Use Case
---------------------|------------|------|--------------------------------------
1. Brute Force       | O(2^N)     | O(N) | Never
2. Greedy Sorting    | O(N log N) | O(N) | Always, optimal for CP

Final Recommended Solution: Method 2 (Greedy Sorting)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Fast I/O for Competitive Programming
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

class Solution {
public:
    void solve() {
        int n;
        long long c;
        cin >> n >> c;
        
        vector<long long> costs;
        costs.reserve(n);
        
        for (int i = 1; i <= n; ++i) {
            long long a;
            cin >> a;
            // The cost to use teleporter 'i' is the distance 'i' plus the usage cost 'a'
            costs.push_back(i + a);
        }
        
        // Greedily sort to pick the cheapest teleporters first
        sort(costs.begin(), costs.end());
        
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (c >= costs[i]) {
                c -= costs[i];
                count++;
            } else {
                // If we can't afford the current cheapest, we can't afford any others
                break;
            }
        }
        
        cout << count << "\n";
    }
};

int main() {
    fast_io;
    
    int t;
    cin >> t;
    Solution sol;
    
    while (t--) {
        sol.solve();
    }
    
    return 0;
}
