/*
=========================================================
Date        : 03-11-2026
Problem Name: Books Queries
Platform    : Codeforces
Difficulty  : 1400
Tags        : data structures, implementation

Problem Summary:
We maintain a shelf of books where we can add books to the 
left or right ends. We need to answer queries calculating 
the minimum number of pops needed from either the left or 
right side to make a specific book the leftmost or rightmost.

Key Observation:
Since books are only added to the outer ends and never reordered or removed until queried, we can assign virtual coordinate indices to track each book's position dynamically.
=========================================================
*/

#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    if (!(cin >> q)) return 0;

    // Array to store the virtual position coordinate of each book ID.
    // Given q <= 2 * 10^5, coordinate range [0, 400005] is sufficient.
    int pos[200005];

    // Initialize pointers for left and right ends around a central offset.
    int left_ptr = 200002;
    int right_ptr = 200003;

    for (int i = 0; i < q; ++i) {
        char type;
        int id;
        cin >> type >> id;

        if (type == 'L') {
            /*
            Intuition:
            Adding to the left extends our shelf boundary on the left side.
            
            Approach:
            Assign the current left_ptr coordinate to the book and decrement left_ptr.
            
            Why it Works:
            Maintains the relative order and tracks exact coordinates for distance queries in constant time.
            
            Time Complexity (TC): O(1)
            Space Complexity (SC): O(MAX_ID)
            */
            pos[id] = left_ptr--;
        } else if (type == 'R') {
            /*
            Intuition:
            Adding to the right extends our shelf boundary on the right side.
            
            Approach:
            Assign the current right_ptr coordinate to the book and increment right_ptr.
            
            Why it Works:
            Maintains the relative order and tracks exact coordinates for distance queries in constant time.
            
            Time Complexity (TC): O(1)
            Space Complexity (SC): O(MAX_ID)
            */
            pos[id] = right_ptr++;
        } else {
            /*
            Intuition:
            To bring a target book to the extreme left or right, we determine 
            whether popping from the left or right side requires fewer operations.
            
            Approach:
            Calculate the distance from the book's position to the current left boundary 
            (left_ptr + 1) and right boundary (right_ptr - 1), and output the minimum.
            
            Why it Works:
            The number of pops needed from a side equals the count of elements between 
            that boundary and the target book's index.
            
            Time Complexity (TC): O(1)
            Space Complexity (SC): O(MAX_ID)
            */
            int dist_left = pos[id] - (left_ptr + 1);
            int dist_right = (right_ptr - 1) - pos[id];
            cout << min(dist_left, dist_right) << "\n";
        }
    }

    return 0;
}
