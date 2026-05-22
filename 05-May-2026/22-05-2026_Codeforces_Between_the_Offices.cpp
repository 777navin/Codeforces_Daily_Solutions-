/*
Date: 22-05-2026
Problem Name: Between the Offices (867A)
Platform: Codeforces
Difficulty: 800 (Easy)
Tags: Implementation, Strings

Problem Summary:
The problem asks whether a manager flies more times from Seattle ('S') to San Francisco ('F') 
than from San Francisco to Seattle over a given sequence of 'n' days. Transitions only occur 
between consecutive days where the location changes.

Methods to Solve:
1. Optimal Approach (Single Pass Transition Counting / First & Last Character Check)

For EACH method include:

- Intuition: 
  A flight from Seattle to San Francisco occurs when a day 'S' is immediately followed by 'F'. 
  Conversely, a flight from San Francisco to Seattle occurs when 'F' is followed by 'S'.
  Since the locations form a linear sequence of movements, the only way to have strictly more 
  'S' -> 'F' flights than 'F' -> 'S' flights is if the entire sequence starts at Seattle ('S') 
  and ends at San Francisco ('F'). Any intermediate flight pairs cancel each other out in terms of net count.
  
- Approach:
  Check if the first character of the string is 'S' and the last character is 'F'. If true, print "YES".
  Otherwise, print "NO".

- Dry Run (small example):
  Input: 4 -> S S F F
  First character: 'S', Last character: 'F'. Result: YES.
  
  Input: 4 -> F S S F
  First character: 'F', Last character: 'F'. Result: NO.

- Time Complexity: O(1) if indexing directly, or O(n) to read the string.
- Space Complexity: O(n) to store the input string.
- Why better than previous method: It simplifies the problem to a boundary condition instead of tracking state transitions.
- When to use: Always, as it provides the most optimized lookup.

Comparison Table:
Method | TC | SC | Best Use Case
Optimal Approach | O(n) | O(n) | Standard competitive programming solution.

Final Recommended Solution:
Checking if the first day is 'S' and the last day is 'F'.
*/

#include <iostream>
#include <string>

using namespace std;

// Fast I/O
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    // If the sequence starts in Seattle and ends in San Francisco,
    // there must be more SF flights than FS flights.
    if (s.front() == 'S' && s.back() == 'F') {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    fast_io();
    // Single test case configuration as per problem statement
    solve();
    return 0;
}
