/*
=========================================================
Date        : 04-08-2026
Problem Name: Glory Addicts (1738A)
Platform    : Codeforces
Difficulty  : 800
Tags        : greedy, sortings, math

Problem Summary:
The hero has 'n' skills of two types (fire and frost).
Playing a skill immediately after one of a different type doubles its damage.
The goal is to reorder the skills to maximize the total damage dealt.

Key Observation:
To maximize damage, alternate between the two types to double the highest damage values. 
If counts are equal, all but the absolute minimum damage skill get doubled.
=========================================================

=========================================================
APPROACHES
=========================================================

1. Greedy Sorting (Most Optimal)
   • Intuition: Since we want to maximize the sum, we should double the largest elements. We can achieve this by pairing fire and frost skills.
   • Approach: Group skills by type and sort them in descending order. 
     - If we have equal numbers of fire and frost skills, we can double all of them except the very first one we use. We pick the absolute minimum of all skills to NOT double.
     - If the counts differ, say 'k' is the minimum count between the two types, we can double the top 'k' skills of BOTH types. The remaining un-paired skills of the more frequent type are just added normally.
   • Why it Works: Sorting guarantees we are applying the 2x multiplier to the absolute highest damage values possible based on the alternation constraints.
   • Time Complexity (TC): O(N log N) because we sort the skill damages.
   • Space Complexity (SC): O(N) to store the separated fire and frost skills.

=========================================================
FINAL APPROACH
=========================================================
The Greedy Sorting approach is chosen because it directly addresses the 
optimal substructure of maximizing the multiplier on the largest elements. 
It is both optimal and easily runs well within the 2.0 second time limit.
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> type(n);
    for(int i = 0; i < n; i++) {
        cin >> type[i];
    }
    
    vector<long long> fire, frost;
    for(int i = 0; i < n; i++) {
        long long dmg;
        cin >> dmg;
        if(type[i] == 0) {
            fire.push_back(dmg);
        } else {
            frost.push_back(dmg);
        }
    }
    
    // Sort in descending order to prioritize doubling large damages
    sort(fire.rbegin(), fire.rend());
    sort(frost.rbegin(), frost.rend());
    
    long long total_damage = 0;
    
    // Case 1: Equal number of fire and frost skills
    if (fire.size() == frost.size()) {
        for (long long x : fire) total_damage += 2 * x;
        for (long long x : frost) total_damage += 2 * x;
        
        // The first skill played cannot be doubled, subtract the smallest element
        long long min_val = min(fire.back(), frost.back());
        total_damage -= min_val;
    } 
    // Case 2: Unequal counts
    else {
        int k = min(fire.size(), frost.size());
        
        // Double the top 'k' elements from both types
        for (int i = 0; i < k; i++) {
            total_damage += 2 * fire[i];
            total_damage += 2 * frost[i];
        }
        
        // Add the remaining elements without doubling
        for (int i = k; i < fire.size(); i++) {
            total_damage += fire[i];
        }
        for (int i = k; i < frost.size(); i++) {
            total_damage += frost[i];
        }
    }
    
    cout << total_damage << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    
    return 0;
}
