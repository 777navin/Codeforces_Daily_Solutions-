/*
Date: 02-06-2026
Problem Name: Complicated GCD (664A)
Platform: Codeforces
Difficulty: Easy
Tags: Math, Number Theory, Strings

Problem Summary:
Find the greatest common divisor (GCD) of all integers from 'a' to 'b' inclusive. 
The values of 'a' and 'b' can be extremely large (up to 10^100), meaning they cannot 
fit in standard integer data types and must be handled as strings.

Methods to Solve:
1. Brute Force (Theoretical)
2. Optimal Approach (Mathematical Property)

-------------------------------------------------------------------
Method 1: Brute Force (Theoretical - Will result in TLE)
- Intuition: Calculate the GCD of all numbers iteratively from 'a' to 'b'.
- Approach: Initialize `ans = a`. Loop from `a + 1` to `b` and do `ans = gcd(ans, current_number)`.
- Dry Run: a = 1, b = 2 -> gcd(1, 2) = 1.
- Time Complexity: O(b - a) -> Will cause Time Limit Exceeded (TLE) for differences up to 10^100.
- Space Complexity: O(1)
- Why better than previous method: N/A
- When to use: Never for this specific problem due to massive constraints.

-------------------------------------------------------------------
Method 2: Optimal Approach (Mathematical Property)
- Intuition: Two consecutive integers (like x and x+1) are always coprime, meaning their 
  GCD is always 1. If 'a' and 'b' are not the exact same number, the continuous range [a, b] 
  is guaranteed to contain at least one pair of consecutive integers. Therefore, the GCD 
  of the entire range drops immediately to 1. If 'a' is exactly equal to 'b', then the 
  range contains only one number, and the GCD of a single number is that number itself.
- Approach: Read 'a' and 'b' as `std::string` since they can be up to 10^100 (which exceeds 
  limits of `unsigned long long`). Compare the two strings. If they are identical, output 'a'. 
  Otherwise, output '1'.
- Dry Run:
    Example 1: a = "1", b = "2". 
               a != b -> Output: 1.
    Example 2: a = "618...", b = "618...". 
               a == b -> Output: 618...
- Time Complexity: O(|a|) where |a| is the length of the string (up to 100 characters for comparison).
- Space Complexity: O(|a|) to store the strings in memory.
- Why better than previous method: Executes in O(|a|) string comparison time instead of 
  iterating through up to 10^100 elements.
- When to use: Always for this problem.

Comparison Table:
Method           | TC             | SC     | Best Use Case
-----------------|----------------|--------|---------------------------
Brute Force      | O(b - a)       | O(1)   | Small bounds (not applicable here)
Optimal Approach | O(|a|)         | O(|a|) | Always, perfectly handles up to 10^100

Final Recommended Solution: Optimal Approach
*/

#include <iostream>
#include <string>

using namespace std;

// Fast I/O for competitive programming
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void solve() {
    string a, b;
    cin >> a >> b;

    // If the starting and ending points are exactly the same,
    // the GCD of a single number is the number itself.
    if (a == b) {
        cout << a << "\n";
    }
    // If a and b are different, the range [a, b] contains at least
    // two consecutive integers. The GCD of any two consecutive integers is 1.
    // Therefore, the GCD of the entire continuous range must be 1.
    else {
        cout << 1 << "\n";
    }
}

int main() {
    // Apply standard fast I/O optimizations
    fast_io();

    // Problem requires only a single test case
    int t = 1;
    // cin >> t; // Uncomment if multiple test cases were given in future variations

    while (t--) {
        solve();
    }

    return 0;
}
