/*
    Problem: B. Ordinary Numbers
    Platform: Codeforces
    Date: 16-04-2026

    Approach:
    Ordinary numbers are numbers where all digits are same:
    1,2,3,...9,11,22,...99,111,...

    For each test case:
    - Generate all possible ordinary numbers up to 9 digits.
    - Count how many are <= n.

    Since only 9 digits * 9 starting digits = 81 numbers,
    brute force generation is very efficient.

    Time Complexity: O(81) per test case
    Space Complexity: O(81)
*/

#include <bits/stdc++.h>
using namespace std;

vector<long long> ordinary;

void generateNumbers() {
    for (int digit = 1; digit <= 9; digit++) {
        long long num = 0;
        for (int len = 1; len <= 9; len++) {
            num = num * 10 + digit;
            ordinary.push_back(num);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    generateNumbers();
    sort(ordinary.begin(), ordinary.end());

    int t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;

        int count = upper_bound(ordinary.begin(), ordinary.end(), n) - ordinary.begin();
        cout << count << '\n';
    }

    return 0;
}
