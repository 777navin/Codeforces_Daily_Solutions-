/**
 * Target Platform: Codeforces
 * Problem Name: Accordion (1101B)
 * Profile: navin_0509
 * Date: 01-10-2026
 * 
 * Problem Summary:
 * Given a string s, find the maximum length of an "accordion" sub-sequence that can be formed.
 * An accordion is defined as a string starting with '[', followed by a ':', then zero or more '|',
 * followed by another ':', and ending with ']'. If no such accordion can be formed, return -1.
 * 
 * Time Complexity: O(N) where N is the length of string s.
 * Space Complexity: O(1) auxiliary space.
 */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
    string s;
    if (!(cin >> s)) return;

    int n = s.length();

    // Find the first '[' from the left
    int left_bracket = -1;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '[') {
            left_bracket = i;
            break;
        }
    }

    // Find the first ':' after the first '['
    int left_colon = -1;
    if (left_bracket != -1) {
        for (int i = left_bracket + 1; i < n; ++i) {
            if (s[i] == ':') {
                left_colon = i;
                break;
            }
        }
    }

    // Find the last ']' from the right
    int right_bracket = -1;
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == ']') {
            right_bracket = i;
            break;
        }
    }

    // Find the last ':' before the last ']'
    int right_colon = -1;
    if (right_bracket != -1) {
        for (int i = right_bracket - 1; i >= 0; --i) {
            if (s[i] == ':') {
                right_colon = i;
                break;
            }
        }
    }

    // Check if a valid structure [ : ... : ] exists in correct order
    if (left_bracket == -1 || left_colon == -1 || right_bracket == -1 || right_colon == -1 || left_colon >= right_colon) {
        cout << -1 << "\n";
        return;
    }

    // Count vertical lines '|' between left_colon and right_colon
    int bars = 0;
    for (int i = left_colon + 1; i < right_colon; ++i) {
        if (s[i] == '|') {
            bars++;
        }
    }

    // Length = 4 mandatory characters ('[', ':', ':', ']') + count of '|'
    cout << 4 + bars << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
