/*
=========================================================
Date        : 21-07-2026
Problem Name: Marin and Anti-coprime Permutation
Platform    : Codeforces
Difficulty  : 800 (Easy)
Tags        : Math, Number Theory, Combinatorics, Greedy

Problem Summary:
Count the number of permutations p of length n such that 
gcd(1*p1, 2*p2, ..., n*pn) > 1, modulo 998244353.

Key Observation:
If n is odd, the GCD can never be > 1, so the answer is 0.
If n is even, we can fix the GCD to 2 by placing even numbers at odd indices
and odd numbers at even indices, resulting in ((n/2)!)^2 permutations.
=========================================================
*/

#include <iostream>

using namespace std;

/*
• Intuition
  If n is odd, there are more odd numbers than even numbers in the permutation, 
  or vice-versa, making it impossible to ensure every product i * p[i] shares 
  a common factor greater than 1. When n is even, we can make the GCD equal to 2.

• Approach
  1. Check if n is odd. If so, output 0.
  2. If n is even, we place even numbers at odd indices and odd numbers at even indices.
  3. There are (n/2) even numbers and (n/2) odd numbers.
  4. The number of valid permutations is ((n / 2)!) * ((n / 2)!) modulo 998244353.

• Why it Works
  Every product i * p[i] becomes an even integer, ensuring gcd(1*p1, ..., n*pn) >= 2.

• Time Complexity (TC)
  O(n) per testcase to compute the factorials.

• Space Complexity (SC)
  O(1) auxiliary space.
*/

// =========================================================
// FINAL APPROACH
// =========================================================
// We directly implement the O(n) factorial calculation modulo 998244353.
// This approach is chosen because n <= 1000, allowing us to compute 
// ((n/2)!)^2 efficiently within the 1-second time limit without complex precomputation.
// =========================================================

const int MOD = 998244353;

void solve() {
    int n;
    cin >> n;

    if (n % 2 != 0) {
        cout << 0 << "\n";
        return;
    }

    long long half = n / 2;
    long long fact = 1;

    for (int i = 1; i <= half; ++i) {
        fact = (fact * i) % MOD;
    }

    long long ans = (fact * fact) % MOD;
    cout << ans << "\n";
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
