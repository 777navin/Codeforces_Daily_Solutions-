/*
=========================================================
Date        : 06-08-2026
Problem Name: New Bus Route (792A)
Platform    : Codeforces
Difficulty  : 1100
Tags        : sortings, math

Problem Summary:
Given 'n' distinct coordinates of cities, find the minimum 
absolute difference between any two cities. Also, find the 
total number of pairs that have this minimum distance.

Key Observation:
In a sorted array, the minimum absolute difference between 
any two elements will always be between two adjacent elements.
=========================================================

=========================================================
APPROACH EXPLANATION
=========================================================

1. Brute Force
• Intuition: Check the distance between every possible pair of cities.
• Approach: Use two nested loops to calculate the absolute difference for every pair (i, j). Keep track of the minimum and count how many times it occurs.
• Why it Works: It exhaustively searches all combinations.
• Time Complexity (TC): O(N^2) - Will give Time Limit Exceeded (TLE) for N = 200,000.
• Space Complexity (SC): O(1)

2. Optimal (Sorting)
• Intuition: The closest numbers will be next to each other if we order them.
• Approach: Sort the array. Iterate through adjacent elements to find the minimum difference, updating the count whenever a new minimum is found or incrementing if the same minimum is encountered again.
• Why it Works: Sorting brings the closest values adjacent to each other, mathematically guaranteeing the minimum difference is between some a[i] and a[i-1].
• Time Complexity (TC): O(N log N) - Dominated by the sorting step.
• Space Complexity (SC): O(1) auxiliary space (or O(N) depending on the sorting algorithm implementation).

=========================================================
FINAL APPROACH
=========================================================
Chosen Approach: Optimal (Sorting)
Why this is chosen: The Brute Force approach will exceed the time limit due to O(N^2) complexity with N up to 200,000. Sorting reduces the time complexity to O(N log N), which comfortably passes within the 1-second limit. It is much better as it avoids redundant comparisons.
=========================================================
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return; // Read number of cities

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Sort the coordinates
    sort(a.begin(), a.end());

    int min_diff = 2e9 + 7; // Initialize to a large value (Max possible diff is 2*10^9)
    int count = 0;

    // Check adjacent elements
    for (int i = 1; i < n; ++i) {
        int diff = a[i] - a[i - 1];
        
        if (diff < min_diff) {
            min_diff = diff;
            count = 1; // Reset count for a new minimum
        } else if (diff == min_diff) {
            count++;   // Increment count for the current minimum
        }
    }

    // Output the minimum distance and the number of such pairs
    cout << min_diff << " " << count << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // The problem requires a single test case
    solve();

    return 0;
}
