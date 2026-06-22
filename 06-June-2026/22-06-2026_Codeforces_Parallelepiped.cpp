/**
 * Date: 22-06-2026
 * Problem Name: 224A - Parallelepiped
 * Platform: Codeforces
 * Difficulty: 1100
 * Tags: Math, Geometry
 * * Problem Summary:
 * You are given three integers representing the areas of three mutually adjacent 
 * faces of a rectangular parallelepiped (a 3D box). You need to calculate the sum 
 * of the lengths of all 12 edges of this parallelepiped.
 * * Let the dimensions of the parallelepiped be x, y, and z.
 * The areas given are:
 * A1 = x * y
 * A2 = y * z
 * A3 = x * z
 * We need to find 4 * (x + y + z).
 * * Methods to Solve:
 * 1. Brute Force (Factorization)
 * 2. Optimal Approach (Mathematical Derivation)
 * * ==============================================================================
 * Method 1: Brute Force
 * ==============================================================================
 * Intuition: 
 * Since the areas are small (up to 10^4), the dimensions x, y, z must also be small.
 * We can guess one of the dimensions by iterating through all possible values.
 * * Approach:
 * Loop a variable `x` from 1 up to A1. 
 * If `x` divides A1 and `x` divides A3, we can derive `y = A1 / x` and `z = A3 / x`.
 * Then we check if our derived `y` and `z` multiply to give A2 (y * z == A2).
 * If they do, we've found our dimensions.
 * * Dry Run:
 * A1=4, A2=6, A3=6
 * - x=1: y=4, z=6. y*z = 24 != 6.
 * - x=2: y=2, z=3. y*z = 6 == 6! Found dimensions: 2, 2, 3.
 * Ans = 4*(2+2+3) = 28.
 * * Time Complexity: O(min(A1, A3)) - We only loop up to one of the areas.
 * Space Complexity: O(1) - Only a few variables used.
 * Why better than previous method: N/A (Baseline)
 * When to use: When you don't know the mathematical formula and constraints are small.
 * * ==============================================================================
 * Method 2: Optimal Approach (Mathematical Derivation)
 * ==============================================================================
 * Intuition:
 * We can solve the system of equations algebraically to find the dimensions in O(1).
 * * Approach:
 * We know:
 * A1 = x * y
 * A2 = y * z
 * A3 = x * z
 * * If we multiply all three equations:
 * A1 * A2 * A3 = (x * y) * (y * z) * (x * z)
 * A1 * A2 * A3 = (x * y * z)^2
 * * Taking the square root of both sides gives us the volume:
 * Volume (V) = x * y * z = sqrt(A1 * A2 * A3)
 * * Now we can find each dimension by dividing the volume by the areas:
 * z = V / A1  (since V / (x * y) = z)
 * x = V / A2  (since V / (y * z) = x)
 * y = V / A3  (since V / (x * z) = y)
 * * Total edge sum = 4 * (x + y + z).
 * * Dry Run:
 * A1=4, A2=6, A3=6
 * V = sqrt(4 * 6 * 6) = sqrt(144) = 12
 * z = 12 / 4 = 3
 * x = 12 / 6 = 2
 * y = 12 / 6 = 2
 * Ans = 4 * (2 + 2 + 3) = 28.
 * * Time Complexity: O(1) - Only standard math operations.
 * Space Complexity: O(1) - Minimal memory used.
 * Why better than previous method: Solves the problem instantaneously regardless of area sizes.
 * When to use: Always preferred for this specific geometry problem.
 * * ==============================================================================
 * Comparison Table:
 * Method         | TC     | SC   | Best Use Case
 * ------------------------------------------------------------------------------
 * Brute Force    | O(A)   | O(1) | When math formula is forgotten and inputs are small.
 * Optimal (Math) | O(1)   | O(1) | Standard CP environments, handles any valid constraint.
 * * Final Recommended Solution: Method 2 (Optimal Approach)
 */

#include <iostream>
#include <cmath>

using namespace std;

// Function to solve individual test case
void solve() {
    long long a, b, c;
    cin >> a >> b >> c;
    
    // Calculate the volume V = sqrt(a * b * c)
    long long volume = round(sqrt(a * b * c));
    
    // Extract individual edge lengths
    long long edge1 = volume / a;
    long long edge2 = volume / b;
    long long edge3 = volume / c;
    
    // A parallelepiped has 12 edges, 4 of each dimension
    long long total_edge_length = 4 * (edge1 + edge2 + edge3);
    
    cout << total_edge_length << "\n";
}

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // Codeforces Problem 224A only provides a single test case per run
    solve();
    
    return 0;
}
