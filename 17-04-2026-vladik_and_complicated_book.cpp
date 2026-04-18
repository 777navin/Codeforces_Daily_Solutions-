/**
 * Date: 17-04-2026
 * Problem: B. Vladik and Complicated Book
 * Platform: Codeforces
 * Difficulty: 1100 (B)
 */

/*
    Intuition:
    The problem asks if the element at index 'x' remains the same after a subsegment 
    [l, r] is sorted. Since we reset the permutation after every query, each 
    sorting is independent.
    
    To find the position of p[x] in a sorted subsegment [l, r], we don't need to 
    actually sort it. We only need to count how many elements in the range [l, r] 
    are strictly smaller than p[x].
    
    Approach:
    1. For each query (l, r, x):
       - Let 'target' be the value at p[x].
       - Count how many elements 'p[i]' in the range l <= i <= r are less than 'target'.
       - Let this count be 'count_smaller'.
    2. In a sorted version of the subsegment [l, r], the value 'target' would 
       move to the position (l + count_smaller).
    3. If (l + count_smaller) is equal to the original index 'x', then the 
       page hasn't changed ("Yes"). Otherwise, it has changed ("No").

    Time Complexity (TC): O(m * n)
    Given n, m <= 10,000, m*n = 10^8. This might be tight for 2 seconds, 
    but since the operations inside the loop are very simple (comparisons), 
    it passes within the time limit.

    Space Complexity (SC): O(n) 
    To store the permutation.
*/

#include <iostream>
#include <vector>

using namespace std;

// --- Problem Logic Structure ---
class VladikBook {
public:
    void solve() {
        int n, m;
        if (!(cin >> n >> m)) return;

        vector<int> p(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> p[i];
        }

        while (m--) {
            int l, r, x;
            cin >> l >> r >> x;

            // If x is outside the sorted range, it won't change
            if (x < l || x > r) {
                cout << "Yes" << endl;
                continue;
            }

            int target = p[x];
            int count_smaller = 0;

            // Count how many elements in the subsegment are smaller than p[x]
            for (int i = l; i <= r; i++) {
                if (p[i] < target) {
                    count_smaller++;
                }
            }

            // The new position of target in sorted subsegment would be l + count_smaller
            if (l + count_smaller == x) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }
};

int main() {
    // Optimization for fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    VladikBook solver;
    solver.solve();

    return 0;
}
