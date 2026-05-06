/*
Date: 05-05-2026
Problem Name: Young Physicist
Platform: Codeforces
Difficulty: 1000
Tags: Math, Implementation

Problem Summary
Given 'n' force vectors (x, y, z) acting on a body at (0,0,0), determine if the body is in equilibrium. Equilibrium means the sum of all vectors is (0,0,0).

Methods to Solve:
1. Optimal Approach (Coordinate Summation)

- Intuition
For a body to be in equilibrium in 3D space, the net force along each axis (X, Y, and Z) must independently sum up to zero.

- Approach
1. Initialize three variables (sumX, sumY, sumZ) to 0.
2. Read the number of forces 'n'.
3. Loop 'n' times, reading the x, y, and z components of each force.
4. Add each component to its respective sum variable.
5. Finally, check if sumX, sumY, and sumZ are all exactly equal to 0. If yes, print "YES", otherwise print "NO".

- Dry Run (small example)
Input:
3
4 1 7
-2 4 -1
1 -5 -3

Execution:
Force 1: sumX=4, sumY=1, sumZ=7
Force 2: sumX=4-2=2, sumY=1+4=5, sumZ=7-1=6
Force 3: sumX=2+1=3, sumY=5-5=0, sumZ=6-3=3
Final Check: sumX(3) == 0? False.
Output: NO

- Time Complexity
O(n) - We iterate through the given 'n' vectors exactly once.

- Space Complexity
O(1) - We only use a few integer variables to store the running sums, requiring constant extra space.

- Why better than previous method
This is the standard, optimal, and straightforward approach. 

- When to use
Whenever you need to calculate the net resultant of multiple independent components.

Comparison Table:
Method | TC | SC | Best Use Case
Optimal Approach | O(n) | O(1) | Checking equilibrium of multiple 3D vectors.

Final Recommended Solution
Optimal Approach (Coordinate Summation)
*/

#include <iostream>

using namespace std;

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int sumX = 0, sumY = 0, sumZ = 0;
    int x, y, z;

    for (int i = 0; i < n; ++i) {
        cin >> x >> y >> z;
        sumX += x;
        sumY += y;
        sumZ += z;
    }

    if (sumX == 0 && sumY == 0 && sumZ == 0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}
