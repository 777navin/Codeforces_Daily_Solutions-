/*
=========================================================
Date        : 03-07-2026
Problem Name: Interview (1807E)
Platform    : Codeforces
Difficulty  : 1300
Tags        : interactive, binary search

Problem Summary:
You are given `n` piles of stones. Each stone weighs 1 gram, 
except for one special stone in an unknown pile which weighs 
2 grams. You can query the total weight of a chosen subset 
of piles up to 30 times. You need to find the index of the 
pile containing the special stone.

Constraints:
- 1 <= t <= 1000 (Test cases)
- 1 <= n <= 2 * 10^5 (Number of piles)
- Sum of n over all test cases <= 2 * 10^5
- 1 <= a_i <= 10^4 (Stones in each pile)
- Maximum 30 queries per test case.

Key Observation:
Since we are given the exact number of stones in each pile 
initially, we know the exact expected weight of any subset 
of piles if they only contain 1-gram stones. By maintaining a 
prefix sum array, we can query a range of piles and compare 
the returned weight to the expected weight. If the weight is 
greater, the special stone is in that range. This monotonic 
property allows us to use Binary Search.
=========================================================
*/

/*
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
APPROACH 1: Linear Search (Brute Force)
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
• Intuition: Query the first pile. If it weighs more than a_1, the answer is 1. Else, query the second, and so on.
• Idea: Check each pile individually until the heavier one is found.
• Approach: Iterate `i` from 1 to `n`. Query pile `i`. Check if returned weight > `a_i`.
• Dry Run: For piles [1, 2, 3], query pile 1 -> weight 1. Query pile 2 -> weight 3 (but expected 2). Answer is 2.
• Why it works: Every pile is eventually checked.
• Time Complexity: O(N)
• Space Complexity: O(1)
• Advantages: Very simple to implement.
• Disadvantages: Fails the query limit. Takes up to N queries, but max allowed is 30.
• When to use: When N <= 30.
• Why next approach is better: Binary Search drastically reduces the number of queries to logarithmic time.

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
APPROACH 2: Binary Search (Most Optimal)
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
• Intuition: Since we have an upper bound of 30 queries for N = 200,000, log2(200,000) is approximately 18, which easily fits within the 30 queries limit.
• Idea: Divide the search space in half. Query the left half. If the weight is greater than expected, the special stone is in the left half. Otherwise, it's in the right half.
• Approach: 
  1. Precompute prefix sums of the array so we can find the expected weight of any range [L, mid] in O(1).
  2. Set L = 1, R = n.
  3. While L < R, calculate mid = L + (R - L) / 2.
  4. Query the range [L, mid].
  5. If returned weight > expected weight, set R = mid.
  6. Else, set L = mid + 1.
  7. Answer is L.
• Dry Run: Piles: [1, 2, 1]. Special stone at idx 2. L=1, R=3. mid=2. Query [1, 2]. Expected = 3. Actual = 4. 4 > 3, so R=2. Next L=1, R=2, mid=1. Query [1]. Expected = 1. Actual = 1. 1 == 1, so L=2. Loop ends. Ans=2.
• Why it works: The extra weight acts as a clear indicator of which half of the search space contains the target.
• Time Complexity: O(N + log N) per test case (O(N) for prefix sums, O(log N) for binary search).
• Space Complexity: O(N) for storing the array and prefix sums.
• Advantages: Optimal, guarantees finding the answer in <= 18 queries.
• Disadvantages: Requires careful handling of I/O flushing.
• When to use: Always for this specific problem.

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
COMPARISON TABLE
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
-------------------------------------------------------
Method          Idea            Time      Space   Difficulty   Recommended
-------------------------------------------------------
Brute Force     Check one by 1  O(N)      O(1)    Easy         No
Binary Search   Divide in half  O(log N)  O(N)    Medium       Yes
-------------------------------------------------------

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
FINAL RECOMMENDED APPROACH
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
Binary Search is the best and only valid solution because it guarantees locating the heavy pile in at most ceil(log2(200,000)) = 18 queries, comfortably beating the 30-query limit enforced by the interactive interactor. Using prefix sums allows O(1) expected weight verification.
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> a(n + 1);
    vector<long long> pref(n + 1, 0);
    
    // Read piles and compute prefix sums (1-based indexing)
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
    }
    
    int l = 1, r = n;
    int ans = 1;
    
    // Binary Search to locate the special stone
    while (l <= r) {
        if (l == r) {
            ans = l;
            break;
        }
        
        int mid = l + (r - l) / 2;
        int len = mid - l + 1;
        
        // Formulate the query for the range [l, mid]
        cout << "? " << len;
        for (int i = l; i <= mid; i++) {
            cout << " " << i;
        }
        cout << endl; // endl implicitly flushes the output stream
        
        long long weight;
        cin >> weight;
        
        // Calculate the expected weight if no special stone is present
        long long expected_weight = pref[mid] - pref[l - 1];
        
        // If the actual weight is strictly greater, the special stone is in [l, mid]
        if (weight > expected_weight) {
            r = mid;
        } else {
            // Otherwise, it must be in the remaining half [mid + 1, r]
            l = mid + 1;
        }
    }
    
    // Output the final answer
    cout << "! " << ans << endl;
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
