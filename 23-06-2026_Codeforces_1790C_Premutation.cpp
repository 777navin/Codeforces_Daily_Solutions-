/*
Date: 23-06-2026
Problem Name: C. Premutation
Platform: Codeforces
Difficulty: 1000
Tags: Constructive Algorithms, Implementation, Sortings

Problem Summary:
Kristina had a permutation of length n. She wrote it n times, but each time she omitted one 
element. Given these n sequences of length n-1 in arbitrary order, reconstruct the original 
permutation p.

Methods to Solve:
1. Frequency Analysis (Optimal)

For Method 1 (Frequency Analysis):
- Intuition: Since each number in the original permutation appears n-1 times in the 
  total input (across all n sequences), and each sequence is missing exactly one element,
  we can observe the positions. For any column in the input matrix (size n x (n-1)), 
  one value will appear once while another (the correct one) appears n-1 times.
- Approach: Check the first column of the given n sequences. The number that appears 
  (n-1) times is the first element of the permutation. Identify the sequence that is 
  missing this element and use it to reconstruct the rest.
- Time Complexity: O(n^2) to read and process the input.
- Space Complexity: O(n^2) to store the sequences.

Comparison Table:
Method | TC | SC | Best Use Case
-------|----|----|--------------
Freq Analysis | O(n^2) | O(n^2) | Optimal for this constraint

Final Recommended Solution: Use Frequency Analysis as it is O(n^2) and robust.
*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n - 1));
    map<int, int> first_col_counts;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - 1; ++j) {
            cin >> a[i][j];
        }
        first_col_counts[a[i][0]]++;
    }

    int first_elem = -1;
    int outlier_row = -1;

    // Find the element that appears most frequently in the first column
    for (auto const& [val, count] : first_col_counts) {
        if (count == n - 1) {
            first_elem = val;
        }
    }

    // Find the row that doesn't start with the first_elem
    for (int i = 0; i < n; ++i) {
        if (a[i][0] != first_elem) {
            outlier_row = i;
            break;
        }
    }

    // Print the first element
    cout << first_elem << " ";
    // Print the rest of the permutation from the outlier row
    for (int j = 0; j < n - 1; ++j) {
        cout << a[outlier_row][j] << (j == n - 2 ? "" : " ");
    }
    cout << endl;
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
