/*
=========================================================
Date        : 15-08-2026
Problem Name: 1392C - Omkar and Waterslide
Platform    : Codeforces
Difficulty  : Novice
Tags        : greedy, array

Problem Summary:
Given an array of integers, you can choose any non-decreasing subarray and increase all its elements by 1.
Find the minimum number of operations required to make the entire array non-decreasing.

Key Observation:
Whenever an element is strictly smaller than the previous element, we must perform operations to bridge that specific gap.
The total minimum operations needed is simply the sum of (a[i-1] - a[i]) for all valid adjacent drops.
=========================================================
*/

/*
1. Optimal Approach (Greedy)
• Intuition: Since we can only increase elements, any "drop" in the array (where a[i-1] > a[i]) is a deficit that must be covered by operations.
• Approach: Iterate through the array starting from the second element. If the current element is less than the previous one, add their difference to the total count of operations.
• Why it Works: By adding the exact difference between adjacent elements that are out of order, we optimally level the array from left to right. Overlapping operations are inherently combined.
• Time Complexity (TC): O(N), where N is the number of elements in the array, as we traverse it exactly once.
• Space Complexity (SC): O(1), since we only need a few variables to maintain the running total.

FINAL APPROACH
• This greedy strategy is chosen because it calculates the minimum required operations in strictly linear time.
• It is highly optimal compared to any simulation-based approach, avoiding the overhead of actually updating subarray elements.
• Space usage is kept to an absolute minimum O(1) requirement.
*/

#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long operations = 0;
    for (int i = 1; i < n; i++) {
        // If there is a drop, we need to cover the difference
        if (a[i - 1] > a[i]) {
            operations += (a[i - 1] - a[i]);
        }
    }

    cout << operations << "\n";
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
