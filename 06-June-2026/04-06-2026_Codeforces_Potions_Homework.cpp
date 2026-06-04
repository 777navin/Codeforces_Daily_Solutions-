/*
Date: 04-06-2026
Problem Name: Potions Homework
Platform: Codeforces
Difficulty: 1200
Tags: Greedy, Sorting, Math

Problem Summary:
We are given n students and n tasks, where each student has a laziness level 
equal to the difficulty of the task assigned to them. We need to redistribute 
tasks among students (each student gets one task) to minimize the sum of 
(student_laziness * task_difficulty) modulo 10007.

Methods to Solve:
1. Optimal Approach: Rearrangement Inequality
   To minimize the sum of products of two sequences, we should pair the 
   smallest element of one sequence with the largest element of the other, 
   the second smallest with the second largest, and so on. 
   Since we are given the same set of values for both laziness and difficulty, 
   we sort one array in ascending order and the other in descending order.

Intuition:
The rearrangement inequality states that $\sum a_i b_{n-i+1} \le \sum a_i b_{\sigma(i)} \le \sum a_i b_i$.
By pairing the smallest laziness with the largest difficulty, we minimize the total time.

Approach:
1. Read the input array `a`.
2. Sort `a` in ascending order.
3. Create a copy or iterate such that we multiply `a[i]` with `a[n-1-i]`.
4. Sum these products modulo 10007.

Time Complexity: O(N log N) due to sorting.
Space Complexity: O(N) to store the inputs.

Comparison Table:
Method         | TC       | SC   | Best Use Case
---------------|----------|------|--------------
Greedy (Sort)  | O(N log N)| O(N) | Optimal for this problem

Final Recommended Solution:
Sort and apply the greedy pairing strategy.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Fast I/O setup for competitive programming
 */
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Sort to apply greedy strategy
    sort(a.begin(), a.end());

    long long min_total_time = 0;
    int MOD = 10007;

    // Pair smallest with largest: a[i] * a[n-1-i]
    for (int i = 0; i < n; ++i) {
        min_total_time = (min_total_time + (long long)a[i] * a[n - 1 - i]) % MOD;
    }

    cout << min_total_time << endl;
}

int main() {
    fast_io();
    
    // The problem implies a single test case based on input description
    solve();

    return 0;
}
