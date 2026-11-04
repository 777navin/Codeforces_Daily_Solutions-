/*
=========================================================
Date        : 04-11-2026
Problem Name: Team
Platform    : Codeforces
Difficulty  : 800
Tags        : greedy, brute force

Problem Summary:
Given n problems and for each problem the opinions of three friends (0 or 1), 
count how many problems the team will implement. They implement a problem 
if at least two friends are sure about the solution.

Key Observation:
For each problem, we can sum the three opinions. If the sum is greater than or 
equal to 2, the team will implement the solution.
=========================================================
*/

#include <bits/stdc++.h>
using namespace std;

/*
=========================================================
APPROACH EXPLANATION
=========================================================

1. Direct Counting
   • Intuition: Since we only need to check if at least two out of three friends 
     are sure about a problem, summing their binary opinions per problem directly gives us the count.
   • Approach: Read the number of problems n. Iterate through each of the n test cases, 
     read three integers representing each friend's view, and check if their sum >= 2. 
     Increment a counter whenever the condition is met.
   • Why it Works: A sum of 2 or 3 means at least two members agree on the solution, 
     which matches the team's rule.
   • Time Complexity: O(n)
   • Space Complexity: O(1)
=========================================================
*/

/*
=========================================================
FINAL APPROACH
=========================================================
We use a straightforward linear scan and counting approach with fast I/O. 
This is optimal in both time and space since we process each problem in O(1) 
time and use constant extra memory, easily passing within the 2-second time limit for n <= 1000.
=========================================================
*/

int main() {
    // Optimize standard I/O operations for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    int implementedCount = 0;
    for (int i = 0; i < n; ++i) {
        int petya, vasya, tonya;
        cin >> petya >> vasya >> tonya;
        
        // The team implements the problem if at least two friends are sure
        if (petya + vasya + tonya >= 2) {
            implementedCount++;
        }
    }

    cout << implementedCount << "\n";

    return 0;
}
