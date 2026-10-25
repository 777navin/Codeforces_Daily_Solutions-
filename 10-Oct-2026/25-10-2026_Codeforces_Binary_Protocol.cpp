/*
=========================================================
Date        : 25-10-2026
Problem Name: Binary Protocol
Platform    : Codeforces
Difficulty  : 1100
Tags        : Implementation, Strings

Problem Summary:
Polycarp encoded a positive integer into a binary string where each digit is represented by that many '1's, and digits are separated by a single '0'.
We need to decode this binary string back into the original decimal number.

Key Observation:
- Consecutive '1's represent the value of a single digit.
- A '0' acts as a separator between digits, except when two '0's appear consecutively, which indicates that the digit between them was '0'.
=========================================================
*/

/*
=========================================================
APPROACH EXPLANATION
=========================================================

1. Simulation / Iteration
   • Intuition: Iterate through the string and count consecutive '1's. Whenever we encounter a '0', the accumulated count gives the value of the current digit.
   • Approach: 
     - Maintain a counter for consecutive '1's.
     - Traverse the string character by character.
     - If the character is '1', increment the counter.
     - If the character is '0', append the current count to our result and reset the counter.
     - Handle consecutive '0's (which represent a digit '0') by checking if the previous character was also '0'.
   • Why it Works: It directly reverses Polycarp's encoding scheme by translating counts of '1's back into their respective decimal digits.
   • Time Complexity (TC): O(n) where n is the length of the string.
   • Space Complexity (SC): O(1) auxiliary space (excluding storage for the output result).

=========================================================
FINAL APPROACH
=========================================================
- The simulation approach is chosen because it directly models the encoding logic in linear time with constant extra space. It correctly handles digit separation and zero values via simple state checks.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // Optimize standard I/O operations for speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    string s;
    cin >> s;

    string decoded_number = "";
    int count_ones = 0;

    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            count_ones++;
        } else {
            // '0' encountered: append the accumulated ones count
            decoded_number += to_string(count_ones);
            count_ones = 0;
            
            // Check if it's part of consecutive zeros representing a digit '0'
            // If the next character is also '0' (or if we are handling double zeros), 
            // a single '0' value needs to be recorded.
            if (i + 1 < n && s[i + 1] == '0') {
                decoded_number += "0";
                i++; // Skip the next '0' as it's processed together
            }
        }
    }
    
    // Append the last counted block of ones
    decoded_number += to_string(count_ones);

    cout << decoded_number << "\n";

    return 0;
}
