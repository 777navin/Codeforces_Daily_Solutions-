/*
Date: 30-05-2026
Problem Name: Remove Two Letters (1800D)
Platform: Codeforces
Difficulty: 1200
Tags: data structures, greedy, hashing, strings

Problem Summary:
Given a string `s` of length `n`, you need to remove exactly two consecutive characters. 
The task is to find the total number of strictly distinct strings that can be formed after this operation.

Methods to Solve:
1. Brute Force (Using Set / Hashing)
2. Optimal Approach (Observation / Pattern Matching)

-------------------------------------------------------------------
Method 1: Brute Force
-------------------------------------------------------------------
- Intuition: 
  Generate all possible strings by removing every consecutive pair of characters and store them in a mathematical set. A set automatically handles uniqueness.
  
- Approach:
  1. Iterate `i` from `0` to `n-2`.
  2. For each `i`, construct a new string by concatenating `s[0...i-1]` and `s[i+2...n-1]`.
  3. Insert the newly formed string into a `std::unordered_set` or `std::set`.
  4. The answer is the size of the set.

- Dry Run (small example): 
  s = "aaabcc" (n = 6)
  i = 0 (remove s[0], s[1]): remaining = "abcc" -> Add to set
  i = 1 (remove s[1], s[2]): remaining = "abcc" -> Already in set
  i = 2 (remove s[2], s[3]): remaining = "aaac" -> Add to set
  ...
  Set size at the end = 4.

- Time Complexity: O(n^2) per testcase. String concatenation/substring takes O(n), and we do it O(n) times.
- Space Complexity: O(n^2) to store all the generated strings in the set.
- Why better than previous method: N/A (Baseline).
- When to use: Only when n is very small (e.g., n <= 100). Will cause Time Limit Exceeded (TLE) for n = 2*10^5.

-------------------------------------------------------------------
Method 2: Optimal Approach
-------------------------------------------------------------------
- Intuition:
  The maximum possible number of strings we can form is `n-1` (since there are `n-1` adjacent pairs).
  We only lose a distinct string when removing pair `(i, i+1)` results in the EXACT same string as removing pair `(i+1, i+2)`.
  When does this happen? 
  String 1: prefix + s[i+2] + suffix
  String 2: prefix + s[i] + suffix
  These are equal if and only if `s[i] == s[i+2]`.

- Approach:
  1. Initialize the maximum possible distinct strings: `ans = n - 1`.
  2. Iterate `i` from `0` to `n-3`.
  3. If `s[i] == s[i+2]`, it means removing `s[i], s[i+1]` yields the same result as removing `s[i+1], s[i+2]`.
  4. Decrement `ans` by 1 for every such match.
  5. Return `ans`.

- Dry Run (small example):
  s = "aaabcc", n = 6
  ans = 6 - 1 = 5
  i = 0: s[0]('a') == s[2]('a') -> Match! ans = 4
  i = 1: s[1]('a') == s[3]('b') -> No match
  i = 2: s[2]('a') == s[4]('c') -> No match
  i = 3: s[3]('b') == s[5]('c') -> No match
  Final ans = 4.

- Time Complexity: O(n). We traverse the string exactly once.
- Space Complexity: O(1) auxiliary space (O(n) to store the string).
- Why better than previous method: It avoids string creation, concatenation, and hashing entirely.
- When to use: Best for large strings up to 10^5 or 10^6 length. Mandatory for competitive programming limits.

-------------------------------------------------------------------
Comparison Table:
Method       | TC       | SC       | Best Use Case
-------------------------------------------------------------------
Brute Force  | O(n^2)   | O(n^2)   | Very small constraints (n <= 100)
Optimal      | O(n)     | O(1)     | Large constraints (n = 2*10^5) - Accepted Solution

Final Recommended Solution: Optimal Approach (Method 2)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Method 1: Brute Force (Provided for documentation, not used in main to avoid TLE)
    int solveBruteForce(int n, const string& s) {
        unordered_set<string> unique_strings;
        for (int i = 0; i < n - 1; i++) {
            string temp = s.substr(0, i) + s.substr(i + 2);
            unique_strings.insert(temp);
        }
        return unique_strings.size();
    }

    // Method 2: Optimal Approach
    int solveOptimal(int n, const string& s) {
        // Max possible combinations by removing two adjacent letters
        int distinct_count = n - 1;
        
        // Subtract overlaps
        for (int i = 0; i < n - 2; i++) {
            if (s[i] == s[i + 2]) {
                distinct_count--;
            }
        }
        
        return distinct_count;
    }
};

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    Solution obj;
    // Calling the optimal method
    cout << obj.solveOptimal(n, s) << "\n";
}

int main() {
    // Fast I/O for Competitive Programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
