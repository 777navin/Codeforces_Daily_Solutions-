/*
Date: 21-05-2026
Problem Name: 152A - Marks
Platform: Codeforces
Difficulty: 900
Tags: Implementation

Problem Summary:
Given the marks of 'n' students in 'm' subjects (ranging from 1 to 9), a student is considered "successful" if they are the best at at least one subject. Being the "best" means no other student scored strictly higher than them in that particular subject. The task is to calculate the total number of successful students.

Methods to Solve:
1. Optimal Approach (Greedy / Matrix Traversal)

For EACH method include:

--- 1. Optimal Approach ---
- Intuition:
  To determine if a student is successful, we first need to identify the highest score achieved by anyone in each subject. Once we have a list of the maximum marks for every subject, we can evaluate each student individually to see if they hit the maximum mark in any of the subjects they took.

- Approach:
  1. Read the input into a 2D grid/vector of strings representing the students and their marks.
  2. Create an array `max_marks` of size `m` to track the highest score per subject.
  3. Loop through every column (subject) and find the maximum character value, storing it in `max_marks`.
  4. Loop through every row (student) and compare their marks against the `max_marks` array.
  5. If `marks[i][j] == max_marks[j]`, flag the student as successful, increment the count, and `break` to the next student to avoid double-counting.
  6. Print the total count.

- Dry Run (small example):
  Input: 
  3 3
  223
  232
  112

  Step 1: Find max marks per subject:
  - Subject 0 (col 0): max('2', '2', '1') -> '2'
  - Subject 1 (col 1): max('2', '3', '1') -> '3'
  - Subject 2 (col 2): max('3', '2', '2') -> '3'
  max_marks = ['2', '3', '3']

  Step 2: Check each student:
  - Student 0 ("223"): For Sub 2, mark '3' == max_marks[2]. Successful! (Count = 1)
  - Student 1 ("232"): For Sub 1, mark '3' == max_marks[1]. Successful! (Count = 2)
  - Student 2 ("112"): No marks match the max_marks array. Not successful.
  
  Output: 2

- Time Complexity: O(N * M)
  We traverse the grid twice (once to find maximums, once to check students). Since N, M <= 100, N*M is at most 10,000 operations, which runs well within the 1-second time limit.

- Space Complexity: O(N * M)
  We store the entire grid of marks in memory. Additionally, O(M) space is used for the `max_marks` array.

- Why better than previous method: 
  This is the most direct and optimal approach for this specific problem context. No sorting or complex data structures are required.

- When to use: 
  Use this for 2D matrix problems where properties of a row depend on column-wide aggregates (like finding column maximums).

Comparison Table:
Method             | TC       | SC       | Best Use Case
-------------------|----------|----------|----------------------------------------
Optimal Approach   | O(N * M) | O(N * M) | Standard matrix traversal problems

Final Recommended Solution: Optimal Approach
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Fast I/O Boilerplate for Competitive Programming
void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return; // Handle EOF

    vector<string> marks(n);
    for (int i = 0; i < n; ++i) {
        cin >> marks[i];
    }

    // Array to store the highest mark obtained in each subject
    vector<char> max_marks(m, '0');

    // Find the maximum mark for each subject
    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n; ++i) {
            max_marks[j] = max(max_marks[j], marks[i][j]);
        }
    }

    int successful_students = 0;

    // Check each student to see if they got the highest mark in any subject
    for (int i = 0; i < n; ++i) {
        bool is_successful = false;
        for (int j = 0; j < m; ++j) {
            if (marks[i][j] == max_marks[j]) {
                is_successful = true;
                break; // Student is successful, no need to check other subjects
            }
        }
        
        if (is_successful) {
            successful_students++;
        }
    }

    cout << successful_students << "\n";
}

int main() {
    fastIO();
    
    // Codeforces usually has multiple test cases per run in modern contests,
    // but older problems (like 152A) use single test case per file.
    // Handling as a single testcase template:
    int t = 1; 
    // cin >> t; // Uncomment if problem requires multiple test cases

    while (t--) {
        solve();
    }

    return 0;
}
