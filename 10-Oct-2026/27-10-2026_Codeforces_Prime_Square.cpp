/*
=========================================================
Date        : 27-10-2026
Problem Name: Prime Square (Codeforces 1436B)
Platform    : Codeforces
Difficulty  : 900
Tags        : constructive algorithms, math, number theory

Problem Summary:
Construct a square matrix of size n x n consisting of non-negative integers not exceeding 10^5,
such that no number in the matrix is prime, and the sum of integers in each row and each column is a prime number.

Key Observation:
- We can use 1s and composite numbers (like 4) to control the sums.
- Placing 1s along the main diagonal and the anti-diagonal (or a shifted diagonal) allows us to easily make row and column sums prime without introducing primes into the matrix cells themselves (since 1 and 4 are not prime).
=========================================================
*/

/*
=========================================================
APPROACH EXPLANATION: Constructive Approach
=========================================================
• Intuition:
  - We need all matrix elements to be non-prime and $\le 10^5$.
  - We need every row and column sum to be a prime number.
  - The number 4 is composite (non-prime), and 1 is neither prime nor composite, but we can use 4s and 1s to form rows/columns with composite sums or prime sums.
• Approach:
  - Initialize an $n \times n$ matrix with zeros.
  - Place 1s on the main diagonal and the anti-diagonal (specifically at positions $(i, i)$ and $(i, n - i - 1)$ for $0 \le i < n$).
  - If $n$ is odd, the center element of the anti-diagonal might overlap or require careful adjustment so that each row/column sum is a predictable prime (e.g., adding 4s appropriately).
  - A simpler standard construction places 1s on the main diagonal and the adjacent diagonal (with wrap-around at the last column), and fills the remaining elements with 4s or 0s. Alternatively, setting matrix[i][i] = 1, matrix[i][(i + 1) % n] = 1, and filling the rest with zeros works if we adjust, but let's use the standard diagonal pattern where each row has exactly two 1s and the rest 4s (or similar composite values).
  - Let's use the simplest construction: 
    - Put 1 on the main diagonal: `matrix[i][i] = 1` and `matrix[i][(i + 1) % n] = 1`. Then each row/column sum is 2 (which is prime). Wait, 1 is not prime, but row/sum being 2 means we need two 1s per row/column. But are the elements themselves allowed to be 1? Yes, 1 is not a prime number!
    - Therefore, placing two 1s in each row and each column makes every row and column sum equal to 2 (a prime number), and 1 is not prime.
• Why it Works:
  - Every cell contains either 1 or 0. Neither 0 nor 1 is a prime number, satisfying the condition "there are no prime numbers in the square".
  - Each row and each column contains exactly two 1s, meaning every row and column sum is exactly 2, which is a prime number.
• Time Complexity (TC):
  - O(n^2) to fill and print the matrix for each test case.
• Space Complexity (SC):
  - O(n^2) to store the matrix.
=========================================================
*/

/*
=========================================================
FINAL APPROACH SELECTION:
- The two-diagonal 1s approach is chosen because it elegantly satisfies all constraints: cell values are 0 or 1 (none of which are prime), and every row/column sum is exactly 2 (a prime). It is optimal and extremely simple to implement.
=========================================================
*/

#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<vector<int>> a(n, vector<int>(n, 0));
    
    // Place 1s on the main diagonal and the next diagonal (with wrap-around)
    for (int i = 0; i < n; ++i) {
        a[i][i] = 1;
        a[i][(i + 1) % n] = 1;
    }
    
    // Print the matrix
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << a[i][j] << (j == n - 1 ? "" : " ");
        }
        cout << "\n";
    }
}

int main() {
    // Optimize standard I/O operations for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
