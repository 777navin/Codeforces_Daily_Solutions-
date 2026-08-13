/*
=========================================================
Date        : 13-08-2026
Problem Name: A. The Party and Sweets
Platform    : Codeforces
Difficulty  : 1500
Tags        : greedy, math, sorting

Problem Summary:
Given n boys and m girls, each boy i gave at least b_i sweets to every girl,
and each girl j received at most g_j sweets from any boy. We need to find the
minimum total number of sweets given, or determine if it is impossible (-1).

Key Observation:
Each boy must give at least b_i sweets to all girls, establishing a base sum.
To minimize total sweets, assign higher g_j requirements to the boy with the maximum b_i value.
=========================================================
*/

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

/*
=========================================================
3. APPROACH EXPLANATION
=========================================================

1. Greedy Approach (Optimal)
---------------------------------------------------------
• Intuition:
  Start with the minimum baseline where each boy i gives b_i sweets to each girl.
  Then, increase sweets for specific girls to satisfy their maximum received requirement g_j.

• Approach:
  - If max(b) > min(g), output -1 as conditions contradict.
  - Calculate baseline sum = m * sum(b_i).
  - Sort b to easily access the largest and second-largest values.
  - Assign each girl's requirement g_j to the boy with max(b). Since that boy can give 
    strictly b_max sweets to at most (m - 1) girls (to keep his minimum equal to b_max),
    if all g_j > b_max, one girl must be satisfied by the second-largest boy.

• Why it Works:
  It minimizes additional sweets added above the mandatory baseline by leveraging the largest
  baseline values first without violating any boy's minimum constraint.

• Time Complexity (TC):
  O(n log n + m log m) due to sorting the input arrays.

• Space Complexity (SC):
  O(n + m) to store the arrays of boys and girls.
*/

/*
=========================================================
4. FINAL APPROACH
=========================================================
• Chosen Approach: Greedy with Sorting
• Why Chosen: It is optimal, intuitive, and handles all constraints within O((N+M) log(N+M)) time,
  well within the 1-second limit for N, M <= 100,000.
=========================================================
*/

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;

    vector<long long> b(n);
    long long sum_b = 0;
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        sum_b += b[i];
    }

    vector<long long> g(m);
    for (int i = 0; i < m; ++i) {
        cin >> g[i];
    }

    sort(b.begin(), b.end());
    sort(g.begin(), g.end());

    // If the largest minimum sweet count exceeds the smallest maximum sweet count, it's impossible.
    if (b.back() > g.front()) {
        cout << -1 << "\n";
        return;
    }

    long long total_sweets = sum_b * m;

    for (int j = 0; j < m; ++j) {
        total_sweets += (g[j] - b.back());
    }

    // If the largest boy cannot cover all m girls without breaking his minimum condition
    if (g.front() > b.back()) {
        total_sweets += (b.back() - b[n - 2]);
    }

    cout << total_sweets << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
