/*
Date: 11-05-2026
Problem Name: Search for Pretty Integers (870A)
Platform: Codeforces
Difficulty: 900
Tags: Implementation, Brute Force, Sortings

Problem Summary:
Given two lists of non-zero digits, find the smallest positive integer that 
contains at least one digit from the first list and at least one digit 
from the second list.

Methods to Solve:
1. Brute Force (Checking numbers 1-99)
2. Optimal Approach (Finding Min/Intersection)

-------------------------------------------------------------------------------
1. Brute Force
- Intuition: Since the digits are between 1-9, the smallest "pretty" integer 
  cannot exceed 99 (formed by the smallest digit of list A and list B).
- Approach: Iterate through integers from 1 upwards. For each integer, check 
  if its digits contain at least one element from both sets. The first such 
  number found is the answer.
- Dry Run: 
  List1: {4, 2}, List2: {5, 7, 6}
  Check 1..24 (No), Check 25: Has '2' (List1) and '5' (List2). Return 25.
- Time Complexity: O(1) - Constant range check (1 to 99).
- Space Complexity: O(1)
- Why better: Extremely simple to implement.
- When to use: When constraints are very small like this (digits 1-9).

-------------------------------------------------------------------------------
2. Optimal Approach
- Intuition: A pretty integer is either a single digit (if both lists share 
  a digit) or a two-digit number (if they don't).
- Approach: 
  a) Check for the smallest common digit in both lists. If found, that's the answer.
  b) If no common digit, find the minimum digit from List A (minA) and List B (minB).
  c) Form the smallest 2-digit number: min(minA*10 + minB, minB*10 + minA).
- Dry Run: 
  List1: {4, 2}, List2: {5, 7, 6}
  Common: None. minA=2, minB=5.
  Options: 25 or 52. Smallest is 25.
- Time Complexity: O(N + M) - One pass to find minimums and common elements.
- Space Complexity: O(1) - Using a frequency array or bitmask for digits 1-9.
- Why better: More scalable if the number of lists or range of digits increased.
- When to use: General case for list-based digit problems.

-------------------------------------------------------------------------------
Comparison Table:
Method         | TC       | SC     | Best Use Case
Brute Force    | O(1)     | O(1)   | Tiny constraints (digits 1-9).
Min/Intersect  | O(N + M) | O(1)   | Scalable, production-level efficiency.

Final Recommended Solution: Optimal Approach (Min/Intersection logic).
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

/**
 * Problem: A. Search for Pretty Integers
 * Platform: Codeforces
 */

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;

    vector<int> a(n), b(m);
    vector<int> freqA(10, 0), freqB(10, 0);

    int minA = 10, minB = 10;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        freqA[a[i]]++;
        minA = min(minA, a[i]);
    }

    for (int i = 0; i < m; ++i) {
        cin >> b[i];
        freqB[b[i]]++;
        minB = min(minB, b[i]);
    }

    // Step 1: Check for the smallest common digit (Single digit answer)
    for (int i = 1; i <= 9; ++i) {
        if (freqA[i] > 0 && freqB[i] > 0) {
            cout << i << endl;
            return;
        }
    }

    // Step 2: No common digit, form the smallest two-digit number
    if (minA < minB) {
        cout << minA << minB << endl;
    } else {
        cout << minB << minA << endl;
    }
}

int main() {
    // Fast I/O for Competitive Programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Problem 870A usually has a single test case per run
    solve();

    return 0;
}
