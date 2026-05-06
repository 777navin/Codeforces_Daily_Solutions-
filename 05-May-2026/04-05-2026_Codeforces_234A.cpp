// 04-05-2026_Codeforces_234A.cpp

/*
Date: 04-05-2026
Problem Name: 234A - Lefthanders and Righthanders
Platform: Codeforces
Difficulty: 1200
Tags: Implementation, Greedy, Constructive Algorithms

Problem Summary:
A teacher wants to seat 'n' students (even number) at 'n/2' desks, two per desk.
There are two strict conditions:
1. Students whose numbers differ by exactly 1 cannot sit at the same desk.
2. A right-handed student on the left side of the desk and a left-handed student on the 
   right side will hit elbows. This specific configuration (Right, Left) must be avoided.

We are given the handedness of each student as a string of 'L's and 'R's. We need to 
output 'n/2' valid pairs of students.

Methods to Solve:
1. Constructive Index Pairing (Optimal)

For Method 1: Constructive Index Pairing
- Intuition: 
  To safely guarantee that no two seated students have adjacent roll numbers (difference of 1), 
  we can split the class into two halves and pair student `i` with student `i + n/2`. 
  Since `n >= 4` and is even, the difference between their roll numbers will be `n/2 >= 2`, 
  which flawlessly avoids the first condition.
  For the second condition, we just check the handedness. The only bad arrangement is 
  placing an 'R' on the left seat and an 'L' on the right seat. If our default pair 
  (i, i + n/2) results in this, we simply swap their seats.
  
- Approach:
  1. Read the number of students `n` and the string `s` representing their handedness.
  2. Loop from `i = 0` to `n/2 - 1`.
  3. Let `u = i` and `v = i + n/2`.
  4. If `s[u] == 'R'` and `s[v] == 'L'`, print `v + 1` then `u + 1` (swap to avoid elbows).
  5. Otherwise, print `u + 1` then `v + 1`.
  6. The problem specifies file I/O ("input.txt" and "output.txt"), so `freopen` is mandatory.

- Dry Run:
  Input: n = 6, s = "LLRLLL"
  Pairs are separated by distance n/2 = 3.
  - i = 0: Students 0 ('L') and 3 ('L'). Safe. Output: 1 4
  - i = 1: Students 1 ('L') and 4 ('L'). Safe. Output: 2 5
  - i = 2: Students 2 ('R') and 5 ('L'). Bad arrangement (R, L). Swap! Output: 6 3

- Time Complexity: O(N) 
  We iterate through half of the string exactly once, doing constant time operations.
  
- Space Complexity: O(1) 
  We only process the input string without using any extra auxiliary arrays.

Why better than previous method:
This is the only necessary approach and mathematically guarantees an answer in O(N) time.

When to use:
Ideal for constructive combination problems where fixed gaps help avoid adjacency constraints.

Comparison Table:
Method                       | TC   | SC   | Best Use Case
-------------------------------------------------------------------------
Constructive Index Pairing   | O(N) | O(1) | Guaranteed deterministic matching

Final Recommended Solution: Constructive Index Pairing
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    
    string s;
    cin >> s;

    // We pair student i with student i + n/2
    for (int i = 0; i < n / 2; ++i) {
        int left_student = i;
        int right_student = i + n / 2;

        // Condition to avoid: Right-handed on the left seat & Left-handed on the right seat.
        // If we hit this condition, we just swap their seats.
        if (s[left_student] == 'R' && s[right_student] == 'L') {
            cout << right_student + 1 << " " << left_student + 1 << "\n";
        } else {
            cout << left_student + 1 << " " << right_student + 1 << "\n";
        }
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Codeforces Problem 234A explicitly requires file I/O
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    solve();

    return 0;
}
