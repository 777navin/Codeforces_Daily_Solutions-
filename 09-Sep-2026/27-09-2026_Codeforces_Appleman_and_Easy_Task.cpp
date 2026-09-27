/*
=========================================================
Date        : 27-09-2026
Problem Name: Appleman and Easy Task
Platform    : Codeforces
Difficulty  : 1000
Tags        : implementation, brute force

Problem Summary:
Given an n x n grid consisting of 'x' and 'o' characters, determine whether every cell has an even number of adjacent cells (sharing a side) containing 'o'.
Output "YES" if the condition holds for all cells, otherwise "NO".

Key Observation:
For each cell, we can simply inspect its up, down, left, and right neighbors, count how many contain 'o', and verify if that count is even.
=========================================================
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    // Approach Explanation:
    // 1. Intuition:
    //    - Directly simulate the problem statement by checking all 4 orthogonal neighbors for every cell on the board.
    // 2. Approach:
    //    - Loop through each cell (i, j).
    //    - Count the number of adjacent cells containing 'o' using direction arrays or conditional checks.
    //    - If any cell has an odd count of adjacent 'o' characters, the condition fails immediately ("NO").
    //    - If all cells satisfy the even neighbor count, output "YES".
    // 3. Why it Works:
    //    - Since n <= 100, an O(n^2) check is extremely efficient and will easily pass well within the 1-second time limit.
    // 4. Time Complexity (TC):
    //    - O(n^2) because we iterate through each of the n^2 cells and check at most 4 constant neighbors.
    // 5. Space Complexity (SC):
    //    - O(n^2) to store the grid of characters.

    bool possible = true;
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int count_o = 0;
            for (int k = 0; k < 4; k++) {
                int ni = i + dr[k];
                int nj = j + dc[k];
                if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
                    if (grid[ni][nj] == 'o') {
                        count_o++;
                    }
                }
            }
            if (count_o % 2 != 0) {
                possible = false;
                break;
            }
        }
        if (!possible) break;
    }

    // Final Approach Choice:
    // - Simple iteration with boundary checking is chosen because the constraints are small (n <= 100), making it optimal and robust without extra overhead.
    if (possible) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}
