/*
Date: 10-05-2026
Problem Name: B. Alyona and flowers (740B)
Platform: Codeforces
Difficulty: 1200
Tags: Greedy, Math, Implementation

Problem Summary:
Alyona has `n` flowers, each with a specific "mood" value (positive, zero, or negative). 
Her mother suggests `m` subarrays (segments of consecutive flowers). Alyona can choose 
any number of these subarrays. The total happiness added is the sum of the moods of the 
flowers multiplied by the number of chosen subarrays they appear in. We need to find the 
maximum possible happiness she can achieve.

Observation: 
Adding a flower's mood multiplied by the number of subarrays it is in is mathematically 
equivalent to calculating the sum of each chosen subarray independently and adding them up. 
To maximize happiness, Alyona should simply choose all subarrays that have a strictly 
positive sum and ignore the rest.

Methods to Solve:
1. Brute Force
2. Optimal Approach (Prefix Sums)

--------------------------------------------------------------------------------------
Method 1: Brute Force

- Intuition: 
  For each subarray suggested by the mother, we can iterate from the start index `l` to 
  the end index `r` and calculate the sum. If the sum is greater than 0, it contributes 
  positively to the total happiness, so we add it.
- Approach: 
  Iterate `m` times. In each iteration, run a nested loop from `l` to `r` to find the 
  sum of the subarray. Accumulate the positive sums.
- Dry Run: 
  Array: [1, -2, 1, 3, -4]
  Subarrays:
  - [1, 2] -> 1 + (-2) = -1 (Ignore, sum <= 0)
  - [4, 5] -> 3 + (-4) = -1 (Ignore, sum <= 0)
  - [3, 4] -> 1 + 3 = 4     (Choose, add 4 to total)
  - [1, 4] -> 1-2+1+3 = 3   (Choose, add 3 to total)
  Result = 4 + 3 = 7.
- Time Complexity: O(m * n) - For each of the `m` queries, we might iterate up to `n` elements.
- Space Complexity: O(n) - To store the `n` flowers.
- Why better than previous method: N/A (Base approach)
- When to use: When constraints are very small (e.g., n, m <= 100), this is perfectly fine.

--------------------------------------------------------------------------------------
Method 2: Optimal Approach (Prefix Sums)

- Intuition: 
  Calculating the sum of a subarray iteratively takes O(n) time in the worst case. We can 
  optimize this to O(1) time per query by precomputing a prefix sum array.
- Approach: 
  Create a `pref` array where `pref[i]` stores the sum of elements from index 1 to `i`. 
  The sum of any subarray from `l` to `r` can be instantly found using `pref[r] - pref[l-1]`.
- Dry Run: 
  Array: [1, -2, 1, 3, -4] -> Prefix array: [0, 1, -1, 0, 3, -1]
  - Query [3, 4] -> pref[4] - pref[2] = 3 - (-1) = 4
  - Query [1, 4] -> pref[4] - pref[0] = 3 - 0 = 3
  Total Max Happiness = 4 + 3 = 7.
- Time Complexity: O(n + m) - O(n) to build the prefix array, O(1) for each of the `m` queries.
- Space Complexity: O(n) - For storing the prefix sum array.
- Why better than previous method: Reduces query time from O(n) to O(1). 
- When to use: When `m` and `n` are large (e.g., 10^5), this method is strictly required to avoid TLE.

--------------------------------------------------------------------------------------
Comparison Table:
Method         | TC         | SC     | Best Use Case
---------------|------------|--------|-----------------------------------------------
Brute Force    | O(m * n)   | O(n)   | Small constraints, quick to code.
Prefix Sums    | O(n + m)   | O(n)   | Optimal for large arrays and heavy query loads.

Final Recommended Solution: Method 2 (Prefix Sums) - Cleaner, faster, and standard CP practice.
*/

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

// Fast I/O
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;

    // 1-based indexing for ease of prefix sum calculation
    vector<int> a(n + 1);
    vector<int> pref(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i]; // Build prefix sum array
    }

    long long max_happiness = 0;

    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        
        // Calculate sum of subarray in O(1)
        long long current_subarray_sum = pref[r] - pref[l - 1];
        
        // Greedily pick the subarray if it yields positive happiness
        if (current_subarray_sum > 0) {
            max_happiness += current_subarray_sum;
        }
    }

    cout << max_happiness << "\n";
}

int main() {
    fast_io();
    
    // Codeforces standard single test case for this specific problem
    // (If the problem had 't' testcases, we would wrap `solve()` in a while(t--) loop)
    solve();
    
    return 0;
}
