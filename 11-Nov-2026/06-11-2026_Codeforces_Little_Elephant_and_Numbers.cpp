
/*
=========================================================
Date        : 06-11-2026
Problem Name: B. Little Elephant and Numbers
Platform    : Codeforces
Difficulty  : 1300
Tags        : Implementation, Number Theory

Problem Summary:
- Given a positive integer x.
- Count its positive divisors d such that d and x
  have at least one common digit in decimal representation.

Key Observation:
- We only need to check divisors up to sqrt(x).
- Every divisor i has a corresponding divisor x/i.
- A digit mask efficiently checks common digits.
=========================================================

APPROACH 1: BRUTE FORCE

- Intuition:
  Check every integer from 1 to x.

- Approach:
  Check whether each integer divides x and shares
  at least one digit with x.

- Why it Works:
  Every valid divisor is examined.

- Time Complexity: O(x * log10(x))
- Space Complexity: O(1)


APPROACH 2: OPTIMIZED (SQRT DECOMPOSITION)

- Intuition:
  Divisors occur in pairs: (i, x/i).

- Approach:
  1. Store all digits of x in a bitmask.
  2. Iterate i from 1 to sqrt(x).
  3. If i divides x, check both i and x/i.
  4. Count each valid divisor only once.

- Why it Works:
  Every divisor belongs to one of these pairs.
  The equality case i == x/i is handled separately.

- Time Complexity: O(sqrt(x) * log10(x))
- Space Complexity: O(1)


FINAL APPROACH:
- Use divisor enumeration with digit bitmasking.
- It avoids checking all integers up to x.
- Bitmask operations make digit matching efficient.
- This is optimal for the given constraint.
=========================================================
*/

#include <bits/stdc++.h>
using namespace std;

// Create a bitmask containing all digits of a number.
int getDigitMask(int num) {
    int mask = 0;

    while (num > 0) {
        int digit = num % 10;
        mask |= (1 << digit);
        num /= 10;
    }

    return mask;
}

// Check whether two numbers share at least one digit.
bool hasCommonDigit(int num, int digitMask) {
    while (num > 0) {
        int digit = num % 10;

        if (digitMask & (1 << digit)) {
            return true;
        }

        num /= 10;
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x;
    cin >> x;

    int digitMask = getDigitMask(x);
    int answer = 0;

    // Enumerate divisors in pairs.
    for (int i = 1; i <= x / i; i++) {

        if (x % i == 0) {

            // Check the smaller divisor.
            if (hasCommonDigit(i, digitMask)) {
                answer++;
            }

            // Check the corresponding larger divisor.
            int otherDivisor = x / i;

            // Avoid counting a perfect-square divisor twice.
            if (otherDivisor != i &&
                hasCommonDigit(otherDivisor, digitMask)) {
                answer++;
            }
        }
    }

    cout << answer << '\n';

    return 0;
}

/*
=========================================================
SAMPLE TEST CASES

Input:
1
Output:
1

Input:
10
Output:
2

Input:
12
Output:
4

=========================================================
*/
