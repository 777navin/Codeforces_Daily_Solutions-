# B. Minimize the Permutation

Solved Codeforces B. Minimize the Permutation using C++.

## Problem Statement

You are given a permutation of length `n`.

You can perform at most `n - 1` swap operations.

The `i-th` operation allows swapping elements at positions:

- `i`
- `i + 1`

Each operation can be used **at most once**.

Operations may be done in any order.

Return the lexicographically minimum permutation possible.

---

## Approach

### Key Idea

To make permutation lexicographically smallest:

- Bring smallest possible element to left side.
- But each adjacent swap index can be used only once.

So for each value from `1` to `n`:

1. Find current position of that value.
2. Move it left while:
   - previous element is larger
   - corresponding swap operation not used yet

This greedily minimizes earliest positions first.

---

## Why Efficient?

Lexicographical order depends on earliest changed position.

So moving smallest numbers left first gives optimal answer.

---

## Data Structures Used

- Array / vector
- Boolean array to mark used swap operations

---

## C++ Code

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    while (q--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        vector<int> pos(n + 1);

        for (int i = 0; i < n; i++)
            pos[a[i]] = i;

        vector<bool> used(n, false);

        for (int val = 1; val <= n; val++) {
            int idx = pos[val];

            while (idx > 0 && !used[idx] && a[idx - 1] > a[idx]) {
                used[idx] = true;

                swap(a[idx], a[idx - 1]);

                pos[a[idx]] = idx;
                pos[a[idx - 1]] = idx - 1;

                idx--;
            }
        }

        for (int x : a)
            cout << x << " ";

        cout << '\n';
    }

    return 0;
}
