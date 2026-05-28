/*
Date: 28-05-2026
Problem Name: 1070F - Debate
Platform: Codeforces
Difficulty: Medium (approx. 1500 Rating)
Tags: Greedy, Sorting

Problem Summary:
The main Berland TV channel wants to invite spectators to a political debate between Alice and Bob. 
Each potential spectator has an influence value and a political view represented by a 2-character string:
"00" (neither), "10" (Alice only), "01" (Bob only), or "11" (both).
We need to select a subset of people to maximize the total influence such that:
1. At least half of the selected spectators support Alice.
2. At least half of the selected spectators support Bob.

Methods to Solve:
1. Brute Force (Recursive Subset Generation)
2. Optimal Approach (Greedy & Sorting)

-------------------------------------------------------------------
Method 1: Brute Force 
- Intuition: Generate all possible subsets of the given spectators, check if the subset satisfies the 
  support conditions for Alice and Bob, and track the maximum influence found.
- Approach: Use recursion or bitmasking to iterate through all 2^N possible combinations.
- Dry Run: For N=6, we generate 64 subsets, filter valid ones, and find the max sum.
- Time Complexity: O(2^N * N) - Exponential time. Will result in Time Limit Exceeded (TLE) for N = 4 * 10^5.
- Space Complexity: O(N) for recursion stack.
- Why better than previous method: Baseline method.
- When to use: Only when N <= 20.

-------------------------------------------------------------------
Method 2: Optimal Approach (Greedy & Sorting)
- Intuition: 
  Spectators who support both ("11") are universally beneficial. They increase the total count of 
  Alice and Bob supporters simultaneously, giving us a "buffer" to include neutral or single-candidate 
  supporters. We should always take all "11" supporters.
  Next, we should pair up as many "10" and "01" supporters as possible, taking the highest influence 
  ones first. Each pair perfectly balances the support condition.
  Finally, any leftover "10", "01", and all "00" supporters can be taken using the buffer created 
  by the "11" supporters. Specifically, every "11" spectator allows us to take one arbitrary spectator.
  
- Approach:
  1. Segregate the influences into four arrays based on their view type.
  2. Sort all arrays in descending order.
  3. Greedily add all elements from the "11" array to our total influence.
  4. Pair elements from "10" and "01" up to min(size(10), size(01)) and add their sums.
  5. Pool the remaining unpaired elements from "10" or "01" together with all "00" elements into a `leftovers` array.
  6. Sort the `leftovers` array in descending order.
  7. Add the top elements from `leftovers`, up to a maximum count equal to the number of "11" supporters.

- Dry Run (Example 1):
  "11": [19, 29] -> Take all. Total = 48. Buffer = 2.
  "10": [22, 28] 
  "00": [18, 29]
  Pairing: No "01" to pair with "10". Pairs taken = 0.
  Leftovers: "10" remaining [28, 22], "00" remaining [29, 18]. Pool = [29, 28, 22, 18].
  Take top 2 from leftovers (buffer = 2): 29 + 28 = 57.
  Total Influence = 48 + 57 = 105. 

- Time Complexity: O(N log N) - Dominant operation is sorting the groups and leftovers.
- Space Complexity: O(N) - Storing elements in respective vectors.
- Why better than previous method: It runs well within the 3.0s time limit for N = 4 * 10^5.
- When to use: The standard optimal solution for this greedy pairing problem.

-------------------------------------------------------------------
Comparison Table:
Method         | TC         | SC   | Best Use Case
Brute Force    | O(2^N * N) | O(N) | N <= 20
Optimal Greedy | O(N log N) | O(N) | N <= 4 * 10^5 (Final Submission)

Final Recommended Solution: Method 2
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<long long> s11, s10, s01, s00;

    // 1. Segregate input based on views
    for (int i = 0; i < n; ++i) {
        string view;
        long long influence;
        cin >> view >> influence;
        
        if (view == "11") {
            s11.push_back(influence);
        } else if (view == "10") {
            s10.push_back(influence);
        } else if (view == "01") {
            s01.push_back(influence);
        } else if (view == "00") {
            s00.push_back(influence);
        }
    }

    // 2. Sort to process highest influence first
    sort(s11.rbegin(), s11.rend());
    sort(s10.rbegin(), s10.rend());
    sort(s01.rbegin(), s01.rend());

    long long total_influence = 0;

    // 3. Always take all "11"s
    for (long long val : s11) {
        total_influence += val;
    }

    // 4. Pair up "10"s and "01"s perfectly to balance votes
    int paired_count = min(s10.size(), s01.size());
    for (int i = 0; i < paired_count; ++i) {
        total_influence += s10[i] + s01[i];
    }

    // 5. Pool all remaining unselected spectators into a leftovers array
    vector<long long> leftovers;
    
    // Add remaining "10"s if any
    for (size_t i = paired_count; i < s10.size(); ++i) {
        leftovers.push_back(s10[i]);
    }
    // Add remaining "01"s if any
    for (size_t i = paired_count; i < s01.size(); ++i) {
        leftovers.push_back(s01[i]);
    }
    // Add all "00"s
    for (long long val : s00) {
        leftovers.push_back(val);
    }

    // 6. Sort leftovers descending to pick the best ones available
    sort(leftovers.rbegin(), leftovers.rend());

    // 7. We can take exactly s11.size() extra spectators without violating the >= 50% rule
    int extra_capacity = s11.size();
    for (int i = 0; i < min((int)leftovers.size(), extra_capacity); ++i) {
        total_influence += leftovers[i];
    }

    // Output final maximum influence
    cout << total_influence << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    
    return 0;
}
