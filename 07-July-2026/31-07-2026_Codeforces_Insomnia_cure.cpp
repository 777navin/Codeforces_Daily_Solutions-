/*
=========================================================
Date        : 31-07-2026
Problem Name: Insomnia cure (148A)
Platform    : Codeforces
Difficulty  : 800
Tags        : Implementation, Math

Problem Summary:
The princess counts a total of d dragons. Every k-th dragon gets punched with a frying pan,
every l-th dragon gets its tail shut in a door, every m-th dragon gets its paws trampled,
and every n-th dragon gets threatened. We need to find the total number of dragons that
suffered at least one type of damage.

Key Observation:
A dragon suffers damage if its 1-based index (from 1 to d) is divisible by k, l, m, or n.
=========================================================
*/

#include <iostream>
#include <numeric>

using namespace std;

/*
---------------------------------------------------------
APPROACH 1: Simulation / Direct Iteration (Brute Force)
---------------------------------------------------------
• Intuition:
  Iterate through each dragon from 1 to d and check if it suffers damage from any of the 4 conditions.

• Approach:
  Loop from i = 1 to d. If (i % k == 0 || i % l == 0 || i % m == 0 || i % n == 0), increment damage count.

• Why it Works:
  It directly tests the given condition for every individual dragon up to d.

• Time Complexity (TC):
  O(d) - We iterate through all d dragons once. Given d <= 10^5, this runs in under 1 ms.

• Space Complexity (SC):
  O(1) - Uses only constant auxiliary space.
---------------------------------------------------------
*/

/*
---------------------------------------------------------
APPROACH 2: Inclusion-Exclusion Principle (Mathematical)
---------------------------------------------------------
• Intuition:
  Count the multiples of each number and adjust for overlaps using set theory.

• Approach:
  Apply inclusion-exclusion on sets of multiples of k, l, m, n within range [1, d].

• Why it Works:
  Counts exact unique elements divisible by at least one of the numbers without iterating.

• Time Complexity (TC):
  O(1) - Simple arithmetic operations and LCM calculations.

• Space Complexity (SC):
  O(1) - Uses constant space.
---------------------------------------------------------
*/

/*
=========================================================
FINAL CHOICE EXPLANATION
=========================================================
Approach 1 (Direct Iteration) is chosen for its simplicity and readability.
Since d <= 10^5, an O(d) solution executes almost instantaneously (well within the 2.0-second time limit),
making the code cleaner and less error-prone than complex inclusion-exclusion arithmetic formulas.
=========================================================
*/

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k, l, m, n, d;
    if (!(cin >> k >> l >> m >> n >> d)) return 0;

    int damaged_dragons = 0;

    for (int i = 1; i <= d; ++i) {
        if (i % k == 0 || i % l == 0 || i % m == 0 || i % n == 0) {
            damaged_dragons++;
        }
    }

    cout << damaged_dragons << "\n";

    return 0;
}
