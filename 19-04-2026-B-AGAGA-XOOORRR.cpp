#include <bits/stdc++.h>
using namespace std;

// Problem: B. AGAGA XOOORRR
// Date: 19-04-2026
// Language: C++

/*
=========================================================
Intuition
=========================================================

Operation:
Pick two adjacent elements and replace them with their XOR.

This means any sequence of operations can merge segments of
the array, where each final element represents XOR of one segment.

We need:
1. At least 2 elements remaining
2. All remaining elements equal

So we need to split array into >= 2 contiguous parts such that
XOR of every part is same.

---------------------------------------------------------
Key Observation
---------------------------------------------------------

Let totalXor = XOR of all elements.

If array can be divided into k equal XOR parts:

val ^ val ^ val ... (k times) = totalXor

If totalXor == 0:
Always possible if we can make at least 2 segments.

If totalXor != 0:
Need at least 3 segments having XOR = totalXor.

So:
1. If total XOR = 0 => YES
2. Else find at least two prefixes with XOR = totalXor
   before last position, then remaining segment also becomes totalXor

=========================================================
Approach
=========================================================

1. Compute total XOR.
2. If total XOR == 0 -> YES
3. Else count prefix XOR == totalXor
4. If count >= 2 before end -> YES
5. Else NO

=========================================================
Time Complexity
=========================================================
O(n) per test case

=========================================================
Space Complexity
=========================================================
O(1)
=========================================================
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        int totalXor = 0;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            totalXor ^= a[i];
        }

        // If total XOR is 0, always possible
        if (totalXor == 0) {
            cout << "YES\n";
            continue;
        }

        int prefXor = 0;
        int count = 0;

        // Need two cuts before last index
        for (int i = 0; i < n - 1; i++) {
            prefXor ^= a[i];

            if (prefXor == totalXor) {
                count++;
                prefXor = 0;
            }
        }

        if (count >= 2)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
