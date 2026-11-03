/*
=========================================================
Date        : 01-11-2026
Problem Name: MUH and Sticks
Platform    : Codeforces
Difficulty  : 1100
Tags        : Implementation, Sorting, Brute Force

Problem Summary:
We are given the lengths of 6 sticks. We need to determine if they can form a bear, an elephant, or neither (Alien).
- Four sticks of the same length are required for the animal's legs.
- The remaining two sticks represent the head and body.
- Bear: Head stick must be shorter than the body stick.
- Elephant: Head stick must be equal to the body stick.

Key Observation:
By sorting the 6 stick lengths, any set of 4 identical sticks (legs) will appear consecutively either at the start, middle, or end. Once the legs are identified, the relation between the remaining two sticks determines whether the animal is a Bear or an Elephant.
=========================================================
*/

/*
=========================================================
APPROACH EXPLANATION

1. Sorting and Frequency Check
   • Intuition: Since there are only 6 sticks, sorting the array makes it very easy to check if any 4 sticks have the exact same length.
   • Approach: Read the 6 integers, sort them in non-decreasing order, and check the three possible positions where 4 identical sticks could reside (`l[0] == l[3]`, `l[1] == l[4]`, or `l[2] == l[5]`).
   • Why it Works: If 4 identical sticks exist, they are guaranteed to occupy one of these three contiguous windows in a sorted array. The remaining two sticks can then be directly compared to check the head and body conditions.
   • Time Complexity (TC): O(1) [Sorting 6 elements takes constant time]
   • Space Complexity (SC): O(1) [Constant extra space]

FINAL APPROACH CHOICE:
The sorting approach is chosen because it is extremely concise, efficient for fixed-size inputs (N = 6), and avoids complex hash maps while correctly identifying legs and remaining parts.
=========================================================
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Optimize standard I/O operations for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> l(6);
    for (int i = 0; i < 6; i++) {
        cin >> l[i];
    }

    sort(l.begin(), l.end());

    // Check if 4 sticks have the same length (legs)
    if (l[0] == l[3]) {
        // Legs are l[0] to l[3], remaining are l[4] and l[5]
        if (l[4] == l[5]) {
            cout << "Elephant\n";
        } else {
            cout << "Bear\n";
        }
    } else if (l[1] == l[4]) {
        // Legs are l[1] to l[4], remaining are l[0] and l[5]
        if (l[0] == l[5]) {
            cout << "Elephant\n";
        } else {
            cout << "Bear\n";
        }
    } else if (l[2] == l[5]) {
        // Legs are l[2] to l[5], remaining are l[0] and l[1]
        if (l[0] == l[1]) {
            cout << "Elephant\n";
        } else {
            cout << "Bear\n";
        }
    } else {
        cout << "Alien\n";
    }

    return 0;
}
