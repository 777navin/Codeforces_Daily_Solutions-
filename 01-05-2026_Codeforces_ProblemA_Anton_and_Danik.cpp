/*
Date: 01-05-2026
Problem Name: 734A - Anton and Danik
Platform: Codeforces
Difficulty: 800 (Easy/Entry Level)
Tags: Strings, Implementation, Competitive Programming

Problem Summary:
Anton and Danik played 'n' games of chess. We are given a string 's' of length 'n' 
where 'A' represents a win for Anton and 'D' represents a win for Danik. 
The task is to determine who won more games or if it was a friendship (tie).

Methods to Solve:
1. Single Pass Counting (Optimal)

-------------------------------------------------------------------------------
1. Method: Single Pass Counting
- Intuition: We only need the total counts of 'A' and 'D' to compare them.
- Approach: 
    - Read the integer 'n'.
    - Read the string 's'.
    - Iterate through the string once, incrementing a counter for Anton whenever 'A' 
      is found. The remaining games (n - anton_wins) belong to Danik.
    - Compare the two counts and print the corresponding result.
- Dry Run: n = 6, s = "ADAAAA"
    - Count 'A': 5
    - Count 'D': 1
    - 5 > 1 -> Output: "Anton"
- Time Complexity: O(n) - We traverse the string exactly once.
- Space Complexity: O(n) to store the string, or O(1) if reading character by character.
- Why better than previous: This is the most efficient approach possible for this problem.
- When to use: Always for frequency-based comparison problems.

-------------------------------------------------------------------------------
Comparison Table:
Method               | TC    | SC   | Best Use Case
---------------------|-------|------|-------------------------
Single Pass Counting | O(n)  | O(n) | Standard Competitive Programming

Final Recommended Solution: Single Pass Counting
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/**
 * Clean Competitive Programming Template
 * Optimized for Fast I/O
 */
void solve() {
    int n;
    if (!(cin >> n)) return;
    
    string s;
    cin >> s;
    
    int anton_wins = 0;
    int danik_wins = 0;
    
    // Counting wins for each player
    for (char c : s) {
        if (c == 'A') {
            anton_wins++;
        } else {
            danik_wins++;
        }
    }
    
    // Result determination based on comparison
    if (anton_wins > danik_wins) {
        cout << "Anton" << endl;
    } else if (danik_wins > anton_wins) {
        cout << "Danik" << endl;
    } else {
        cout << "Friendship" << endl;
    }
}

int main() {
    // Fast I/O setup for Competitive Programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // Standard problem structure: solve once
    solve();
    
    return 0;
}
