/*
Date: 18-06-2026
Problem Name: Tram
Platform: Codeforces
Difficulty: Easy (800)
Tags: Implementation, Math

Problem Summary:
Given a tram with n stops, you are given the number of passengers exiting (a) 
and entering (b) at each stop. Calculate the minimum capacity the tram must 
have so that the number of passengers never exceeds this capacity at any time.

Methods to Solve:
1. Simulation / Running Maximum (Optimal)

For EACH method include:

- Intuition: 
  The problem naturally simulates the real-world movement of a tram. To find 
  the maximum capacity needed, we just track the current number of people in 
  the tram at every stop and keep a record of the highest number observed.

- Approach:
  1. Initialize `current_passengers` to 0 and `max_capacity` to 0.
  2. Loop through each of the n stops.
  3. At each stop, subtract the exiting passengers (`a`) from `current_passengers`.
  4. Add the entering passengers (`b`) to `current_passengers`.
  5. Update `max_capacity` using `std::max()`.
  6. Output the `max_capacity` after the loop finishes.

- Dry Run (small example):
  Input: n = 4
  Stop 1: 0 out, 3 in -> current = 0 - 0 + 3 = 3. max = 3
  Stop 2: 2 out, 5 in -> current = 3 - 2 + 5 = 6. max = 6
  Stop 3: 4 out, 2 in -> current = 6 - 4 + 2 = 4. max = 6
  Stop 4: 4 out, 0 in -> current = 4 - 4 + 0 = 0. max = 6
  Result: 6

- Time Complexity: O(N) where N is the number of stops. We visit each stop exactly once.
- Space Complexity: O(1) as we are only using a few integer variables.
- Why better than previous method: This is the single, most optimal approach. 
- When to use: Direct sequence processing where intermediate maximums are required.

Comparison Table:
Method             | TC    | SC    | Best Use Case
-------------------|-------|-------|-------------------------
Simulation         | O(N)  | O(1)  | Direct, highly optimal approach

Final Recommended Solution:
The running maximum simulation perfectly covers the constraints. Fast I/O is included 
as standard competitive programming practice.
*/

#include <iostream>
#include <algorithm>

class Solution {
public:
    void solve() {
        int n;
        std::cin >> n;
        
        int current_passengers = 0;
        int max_capacity = 0;
        
        for (int i = 0; i < n; ++i) {
            int a, b;
            std::cin >> a >> b;
            
            // People exit first, then people enter
            current_passengers -= a;
            current_passengers += b;
            
            // Record the peak capacity
            max_capacity = std::max(max_capacity, current_passengers);
        }
        
        std::cout << max_capacity << "\n";
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
