/*
Date: 31-05-2026
Problem Name: Countdown
Platform: Codeforces
Difficulty: 800
Tags: Math, Greedy

Problem Summary:
Given a digital clock showing an n-digit number, you need to find the minimum number of operations to make the clock show 0. In one operation, you can either decrease the number on the clock by 1, or swap any two digits.

Methods to Solve:
1. Optimal Approach (Greedy)

For EACH method include:

- Intuition
  To minimize operations, we should always decrease digits when they are in the lowest possible place value (the units place). Moving a non-zero digit to the last position costs 1 swap operation. Once it is in the units place, reducing it to 0 costs exactly its integer value. The very last digit is already in the optimal position, so it does not require a swap operation.

- Approach
  Iterate through the string representation of the number from left to right. For every non-zero digit encountered, add its numeric value to the total operations count. If the digit is not located at the final index of the string, add an additional 1 to the operations count to account for the swap needed to move it to the units place.

- Dry Run (small example)
  Input: n = 3, s = "103"
  - '1' at index 0: non-zero, not last -> add 1 (value) + 1 (swap) = 2
  - '0' at index 1: zero -> ignore, add 0
  - '3' at index 2: non-zero, last -> add 3 (value)
  Total Operations = 5

- Time Complexity
  $\mathcal{O}(n)$ - We traverse the string of length $n$ exactly once per test case.

- Space Complexity
  $\mathcal{O}(1)$ - We only use a few variables for counting, besides the space required to store the input string. 

- Why better than previous method
  This is the mathematically optimal and only necessary approach, as simulating every possible sequence of decrements and swaps would be too slow and overly complex.

- When to use
  Always for this specific problem.

Comparison Table:
Method | TC | SC | Best Use Case
Optimal Greedy | $\mathcal{O}(n)$ | $\mathcal{O}(1)$ | Default optimal solution

Final Recommended Solution
The $\mathcal{O}(n)$ Greedy approach is the optimal and recommended way to solve this.
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

    long long min_operations = 0;
    
    for (int i = 0; i < n; ++i) {
        int digit = s[i] - '0';
        
        // If the digit is not zero, we need to process it
        if (digit > 0) {
            min_operations += digit; // Cost to decrement the value to 0
            
            // If it's not the last digit, we need 1 operation to swap it to the end
            if (i != n - 1) {
                min_operations += 1;
            }
        }
    }
    
    cout << min_operations << "\n";
}

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    
    // Handle multiple test cases
    while (t--) {
        solve();
    }

    return 0;
}
