/*
Date: 20-06-2026
Problem Name: Queue at the School
Platform: Codeforces
Difficulty: Easy (800)
Tags: Implementation, Strings, Simulation

Problem Summary:
Given a queue of 'n' children represented by a string of 'B' (boys) and 'G' (girls), 
and a time 't' in seconds. Every second, if a boy stands immediately in front of a 
girl (i.e., 'B' followed by 'G'), they swap positions. Find the arrangement of the 
queue after 't' seconds.

Methods to Solve:
1. Direct Simulation (Optimal)

For EACH method include:

- Intuition:
  The constraints are very small (n, t <= 50), which means we can directly simulate 
  the process second by second. In a single second, all swaps happen simultaneously. 
  If we see "BG", it becomes "GB". We just need to be careful not to move the same 
  boy multiple times within a single second.

- Approach:
  1. Read the integers `n` and `t`, and the string `s`.
  2. Create a loop that runs `t` times (once for each second).
  3. Inside the loop, iterate through the string from index `0` to `n - 2`.
  4. If `s[i] == 'B'` and `s[i+1] == 'G'`, swap them.
  5. Crucially, after a swap, increment `i` by an extra 1 (`i++`). This skips the 
     next position so the boy we just moved forward doesn't get moved again in the 
     same second.
  6. After the outer loop finishes, print the final string `s`.

- Dry Run (small example):
  Input: n = 5, t = 1, s = "BGGBG"
  t = 1:
    i = 0: s[0]=='B', s[1]=='G' -> Swap to "GBGBG". i becomes 1 (via extra increment).
    i = 2: s[2]=='B', s[3]=='G' -> Swap to "GBGGB". i becomes 3 (via extra increment).
    i = 4: loop terminates.
  Result: "GBGGB"

- Time Complexity: O(t * n). In the worst case, we do n comparisons t times. With max n=50 and t=50, 2500 operations easily pass the 2-second time limit.
- Space Complexity: O(1) auxiliary space, as we modify the string in-place.
- Why better than previous method: This is the standard, most straightforward optimal approach for the given constraints.
- When to use: When the problem models a real-world step-by-step state change with low limits.

Comparison Table:
Method             | TC      | SC      | Best Use Case
-------------------|---------|---------|-------------------------
Simulation         | O(t*n)  | O(1)    | Optimal for given constraints

Final Recommended Solution:
The direct simulation gracefully handles simultaneous state changes by skipping the evaluated index upon swapping.
*/

#include <iostream>
#include <string>
#include <algorithm>

class Solution {
public:
    void solve() {
        int n, t;
        if (!(std::cin >> n >> t)) return;
        
        std::string s;
        std::cin >> s;
        
        // Simulate for 't' seconds
        while (t--) {
            for (int i = 0; i < n - 1; ++i) {
                // If a boy is in front of a girl, they swap
                if (s[i] == 'B' && s[i + 1] == 'G') {
                    std::swap(s[i], s[i + 1]);
                    // Skip the next index to avoid moving the same boy twice in one second
                    i++;
                }
            }
        }
        
        std::cout << s << "\n";
    }
};

int main() {
    // Fast I/O for competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    Solution sol;
    sol.solve();
    
    return 0;
}

