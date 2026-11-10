/*
=========================================================
Date        : 10-11-2026
Problem Name: Carrot Cakes
Platform    : Codeforces
Difficulty  : 1100
Tags        : implementation, math

Problem Summary:
- Arkady needs at least n cakes. One oven takes t minutes to bake k cakes.
- He can build a second oven, which takes d minutes to build.
- While building, only the first oven bakes. After d minutes, both ovens bake simultaneously.
- Determine if building the second oven strictly decreases the total time needed to get n cakes.

Key Observation:
- Calculate the total time needed using only one oven: ceil(n / k) * t.
- Simulate the timeline with two ovens: at time d, the second oven starts. Track the total cakes baked at each time step or find the time when total cakes reach n.
=========================================================
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, t, k, d;
    if (!(cin >> n >> t >> k >> d)) return 0;

    // Time needed with only one oven
    int one_oven_time = ((n + k - 1) / k) * t;

    // Let's check the state after d minutes.
    // At time d, the first oven has completed (d / t) baking cycles, producing (d / t) * k cakes.
    // If (d / t) * k >= n, the first oven has already finished (or would finish at the exact time d or earlier),
    // but wait: if d is a multiple of t, at time d the first oven finishes a batch. Let's be precise.
    
    // Actually, let's simulate or calculate the time needed with two ovens.
    // With two ovens:
    // From time 0 to d, only oven 1 operates.
    // Cakes baked by time d: (d / t) * k.
    // Remaining cakes needed: n - (d / t) * k. If <= 0, 0 cakes needed after d.
    // From time d onwards, both ovens operate.
    // Let's find the exact time T >= d when total cakes >= n.
    // Total cakes at time T (where T >= d):
    // Cakes from oven 1 by time T: ((T) / t) * k
    // Cakes from oven 2 by time T-d: ((T - d) / t) * k
    // Total = ((T) / t) * k + ((T - d) / t) * k
    // Since T can be at most one_oven_time, we can check for each time step or find the minimum T >= d.
    // Alternatively, a simpler condition: 
    // Does the second oven finish at least one batch *strictly before* the first oven finishes the last batch needed?
    // Let's check time T from d + 1 up to one_oven_time - 1:
    bool possible = false;
    for (int time = 1; time <= one_oven_time; ++time) {
        int cakes_one = (time / t) * k;
        int cakes_two = (time > d) ? ((time - d) / t) * k : 0;
        if (cakes_one + cakes_two >= n) {
            if (time < one_oven_time) {
                possible = true;
            }
            break;
        }
    }

    /*
    =========================================================
    FINAL APPROACH
    =========================================================
    • Why this approach is chosen:
      Simulating the minute-by-minute cake production up to the single-oven completion time is straightforward and completely avoids edge-case formula errors given the small constraints (n, t, k, d <= 1000).
    • Why it is better than the previous ones:
      It directly checks if the total time with two ovens is strictly less than `one_oven_time`, accurately handling all overlapping baking cycles.
    =========================================================
    */

    if (possible) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}
