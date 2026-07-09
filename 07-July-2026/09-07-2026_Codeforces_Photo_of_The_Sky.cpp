/*
=========================================================
Date        : 09-07-2026
Problem Name: Photo of The Sky
Platform    : Codeforces
Difficulty  : 1500 (Estimated)
Tags        : Sorting, Greedy, Two Pointers

Problem Summary:
We are given 2*n coordinate values. We need to pair them up into n points (x, y) 
and then form a rectangle covering all these points such that the area is minimized.

Key Observation:
After sorting the 2*n coordinates, the optimal rectangle will always be formed by 
partitioning the sorted array into two halves of size n, or by taking a range 
of size n and using the remaining elements to fill the other dimension.
=========================================================
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
Approach:
1. Greedy with Sorting:
   - Sort the 2*n coordinates. Let the sorted array be A.
   - Any rectangle will have width (x_max - x_min) and height (y_max - y_min).
   - We can either:
     a) Split the sorted array into two halves: [0, n-1] and [n, 2n-1].
        Area = (A[n-1] - A[0]) * (A[2n-1] - A[n]).
     b) Take a window of size n starting at index i: [i, i+n-1].
        The remaining elements are [0, i-1] and [i+n, 2n-1].
        The width is fixed as (A[2n-1] - A[0]).
        The height is min(A[i+n-1] - A[i]) for all possible i.
   - We take the minimum of these options.

Time Complexity (TC): O(n log n) due to sorting.
Space Complexity (SC): O(n) to store the coordinates.
*/

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<long long> a(2 * n);
    for (int i = 0; i < 2 * n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    // Option 1: Split into two halves
    long long ans = (a[n - 1] - a[0]) * (a[2 * n - 1] - a[n]);

    // Option 2: Minimize height for a fixed width (A[2n-1] - A[0])
    for (int i = 0; i < n; ++i) {
        ans = min(ans, (a[2 * n - 1] - a[0]) * (a[i + n - 1] - a[i]));
    }

    cout << ans << endl;

    return 0;
}

/*
Final Approach Explanation:
This approach is chosen because sorting allows us to efficiently evaluate 
the two geometric constraints: either partitioning the set into two independent 
ranges or constraining one dimension by the full span of the input.
It is more efficient than brute force permutations (O(n!)) and fits within 
the 1-second time limit for n = 100,000.
*/

// 09-07-2026_Codeforces_Photo_of_The_Sky.cpp
