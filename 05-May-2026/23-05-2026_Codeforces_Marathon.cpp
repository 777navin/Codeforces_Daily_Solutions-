/*
Date: 23-05-2026
Problem Name: 1692A - Marathon
Platform: Codeforces
Difficulty: 800
Tags: implementation, math

Problem Summary:
Timur and three other people run a marathon. Given their respective distances 
(a for Timur, and b, c, d for the others), find out how many participants ran 
a strictly greater distance than Timur.

Methods to Solve:
1. Direct Comparison (Optimal Approach)

-------------------------------------------------------------------
Method 1: Direct Comparison
- Intuition: Since there are only 3 other participants, we can easily check 
  each person's distance against Timur's distance individually.
- Approach: 
  1. Read the four integers: a, b, c, d.
  2. Initialize a counter to 0. 
  3. Check if b > a, increment counter if true.
  4. Check if c > a, increment counter if true.
  5. Check if d > a, increment counter if true.
  6. Output the counter.
- Dry Run (small example):
  Input: 2 3 4 1
  a = 2, b = 3, c = 4, d = 1
  Is b (3) > a (2)? -> True, count = 1
  Is c (4) > a (2)? -> True, count = 2
  Is d (1) > a (2)? -> False, count = 2
  Output: 2
- Time Complexity: O(1) per test case.
- Space Complexity: O(1) auxiliary space.
- Why better than previous method: This is the most direct and optimal method 
  possible for a fixed input size of 4 variables.
- When to use: Always for this specific problem size.

Comparison Table:
Method             | TC   | SC   | Best Use Case
------------------------------------------------------
Direct Comparison  | O(1) | O(1) | Always optimal here

Final Recommended Solution:
The Direct Comparison approach is implemented below as it is perfectly suited 
for the constraints and provides the cleanest O(1) solution.
*/

#include <iostream>

using namespace std;

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    
    int count = 0;
    
    if (b > a) {
        count++;
    }
    if (c > a) {
        count++;
    }
    if (d > a) {
        count++;
    }
    
    cout << count << "\n";
}

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}
