/*
=========================================================
Date        : 17-10-2026
Problem Name: Factory
Platform    : Codeforces
Difficulty  : 1400
Tags        : math, implementation

Problem Summary:
- Given initial details 'a' and modulus 'm'.
- Each day, the factory produces 'a % m' more details.
- Check if the production will eventually stop (i.e., current details become divisible by m).

Key Observation:
- The sequence of details modulo m will repeat or hit 0. Since the state space is finite (m values), if 0 is not reached, it will cycle.
=========================================================
*/

/*
APPROACH EXPLANATION:

1. Simulation Approach
• Intuition: Simulate the process day by day while tracking visited modulo states to prevent infinite loops.
• Approach: In a loop, check if 'a % m == 0'. If yes, return true. Keep track of visited remainders using a boolean array or set. If a remainder repeats, we are in a cycle and will never hit 0, so return false. Update 'a = a + (a % m)'.
• Why it Works: Since 'm' is up to 10^5, the number of distinct remainders is at most 'm', ensuring fast termination.
• Time Complexity (TC): O(m)
• Space Complexity (SC): O(m)

2. Optimized Math / Cycle Detection (Final Choice)
• Intuition: Notice that a new value of 'a' becomes 'a + a % m'. Since 'a % m' is added to 'a', the new value is a multiple of the greatest common divisor (GCD) of the initial 'a' and 'm'.
• Approach: Repeatedly update 'a = (a + a % m) % m' or simply check if all prime factors of 'm' divide 'a' initially, or just simulate using standard properties. Alternatively, a simple loop with a modulo-based state tracking runs in at most 'm' steps, which easily fits within the 1-second time limit given m <= 10^5.
• Why it Works: Modulo arithmetic confines the state space, making direct simulation extremely efficient and simple.
• Time Complexity (TC): O(m)
• Space Complexity (SC): O(1)
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Optimize standard I/O operations for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, m;
    if (!(cin >> a >> m)) return 0;

    // Use a visited array to detect cycles since m <= 10^5
    vector<bool> visited(m, false);

    while (true) {
        long long rem = a % m;
        if (rem == 0) {
            cout << "Yes\n";
            return 0;
        }
        if (visited[rem]) {
            cout << "No\n";
            return 0;
        }
        visited[rem] = true;
        a += rem;
    }

    return 0;
}
