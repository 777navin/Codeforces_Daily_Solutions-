/*
Date: 08-06-2026
Problem Name: Long Comparison
Platform: Codeforces
Difficulty: 900
Tags: implementation, math, strings

Problem Summary:
Compare two numbers x1 and x2, where each is followed by p1 and p2 zeros respectively.
The numbers can be very large (up to 10^6 followed by 10^6 zeros), so direct 
integer comparison is not possible.

Methods to Solve:
1. Length-based comparison:
   - Calculate total digits for both numbers.
   - If total digits differ, the one with more digits is larger.
   - If total digits are equal, compare the prefix numbers (x1, x2) as strings or integers.

Intuition:
The magnitude of a number is primarily determined by its number of digits (logarithmic 
scale). If the number of digits is the same, then the lexicographical order of the 
significant digits (x1 vs x2) determines the magnitude.

Approach:
1. Calculate total length: L = log10(x) + 1 + p.
2. If L1 > L2, then num1 > num2.
3. If L1 < L2, then num1 < num2.
4. If L1 == L2, compare x1 and x2 directly. 
   - Note: If one has significantly more zeros, they will naturally have different lengths 
     unless x is adjusted. We align them by reducing p if possible to ensure accurate comparison.

Comparison Table:
Method         | TC    | SC   | Best Use Case
Length Compare | O(1)  | O(1) | Large numbers with exponents/zeros

Final Recommended Solution:
Directly compare the number of digits. If equal, compare the underlying integer values 
after normalizing the trailing zeros.
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

void solve() {
    long long x1, p1, x2, p2;
    cin >> x1 >> p1 >> x2 >> p2;

    string s1 = to_string(x1);
    string s2 = to_string(x2);

    // Total length = digits in x + count of zeros
    long long len1 = s1.length() + p1;
    long long len2 = s2.length() + p2;

    if (len1 > len2) {
        cout << ">" << endl;
    } else if (len1 < len2) {
        cout << "<" << endl;
    } else {
        // Same number of digits, compare values lexicographically
        if (s1.length() == s2.length()) {
            if (x1 > x2) cout << ">" << endl;
            else if (x1 < x2) cout << "<" << endl;
            else cout << "=" << endl;
        } else if (s1.length() < s2.length()) {
            // Need to append zeros to s1 to match length of s2
            while (s1.length() < s2.length() && p1 > 0) {
                s1 += '0';
                p1--;
            }
            if (s1 > s2) cout << ">" << endl;
            else if (s1 < s2) cout << "<" << endl;
            else cout << "=" << endl;
        } else {
            // Need to append zeros to s2 to match length of s1
            while (s2.length() < s1.length() && p2 > 0) {
                s2 += '0';
                p2--;
            }
            if (s1 > s2) cout << ">" << endl;
            else if (s1 < s2) cout << "<" << endl;
            else cout << "=" << endl;
        }
    }
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
