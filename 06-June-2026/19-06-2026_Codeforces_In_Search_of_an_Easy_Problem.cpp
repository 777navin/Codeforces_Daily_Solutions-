/*
Date: 19-06-2026
Problem Name: In Search of an Easy Problem
Platform: Codeforces
Difficulty: Easy (800)
Tags: Implementation

Problem Summary:
Given n responses where 0 means easy and 1 means hard, determine if the problem 
is easy for everyone. If even one person says it's hard (1), output "HARD". 
Otherwise, output "EASY".

Methods to Solve:
1. Array Storage & Search (Brute Force)
2. On-the-fly Stream Processing (Optimal)

For EACH method include:

- Intuition:
  We just need to check if there is any '1' in the input stream. As soon as we see 
  a '1', we know the problem is "HARD". If we check all inputs and find no '1', 
  the problem is "EASY".

- Approach (Optimal):
  1. Read the number of people `n`.
  2. Loop `n` times to read each person's response directly from the input stream.
  3. If any response is 1, update a boolean flag `is_hard` to true.
  4. After the loop, print "HARD" if the flag is true, else print "EASY".
  (We can also terminate early, but reading the full input is safer for stream integrity).

- Dry Run (small example):
  Input: 3 \n 0 0 1
  i = 0, val = 0 (Easy) -> is_hard = false
  i = 1, val = 0 (Easy) -> is_hard = false
  i = 2, val = 1 (Hard) -> is_hard = true
  Loop ends. is_hard is true -> Print "HARD"

- Time Complexity: O(N) where N is the number of people. We read the input stream exactly once.
- Space Complexity: O(1) as we process the inputs on the fly without storing them in an array or vector.
- Why better than previous method: Storing elements in an array and then searching requires O(N) auxiliary space. Processing on the fly reduces space to strict O(1).
- When to use: Simple conditional checks where past data points don't need to be remembered.

Comparison Table:
Method             | TC    | SC    | Best Use Case
-------------------|-------|-------|-------------------------
Array Search       | O(N)  | O(N)  | If data needs reuse later
On-the-fly Check   | O(N)  | O(1)  | Optimal, memory efficient

Final Recommended Solution:
The on-the-fly stream processing is optimal. As per Codeforces requirements, a full `main()` with fast I/O is provided.
*/

#include <iostream>

class Solution {
public:
    void solve() {
        int n;
        if (!(std::cin >> n)) return;
        
        bool is_hard = false;
        for (int i = 0; i < n; ++i) {
            int response;
            std::cin >> response;
            if (response == 1) {
                is_hard = true;
            }
        }
        
        if (is_hard) {
            std::cout << "HARD\n";
        } else {
            std::cout << "EASY\n";
        }
    }
};

int main() {
    // Fast I/O setup for competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    Solution sol;
    sol.solve();
    
    return 0;
}

