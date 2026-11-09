/*
=========================================================
Date        : 09-11-2026
Problem Name: Center Alignment (Codeforces 5B)
Platform    : Codeforces
Difficulty  : 1200
Tags        : implementation, strings

Problem Summary:
- Given one or more lines of text, frame the entire text with '*' characters of the minimum possible size.
- Center-align each line horizontally inside the frame.
- If a line's length cannot be centered perfectly (uneven remaining spaces), alternate the direction of rounding (starting towards the left).

Key Observation:
- The total width of the inner frame is determined by the maximum line length among all input lines.
- For a line of length $len$ inside a frame of width $W$, the number of spaces to pad is $total\_spaces = W - len$.
- The left padding alternates between $\lfloor total\_spaces / 2 \rfloor$ and $\lceil total\_spaces / 2 \rceil$.
=========================================================
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/*
=========================================================
APPROACH EXPLANATION
=========================================================

1. Single Pass Simulation
   • Intuition: Read all lines first to find the maximum line length, which dictates the width of our frame.
   • Approach: Store all lines in a vector, find the maximum length ($W$), and then process each line to add appropriate padding and borders.
   • Why it Works: Knowing the maximum length ensures the bounding box accommodates the longest line without truncation. Alternating state tracks whether an extra space goes to the left or right for uneven lengths.
   • Time Complexity (TC): O(N * L) where N is the number of lines and L is the maximum length of a line.
   • Space Complexity (SC): O(N * L) to store the input lines.

=========================================================
FINAL APPROACH
=========================================================
- We use a single straightforward simulation approach. It reads all lines, determines the frame width, and constructs the output line by line with alternating alignment for odd-length differences, matching Codeforces problem requirements precisely.
*/

int main() {
    // Optimize standard I/O operations for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string> lines;
    string s;
    int max_len = 0;

    // Read all lines from standard input until EOF
    while (getline(cin, s)) {
        lines.push_back(s);
        if ((int)s.length() > max_len) {
            max_len = s.length();
        }
    }

    // Create the horizontal border of length max_len + 2
    string border(max_len + 2, '*');

    // Print top border
    cout << border << "\n";

    // Track state for uneven alignment: false means extra space goes to the left first
    bool left_turn = true;

    for (const string& line : lines) {
        int diff = max_len - line.length();
        int left_spaces, right_spaces;

        if (diff % 2 == 0) {
            left_spaces = diff / 2;
            right_spaces = diff / 2;
        } else {
            if (left_turn) {
                left_spaces = diff / 2;
                right_spaces = diff / 2 + 1;
            } else {
                left_spaces = diff / 2 + 1;
                right_spaces = diff / 2;
            }
            // Toggle the turn for the next uneven line
            left_turn = !left_turn;
        }

        // Print formatted line with frame
        cout << "*" << string(left_spaces, ' ') << line << string(right_spaces, ' ') << "*\n";
    }

    // Print bottom border
    cout << border << "\n";

    return 0;
}
