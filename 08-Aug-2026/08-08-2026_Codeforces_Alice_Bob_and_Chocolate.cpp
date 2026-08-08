/*
=========================================================
Date        : 08-08-2026
Problem Name: Alice, Bob and Chocolate
Platform: Codeforces
Difficulty: 1200
Tags: Two Pointers, Greedy

Problem Summary:
Alice and Bob consume n chocolate bars from the left and right sides respectively.
They eat at the same speed. If they reach a bar simultaneously, Alice gets to eat it.
Find the total number of chocolate bars each person consumes.

Key Observation:
Since they eat from opposite ends continuously, we can simulate the process using two 
pointers while tracking the cumulative time spent by each person.
=========================================================
*/

/*
1. Optimal Approach (Two Pointers)

* Intuition:
Since Alice eats from left to right and Bob from right to left, we can represent their 
positions using a left pointer and a right pointer. We must keep track of how much time 
each has spent so far to decide who gets the next available bar.

* Approach:
- Initialize `left` at 0 and `right` at n-1.
- Maintain `time_a` and `time_b` to track the total time elapsed for Alice and Bob.
- Use a while loop as long as `left <= right`.
- If `time_a <= time_b`, Alice consumes the `left` bar, and we increment her time, count, and pointer.
- Otherwise, Bob consumes the `right` bar, and we increment his time, count, and decrement his pointer.

* Why it Works:
This directly simulates the real-time consumption. The `<=` condition for Alice seamlessly 
handles the rule where Bob yields to Alice if they finish their current bars at the exact same moment.

* Time Complexity (TC):
O(N) - We iterate through the array of n chocolate bars exactly once.

* Space Complexity (SC):
O(N) - To store the input array of chocolate bar times.
*/

/*
=========================================================
FINAL APPROACH
=========================================================
The Two Pointers simulation is the chosen final approach because it operates in linear time 
O(N) with a single pass, which is optimal for N = 10^5 and well within the 2.0s time limit.
It directly models the problem statement without unnecessary complexity.
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> t(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    
    int left = 0, right = n - 1;
    int time_a = 0, time_b = 0;
    int a_count = 0, b_count = 0;
    
    while (left <= right) {
        if (time_a <= time_b) {
            time_a += t[left];
            left++;
            a_count++;
        } else {
            time_b += t[right];
            right--;
            b_count++;
        }
    }
    
    cout << a_count << " " << b_count << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // The problem does not specify multiple test cases per run
    int t = 1; 
    // cin >> t; 
    while (t--) {
        solve();
    }
    
    return 0;
}
