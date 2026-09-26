/*
=========================================================
Date        : 26-09-2026
Problem Name: Running for Gold
Platform    : Codeforces
Difficulty  : 1500
Tags        : Greedy, Implementation, Sorts

Problem Summary:
Given n athletes and their ranks in 5 past marathons, an athlete is superior to 
another if they ranked better in at least 3 out of 5 marathons. Find any athlete 
who is superior to all other athletes, or return -1 if no such athlete exists.

Key Observation:
Superiority is a tournament comparison (like finding a candidate winner). We can find a 
candidate winner in O(N) by keeping track of the current best athlete, and then verify 
in a second O(N) pass if this candidate beats all other athletes.
=========================================================
*/

#include <iostream>
#include <vector>

using namespace std;

// Function to check if athlete A is superior to athlete B
bool is_superior(const vector<int>& a, const vector<int>& b) {
    int count = 0;
    for (int j = 0; j < 5; ++j) {
        if (a[j] < b[j]) {
            count++;
        }
    }
    return count >= 3;
}

/*
=========================================================
APPROACH 1: Brute Force (Check All Pairs)
=========================================================
- Intuition:
  • Check every athlete against all other athletes to see if one is superior to everyone.

- Approach:
  • For each athlete i from 1 to n, compare them against every athlete j (1 to n, j != i).
  • If athlete i beats all other athletes, return i.

- Why it Works:
  • Directly tests the condition given in the problem for all possible pairs.

- Time Complexity (TC):
  • O(N^2) where N is the number of athletes. TLE since N <= 50,000.

- Space Complexity (SC):
  • O(N) to store ranks.
=========================================================
*/

/*
=========================================================
APPROACH 2: Candidate Selection + Verification (Optimized)
=========================================================
- Intuition:
  • If a gold medalist exists, they must be superior to every other candidate, 
    including the winner of a single-elimination scan.

- Approach:
  • Pass 1 (Candidate Elimination): Maintain a potential winner `best` (initially athlete 1). 
    Iterate through athletes 2 to n. If candidate `i` beats `best`, update `best = i`.
  • Pass 2 (Verification): Verify if `best` is actually superior to ALL other athletes 
    from 1 to n (excluding `best`).
  • If `best` satisfies the condition for all athletes, return `best` (1-indexed); else return -1.

- Why it Works:
  • If a true gold medalist exists, they can never be eliminated during Pass 1, 
    so `best` will end up as that gold medalist. The second pass guarantees correctness.

- Time Complexity (TC):
  • O(N) because we make two linear scans over the array.

- Space Complexity (SC):
  • O(N) to store the 5 marathon ranks for each athlete.
=========================================================
*/

/*
=========================================================
FINAL APPROACH CHOICE:
• Approach 2 (Candidate Selection + Verification) is chosen.
• It reduces the time complexity from O(N^2) to O(N), comfortably passing 
  within the 1.0-second time limit for N = 50,000.
=========================================================
*/

void solve() {
    int n;
    cin >> n;
    
    vector<vector<int>> ranks(n, vector<int>(5));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 5; ++j) {
            cin >> ranks[i][j];
        }
    }
    
    // Pass 1: Find candidate
    int candidate = 0;
    for (int i = 1; i < n; ++i) {
        if (is_superior(ranks[i], ranks[candidate])) {
            candidate = i;
        }
    }
    
    // Pass 2: Verify candidate
    bool is_gold_medalist = true;
    for (int i = 0; i < n; ++i) {
        if (i != candidate && !is_superior(ranks[candidate], ranks[i])) {
            is_gold_medalist = false;
            break;
        }
    }
    
    if (is_gold_medalist) {
        cout << candidate + 1 << "\n";
    } else {
        cout << -1 << "\n";
    }
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
