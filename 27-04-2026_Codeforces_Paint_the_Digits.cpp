/*
Date: 27-04-2026
Problem Name: 1209C - Paint the Digits
Platform: Codeforces
Difficulty: Medium (Div. 2 C)
Tags: Greedy, Sorting, Strings, Implementation

Problem Summary:
You are given a sequence of `n` digits. You need to color each digit with either color 1 or color 2. 
If you concatenate all digits painted with color 1, followed by all digits painted with color 2, 
the resulting sequence must be sorted in non-decreasing order. If a valid coloring exists, output 
a string of '1's and '2's representing the colors. Otherwise, output "-".

Methods to Solve:
1. Brute Force (Backtracking)
2. Optimal Approach (Greedy with a Pivot Digit)

-------------------------------------------------------------------------------
Method 1: Brute Force (Backtracking)
-------------------------------------------------------------------------------
Intuition:
Every digit can either be colored 1 or 2. We can try all possible 2^N combinations using 
recursion, and for each valid assignment, check if the concatenated sequence is sorted.

Approach:
- Recursively assign color '1' or '2' to the current character.
- Once all characters are assigned, build the `temp` string (color 1s + color 2s).
- Check if `temp` is sorted.

Time Complexity: O(2^N * N)
Space Complexity: O(N) for recursion stack.
Why better than previous method: N/A (Baseline).
When to use: Only when N <= 20. Will give Time Limit Exceeded (TLE) here since N is up to 2 * 10^5.

-------------------------------------------------------------------------------
Method 2: Optimal Approach (Greedy with a Pivot Digit)
-------------------------------------------------------------------------------
Intuition:
Instead of trying all color combinations, we can guess the "pivot" digit `d` (from 0 to 9) 
that separates color 1 and color 2. 
- All digits strictly less than `d` MUST be color 1.
- All digits strictly greater than `d` MUST be color 2.
- Digits exactly equal to `d` can be either color 1 or color 2. 
To maintain the sorted property, if we assign `d` to color 1, it must appear *after* all 
digits less than `d`. Otherwise, it goes to color 2.

Approach:
- Loop `d` from 0 to 9.
- For a fixed `d`, construct the answer string `res` initialized with '0'.
- First pass: If `s[i] < d`, assign `res[i] = '1'` and track `last_1_idx` (the rightmost position of color 1).
- Second pass:
  - If `s[i] == d`: we can assign it to '1' ONLY if its index `i > last_1_idx`. If we do, update `last_1_idx = i`. Else, it goes to '2'.
  - If `s[i] > d`: assign `res[i] = '2'`.
- Form the concatenated string (all '1's then all '2's) and check if it is fully sorted.
- If it is sorted, print `res` and return.
- If no `d` from 0 to 9 works, print "-".

Dry Run (small example):
s = "040425"
Try d = 4:
- Elements < 4: '0' at idx 0, '0' at idx 2, '2' at idx 4. Colored '1'. (last_1_idx = 4)
- Elements == 4: '4' at idx 1, '4' at idx 3.
  - For idx 1: 1 > 4 is False. Colored '2'.
  - For idx 3: 3 > 4 is False. Colored '2'.
- Elements > 4: '5' at idx 5. Colored '2'.
- Colors string `res`: 121212
- Verifying string: '1's -> "002", '2's -> "445". Concatenated -> "002445". Sorted!
- Return "121212".

Time Complexity: O(10 * N) -> O(N) where N is the length of the string. We iterate over 10 possible digits.
Space Complexity: O(N) to store the result string and the concatenated temporary string.
Why better than previous method: Reduces the search space from exponential O(2^N) to linear time, easily passing constraints.
When to use: When dealing with constrained subset divisions based on values (like digits 0-9).

Comparison Table:
Method | TC         | SC   | Best Use Case
-------------------------------------------------------------------------------
1      | O(2^N * N) | O(N) | Never for this problem constraint.
2      | O(N)       | O(N) | Optimal for Competitive Programming (N = 200,000).

Final Recommended Solution: Method 2 (Greedy with Pivot Digit)
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    // Try all possible pivot digits from 0 to 9
    for (int d = 0; d <= 9; ++d) {
        string res(n, '0');
        int last_1_idx = -1;
        
        // 1. Assign all digits strictly less than the pivot to color 1
        for (int i = 0; i < n; ++i) {
            if (s[i] - '0' < d) {
                res[i] = '1';
                last_1_idx = i;
            }
        }
        
        // 2. Assign digits equal to or greater than the pivot
        for (int i = 0; i < n; ++i) {
            if (s[i] - '0' == d) {
                // To keep color 1 sorted, this 'd' must come after all smaller digits
                if (i > last_1_idx) {
                    res[i] = '1';
                    last_1_idx = i;
                } else {
                    res[i] = '2';
                }
            } else if (s[i] - '0' > d) {
                res[i] = '2';
            }
        }
        
        // 3. Verify if the generated assignment is valid (sorted)
        string temp = "";
        for (int i = 0; i < n; ++i) if (res[i] == '1') temp += s[i];
        for (int i = 0; i < n; ++i) if (res[i] == '2') temp += s[i];
        
        bool is_sorted = true;
        for (int i = 1; i < n; ++i) {
            if (temp[i] < temp[i - 1]) {
                is_sorted = false;
                break;
            }
        }
        
        // If sorted, we found a valid coloring
        if (is_sorted) {
            cout << res << "\n";
            return;
        }
    }
    
    // If no pivot works, it's impossible
    cout << "-" << "\n";
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
