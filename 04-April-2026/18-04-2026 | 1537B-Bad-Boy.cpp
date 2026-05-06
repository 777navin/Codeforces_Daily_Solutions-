/**
 * Question Brief:
 * - Anton is at (i, j) in an n x m grid.
 * - We need to place two yo-yos in two cells (can be the same cell).
 * - Anton must start at (i, j), pick up both yo-yos, and return to (i, j).
 * - Goal: Maximize the total distance traveled (Manhattan distance).
 */

#include <iostream>

using namespace std;

void solve() {
    long long n, m, i, j;
    cin >> n >> m >> i >> j;

    /* Intuition:
       To maximize the distance Anton travels, we should make him go to the 
       extreme corners of the room. The two furthest possible points in any 
       grid are the opposite corners: (1, 1) and (n, m).
       
       By placing yo-yo 1 at (1, 1) and yo-yo 2 at (n, m), we ensure that 
       Anton has to cross the largest possible span of the grid.
    */
    
    cout << 1 << " " << 1 << " " << n << " " << m << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

/**
 * Intuition:
 * The total distance is |i - x1| + |j - y1| + |x1 - x2| + |y1 - y2| + |x2 - i| + |y2 - j|.
 * To maximize this, we simply pick the two most distant corners of the rectangle. 
 * Even if Anton is already near one corner, he will have to travel to the 
 * diagonal opposite corner and back, which is the maximum possible path.
 *
 * Time Complexity: O(1) per test case
 * - We just output the corners regardless of the input coordinates.
 *
 * Space Complexity: O(1)
 * - No extra space used.
 */
