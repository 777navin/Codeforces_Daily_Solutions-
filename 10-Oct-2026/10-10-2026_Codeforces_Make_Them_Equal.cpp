/*
=========================================================
Date        : 10-10-2026
Problem Name: [Make Them Equal](https://codeforces.com/problemset/problem/1154/B)
Platform    : Codeforces
Difficulty  : 1200
Tags        : Implementation, Sorting, Math

Problem Summary:
- Given an array of $n$ integers, we want to find the minimum non-negative integer $D$ such that adding $D$, subtracting $D$, or doing nothing to each element makes all elements equal.
- If impossible, output -1.

Key Observation:
- After collecting unique elements into a set, the number of distinct values dictates the answer: 1 unique value means $D = 0$, 2 unique values mean either the difference or half the difference, 3 unique values mean the difference between adjacent sorted elements must be equal, and more than 3 values is impossible.
=========================================================
*/

/*
=========================================================
APPROACH EXPLANATION
=========================================================

1. Greedy / Case Analysis using Set
   • Intuition: Store all unique elements in a set to analyze distinct values present in the array.
   • Approach: 
     - If the set size is 1, all elements are already equal, so $D = 0$.
     - If the set size is 2, let the elements be $a$ and $b$ ($a < b$). If $(b - a)$ is even, $D = (b - a) / 2$ (by adding $D$ to $a$ and subtracting $D$ from $b$, making both equal to $(a + b)/2$). If $(b - a)$ is odd, $D = b - a$ (by adding $D$ to $a$ to reach $b$).
     - If the set size is 3, let the sorted elements be $a, b, c$. If $c - b == b - a$, then $D = b - a$. Otherwise, it's impossible, so output -1.
     - If the set size is greater than 3, it's impossible to equalize with a single $D$, so output -1.
   • Why it Works: Covers all mathematical constraints for valid single-step transformations using a single non-negative difference $D$.
   • Time Complexity (TC): O(n log n) due to inserting elements into a set.
   • Space Complexity (SC): O(n) to store unique elements in the set.

=========================================================
FINAL APPROACH
=========================================================
- We use a `std::set` to remove duplicates and sort the unique elements automatically.
- This approach is optimal because $n \le 100$, making an O(n log n) set-based check extremely fast, clean, and easily scalable without complex state tracking.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    // Optimize standard input/output streams for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    set<int> s;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.insert(x);
    }

    // If there is only 1 unique value, no change is needed
    if (s.size() == 1) {
        cout << 0 << "\n";
    }
    // If there are 2 unique values
    else if (s.size() == 2) {
        int a = *s.begin();
        int b = *s.rbegin();
        // If the difference is even, we can meet in the middle
        if ((b - a) % 2 == 0) {
            cout << (b - a) / 2 << "\n";
        } else {
            // Otherwise, we add the full difference to the smaller element
            cout << b - a << "\n";
        }
    }
    // If there are 3 unique values
    else if (s.size() == 3) {
        auto it = s.begin();
        int a = *it;
        it++;
        int b = *it;
        it++;
        int c = *it;

        // The difference between adjacent sorted elements must be equal
        if (b - a == c - b) {
            cout << b - a << "\n";
        } else {
            cout << -1 << "\n";
        }
    }
    // If there are more than 3 unique values, it's impossible
    else {
        cout << -1 << "\n";
    }

    return 0;
}10-10-2026_Codeforces_Make_Them_Equal.cpp
