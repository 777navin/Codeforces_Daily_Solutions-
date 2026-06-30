/*
=========================================================
Date        : 30-06-2026
Problem Name: Data Recovery
Platform    : Codeforces
Difficulty  : 1200
Tags        : Implementation, Greedy, Constructive Algorithms

Problem Summary:
Company R2 is testing a processor. Total `n` tests run, but only `m`
temperatures were recorded. We know the expected minimum (`min`) and
maximum (`max`) temperatures. We need to determine if we can add
`n - m` missing temperatures such that the overall minimum is exactly
`min` and the overall maximum is exactly `max`.

Constraints:
1 <= m < n <= 100
1 <= min < max <= 100
1 <= t_i <= 100

Key Observation:
If any recorded temperature is strictly less than `min` or strictly
greater than `max`, it's immediately impossible. Otherwise, check if
`min` and `max` are already present. If not, each missing extreme
requires one of the `n - m` empty slots. If we have enough empty slots
for the required missing extremes, it is possible.
=========================================================

---------------------------------------------------------
Approach 1: Using Sorting (Better Approach)
---------------------------------------------------------
Intuition     : Store all recorded temperatures, sort them to easily find the min and max, and verify conditions.
Idea          : Sort the input array. The first element is the actual minimum, the last is the actual maximum.
Approach      : 
                1. Store all `m` elements in a vector and sort it.
                2. If vec[0] < min_val or vec[m-1] > max_val, return "Incorrect".
                3. Count missing required extremes: if vec[0] > min_val (need 1 slot), if vec[m-1] < max_val (need 1 slot).
                4. Check if m + needed_slots <= n.
Dry Run       : n = 3, m = 1, min = 1, max = 3, temps = [2]
                Sorted = [2]. actual_min = 2, actual_max = 2.
                2 > 1 (need min), 2 < 3 (need max). Total needed = 2 slots.
                m + needed = 1 + 2 = 3. Since 3 <= 3 (n), it's "Correct".
Why it works  : By sorting, we easily isolate the extremes and calculate how many target limits are missing.
Time Complexity: O(m log m) due to sorting.
Space Complexity: O(m) to store the elements.
Advantages    : Simple to understand and logically map out.
Disadvantages : Unnecessary sorting and memory allocation.
When to use   : When `m` is small and you need a quick brute-force verification.
Why next approach is better: We do not need to store all elements or sort them to find the min and max. We can determine bounds on the fly.

---------------------------------------------------------
Approach 2: Single Pass Greedy (Most Optimal)
---------------------------------------------------------
Intuition     : We only care about the absolute minimum and maximum of the recorded temperatures. We can track these dynamically.
Idea          : Read elements one by one from the input stream, updating `actual_min` and `actual_max` immediately.
Approach      :
                1. Initialize actual_min = INF, actual_max = -INF.
                2. Loop `m` times, read `t`, update actual_min = min(actual_min, t) and actual_max = max(actual_max, t).
                3. Check bounds: if actual_min < min_val or actual_max > max_val, print "Incorrect".
                4. Calculate missing: required = (actual_min > min_val ? 1 : 0) + (actual_max < max_val ? 1 : 0).
                5. Print "Correct" if m + required <= n else "Incorrect".
Dry Run       : n = 2, m = 1, min = 1, max = 3, temps = [2]
                Read 2: actual_min = 2, actual_max = 2.
                required = (2 > 1) + (2 < 3) = 1 + 1 = 2 slots needed.
                m + required = 1 + 2 = 3. Since 3 <= 2 is False, print "Incorrect".
Why it works  : Computes the same verification logic but avoids data structures entirely.
Time Complexity: O(m) because we process each element exactly once.
Space Complexity: O(1) because we only use a few integer variables.
Advantages    : Optimal time and space complexity.
Disadvantages : None.
When to use   : Highly recommended for this problem format.

---------------------------------------------------------
Comparison Table
---------------------------------------------------------
Method                  | Idea                                | Time       | Space | Difficulty | Recommended
------------------------|-------------------------------------|------------|-------|------------|------------
1. Using Sorting        | Sort elements to find extremes      | O(m log m) | O(m)  | Easy       | No
2. Single Pass Greedy   | Track min/max on the fly            | O(m)       | O(1)  | Easy       | Yes

---------------------------------------------------------
Final Recommended Approach
---------------------------------------------------------
The Single Pass Greedy approach (Method 2) is the best solution.
It completely avoids the overhead of dynamic memory allocation and 
sorting, processing the data stream in real-time O(m) and consuming 
constant O(1) space. This is highly efficient and aligns perfectly 
with Competitive Programming best practices.
=========================================================
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, min_val, max_val;
    cin >> n >> m >> min_val >> max_val;

    int actual_min = 105; // Constraint max is 100
    int actual_max = -1;

    for (int i = 0; i < m; ++i) {
        int t;
        cin >> t;
        actual_min = min(actual_min, t);
        actual_max = max(actual_max, t);
    }

    // If any recorded temperature strictly violates the allowed boundaries
    if (actual_min < min_val || actual_max > max_val) {
        cout << "Incorrect\n";
        return;
    }

    // Calculate how many necessary extreme values are missing
    int needed_slots = 0;
    if (actual_min > min_val) {
        needed_slots++;
    }
    if (actual_max < max_val) {
        needed_slots++;
    }

    // Check if we have enough empty steps (n - m) to inject the missing extremes
    if (m + needed_slots <= n) {
        cout << "Correct\n";
    } else {
        cout << "Incorrect\n";
    }
}

int main() {
    // Fast I/O for Competitive Programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Problem does not specify multiple test cases (t) per file,
    // so we execute the logic once.
    solve();

    return 0;
}
