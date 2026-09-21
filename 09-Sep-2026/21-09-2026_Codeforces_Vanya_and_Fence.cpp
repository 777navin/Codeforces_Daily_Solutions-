/*
=========================================================
Date        : 21-09-2026
Problem Name: Vanya and Fence
Platform    : Codeforces
Difficulty  : 800
Tags        : Implementation

Problem Summary:
Given n friends and a fence of height h. The height of each friend is provided.
If a friend's height is greater than h, their width is 2, otherwise their width is 1.
Calculate the minimum possible valid width of the road for all friends to walk in a row.

Key Observation:
Since each friend's width is determined independently by their height relative to the fence, 
we can determine the total width with a simple linear pass over the input.
=========================================================
*/

/*
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
1. Optimal Approach: Linear Scan
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
• Intuition:
  We just need to verify each person's height individually against the fence height.
  
• Approach:
  Maintain a variable `totalWidth` starting at 0.
  Read the height of each person one by one.
  If the person's height > h, add 2 to `totalWidth`; otherwise, add 1.
  
• Why it Works:
  It strictly follows the problem's rules and processes each person exactly once, summing their required widths.
  
• Time Complexity (TC): O(n)
  We iterate through the n heights exactly once.
  
• Space Complexity (SC): O(1)
  We only use a few integer variables to store the state, so no extra space is needed.

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
FINAL APPROACH
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
• Why this approach is chosen:
  This is the most straightforward and mathematically optimal way to solve the problem.
  There is no need to store the array elements, optimizing the space to strictly O(1).
*/

#include <iostream>

using namespace std;

void solve() {
    int n, h;
    cin >> n >> h;
    
    int totalWidth = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (a > h) {
            totalWidth += 2;
        } else {
            totalWidth += 1;
        }
    }
    
    cout << totalWidth << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // The problem statement specifies a single test case per execution
    solve();
    
    return 0;
}
