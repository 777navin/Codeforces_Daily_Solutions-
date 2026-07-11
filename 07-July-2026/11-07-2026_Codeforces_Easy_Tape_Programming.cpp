/*
=========================================================
Date        : 11-07-2026
Problem Name: B. Easy Tape Programming
Platform    : Codeforces
Difficulty  : 1500 (Medium)
Tags        : Implementation, Simulation

Problem Summary:
We are given a sequence consisting of '<', '>', and digits (0-9). 
For each query containing a range [l, r], we simulate an interpreter running 
on this subsegment. We need to count and output how many times each digit (0-9) 
is printed during execution.

Key Observation:
Since N and Q are very small (1 <= N, Q <= 100), we can directly simulate 
the execution process for each query individually without worrying about TLE.
=========================================================
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
APPROACH EXPLANATION
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
1. Simulation Approach
• Intuition:
  The problem boundaries are exceptionally small (N, Q <= 100). The execution process 
  modifies or erases elements, which naturally leads to simulating the exact state 
  transitions of the Instruction Pointer (CP) and Direction Pointer (DP).

• Approach:
  For each query, extract the substring from index l to r. Maintain the current 
  character pointer (CP) and direction pointer (DP). Follow the rules for digit printing, 
  value decrementing, erasure, and direction switching until CP falls out of bounds.

• Why it Works:
  Since the simulation is guaranteed to terminate and the string length reduces or 
  values decrease, the total steps per simulation are bounded and well within the limits.

• Time Complexity (TC): 
  O(Q * MAX_STEPS), where MAX_STEPS per query is bounded because digits reduce to 0 
  and get erased, and consecutive arrows erase each other. In worst case, it takes few thousand steps.
• Space Complexity (SC): 
  O(N) to store the modified string for each independent simulation query.
*/

/*
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
FINAL APPROACH
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
• Why this approach is chosen:
  Simulation is the only logical approach because the state updates are highly dynamic 
  and order-dependent. Given N, Q <= 100, a direct simulation runs instantly.
*/

void solve() {
    int n, q;
    if (!(cin >> n >> q)) return;
    
    string s;
    cin >> s;
    
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--; r--; // Convert to 0-indexed
        
        // Extract the target subsegment for independent execution
        string cur = s.substr(l, r - l + 1);
        vector<int> count(10, 0);
        
        int cp = 0;
        int dp = 1; // 1 for Right, -1 for Left
        
        while (cp >= 0 && cp < (int)cur.length()) {
            if (cur[cp] >= '0' && cur[cp] <= '9') {
                int digit = cur[cp] - '0';
                count[digit]++;
                
                // Track where we are moving next
                int next_cp = cp + dp;
                
                if (digit == 0) {
                    cur.erase(cur.begin() + cp);
                    // Adjust CP if the character was erased before the pointer's new direction
                    if (dp == -1) {
                        cp--;
                    }
                } else {
                    cur[cp]--;
                    cp = next_cp;
                }
            } else {
                // The current character is '<' or '>'
                if (cur[cp] == '<') {
                    dp = -1;
                } else {
                    dp = 1;
                }
                
                int next_cp = cp + dp;
                
                // Check if the new character is also a direction character
                if (next_cp >= 0 && next_cp < (int)cur.length() && (cur[next_cp] == '<' || cur[next_cp] == '>')) {
                    int prev_cp = cp;
                    cp = next_cp;
                    cur.erase(cur.begin() + prev_cp);
                    // If we erased an element behind our movement direction, adjust the pointer index
                    if (prev_cp < cp) {
                        cp--;
                    }
                } else {
                    cp = next_cp;
                }
            }
        }
        
        // Print the frequencies of digits 0 through 9
        for (int i = 0; i < 10; ++i) {
            cout << count[i] << (i == 9 ? "" : " ");
        }
        cout << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    
    return 0;
}
