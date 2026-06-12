/*
Date: 12-06-2026
Problem Name: E. Arranging The Sheep
Platform: Codeforces
Difficulty: 1400
Tags: Constructive Algorithms, Greedy, Math, Two Pointers

Problem Summary
You are given a string of length n consisting of '.' (empty space) and '*' (sheep). 
In one move, you can shift any sheep to an adjacent empty square. 
The goal is to move the sheep so that they all form a contiguous block, 
minimizing the total number of moves.

Methods to Solve:
1. Greedy (Median Approach)
- Intuition: To minimize the distance of all points to a single point, the median is optimal. 
  Here, we want all sheep to be contiguous. If we consider the indices of all sheep, 
  let these indices be a_0, a_1, ..., a_{k-1}. If we align them to a target position, 
  the cost is minimized when the median sheep stays in its relative position, 
  and others pack around it.
- Approach: 
  1. Store all indices of sheep in a vector.
  2. If there are no sheep, the cost is 0.
  3. Find the median index (k/2).
  4. For every sheep at position `pos[i]`, its target position in the final contiguous 
     block will be `median_pos - (median_index - i)`.
  5. The moves required for a sheep at `pos[i]` to reach its target is 
     `abs(pos[i] - target_pos)`.
- Time Complexity: O(n) per test case.
- Space Complexity: O(k) where k is the number of sheep.

Comparison Table:
Method | TC | SC | Best Use Case
Greedy | O(n) | O(k) | Optimal for linear arrangements

Final Recommended Solution: Greedy (Median Approach)
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

/**
 * Function to solve a single test case.
 * We calculate the cost by aligning all sheep to the median's relative position.
 */
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<long long> sheep_indices;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '*') {
            sheep_indices.push_back(i);
        }
    }

    if (sheep_indices.empty()) {
        cout << 0 << "\n";
        return;
    }

    int k = sheep_indices.size();
    int median_idx = k / 2;
    long long median_pos = sheep_indices[median_idx];

    long long min_moves = 0;
    // For each sheep, calculate distance to its target position in the contiguous block
    for (int i = 0; i < k; ++i) {
        // Target position for the i-th sheep relative to the median sheep
        long long target_pos = median_pos - (median_idx - i);
        min_moves += abs(sheep_indices[i] - target_pos);
    }

    cout << min_moves << "\n";
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
