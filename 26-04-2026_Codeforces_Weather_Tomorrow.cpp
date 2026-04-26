/*
Date: 26-04-2026
Problem Name: M. Weather Tomorrow
Platform: Codeforces
Difficulty: 900 (Easy/Medium)
Tags: Implementation, Math

Problem Summary:
Vasya predicts the temperature for day (n+1) based on the temperatures of the last n days.
- If the n days form an Arithmetic Progression (AP), the temperature for day (n+1) 
  is the next term of that AP.
- If they do NOT form an AP, the temperature for day (n+1) is simply the same as 
  the temperature of day n.

Methods to Solve:
1. Difference Checking (Linear Scan):
   Calculate the common difference (d) between the first two terms and verify if 
   this difference remains constant across all consecutive terms.

---------------------------------------------------------------------------
Method 1: Linear Scan [Optimal Approach]

- Intuition:
  An Arithmetic Progression requires that A[i] - A[i-1] is the same for all i.
  If this condition is met, the next term is A[n-1] + d. Otherwise, it is A[n-1].

- Approach:
  1. Read n and the sequence of temperatures.
  2. If n < 2, it's technically an AP, but the problem constraints say n >= 2.
  3. Calculate the common difference: d = temp[1] - temp[0].
  4. Iterate from index 2 to n-1. If (temp[i] - temp[i-1] != d), the sequence is not an AP.
  5. If it's an AP, output temp[n-1] + d.
  6. Else, output temp[n-1].

- Dry Run:
  Input: 5, temps = [10, 20, 30, 40, 50]
  d = 20 - 10 = 10.
  Check 30-20=10 (OK), 40-30=10 (OK), 50-40=10 (OK).
  It's an AP. Output: 50 + 10 = 60.

  Input: 4, temps = [1, 2, 4, 8]
  d = 2 - 1 = 1.
  Check 4-2=2. 2 != 1. Not an AP.
  Output: 8.

- Time Complexity: O(N) - Single pass through the array.
- Space Complexity: O(N) - To store the temperatures (or O(1) if checked on the fly).
- Why better: It's the most direct and efficient way to solve the problem.

---------------------------------------------------------------------------
Comparison Table:
Method      | TC   | SC   | Best Use Case
Linear Scan | O(N) | O(N) | Standard arrays/vectors.
Streaming   | O(N) | O(1) | When memory is extremely limited.

Final Recommended Solution: Linear Scan
*/

#include <iostream>
#include <vector>

using namespace std;

/**
 * Competitive Programming Template for Codeforces
 * Fast I/O included for performance.
 */
void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<int> temp(n);
    for (int i = 0; i < n; ++i) {
        cin >> temp[i];
    }

    // Edge case: if only 2 days are given, they always form an AP
    if (n == 2) {
        int d = temp[1] - temp[0];
        cout << temp[1] + d << endl;
        return;
    }

    int diff = temp[1] - temp[0];
    bool is_ap = true;

    for (int i = 2; i < n; ++i) {
        if (temp[i] - temp[i - 1] != diff) {
            is_ap = false;
            break;
        }
    }

    if (is_ap) {
        cout << temp[n - 1] + diff << endl;
    } else {
        cout << temp[n - 1] << endl;
    }
}

int main() {
    // Fast I/O optimization
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
