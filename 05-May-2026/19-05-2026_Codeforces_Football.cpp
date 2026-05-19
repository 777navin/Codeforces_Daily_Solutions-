/*
Date: 19-05-2026
Problem Name: 43A - Football
Platform: Codeforces
Difficulty: 1000 (Div. 2 A)
Tags: Strings, Implementation, Hashing

Problem Summary:
Given 'n' lines of strings representing goals scored by teams in a football match, 
determine the winning team. The match is guaranteed to not end in a tie, and 
there are no more than two distinct teams playing.

Methods to Solve:

1. Two-Variable Tracking (Optimal for this specific constraint)
   - Intuition: The problem states there are AT MOST 2 distinct teams. We don't 
     need complex data structures; we can just track the two team names and their scores.
   - Approach: Read the first team's name and set its score to 1. For the remaining 
     n-1 goals, check if the goal belongs to the first team. If yes, increment its score. 
     If no, it must belong to the second team; save the second team's name and increment 
     its score. Compare the two scores at the end.
   - Dry Run: 
     Input: 5 \n A \n ABA \n ABA \n A \n A
     Step 1: team1 = "A", count1 = 1
     Step 2: next is "ABA". Not equal to "A". team2 = "ABA", count2 = 1
     Step 3: next is "ABA". Equals team2. count2 = 2
     Step 4: next is "A". Equals team1. count1 = 2
     Step 5: next is "A". Equals team1. count1 = 3
     Result: count1 (3) > count2 (2), winner is "A".
   - Time Complexity: O(N * L) where N is number of goals, L is max string length (10).
   - Space Complexity: O(L) to store the two string variables.
   - Why better than previous method: N/A (this is the most space-efficient).
   - When to use: When the number of distinct categories (teams) is strictly limited to 2.

2. Hash Map (Frequency Array for Strings - General Approach)
   - Intuition: If the problem were generalized to 'K' teams, tracking variables 
     would become messy. A frequency map handles any number of teams dynamically.
   - Approach: Use `std::unordered_map<string, int>` to tally the goals. Keep a running 
     maximum of goals and update the winning team string whenever a new maximum is reached.
   - Dry Run: 
     Map state: {"A": 1} -> {"A": 1, "ABA": 1} -> {"A": 1, "ABA": 2} -> 
                {"A": 2, "ABA": 2} -> {"A": 3, "ABA": 2}. Max is "A" with 3.
   - Time Complexity: O(N * L) for inserting N strings of length L into the hash map.
   - Space Complexity: O(K * L) where K is the number of distinct teams (K=2 here).
   - Why better than previous method: It scales automatically to any number of teams without code changes.
   - When to use: General string frequency counting problems.

Comparison Table:
Method               | TC       | SC       | Best Use Case
---------------------|----------|----------|----------------------------------------
1. Two-Variable      | O(N*L)   | O(L)     | Strictly 2 distinct teams (Memory constrained)
2. Hash Map          | O(N*L)   | O(K*L)   | Standard approach, works for >2 teams (Recommended)

Final Recommended Solution: Method 2 (Hash Map) for its clean logic and scalability.
*/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    unordered_map<string, int> goals;
    string winningTeam = "";
    int maxGoals = 0;
    
    for (int i = 0; i < n; ++i) {
        string team;
        cin >> team;
        
        // Increment the goal count for the scoring team
        goals[team]++;
        
        // Dynamically track the winning team to avoid a second pass
        if (goals[team] > maxGoals) {
            maxGoals = goals[team];
            winningTeam = team;
        }
    }
    
    // Output the team with the maximum goals
    cout << winningTeam << "\n";
}

int main() {
    // Fast I/O for Competitive Programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // Codeforces problems often have multiple test cases, 
    // but this specific problem only has a single test case per run.
    int t = 1; 
    // cin >> t; // Uncomment if multiple test cases are introduced
    while (t--) {
        solve();
    }
    
    return 0;
}
