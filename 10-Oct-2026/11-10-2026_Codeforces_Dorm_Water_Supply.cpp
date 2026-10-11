/*
=========================================================
Date        : 11-10-2026
Problem Name: A. Dorm Water Supply
Platform    : Codeforces
Difficulty  : 1400
Tags        : Graph Theory, DFS/BFS, Implementation

Problem Summary:
- Given $n$ houses and $p$ directed water pipes with given diameters, where each house has at most one incoming and one outgoing pipe.
- We need to identify all chains starting from water tanks (houses with outgoing pipe but no incoming pipe) to water taps (houses with incoming pipe but no outgoing pipe).
- For each chain, find the minimum diameter among all pipes in the path (which limits the maximum water flow) and output all valid tank-tap pairs sorted increasingly by the tank index.

Key Observation:
- Since each house has an in-degree $\le 1$ and out-degree $\le 1$, the graph consists of disjoint paths and cycles.
- We can simply start traversing from every node that has an out-degree of 1 and in-degree of 0 (tank), follow the path until we reach a node with no outgoing pipe (tap), and keep track of the minimum pipe diameter along the path.
=========================================================
*/

/*
APPROACH EXPLANATION:

1. Optimized (Graph Traversal / Simulation)
• Intuition: Since in-degrees and out-degrees are at most 1, paths are simple and non-branching. We can locate all starting nodes (tanks) and trace each path to its end (tap).
• Approach: Maintain arrays for outgoing edges, incoming edges, and edge diameters. Iterate through all nodes to find tanks (in-degree == 0 and out-degree == 1). From each tank, traverse forward to find the endpoint tap while tracking the minimum diameter.
• Why it Works: The structural constraint ensures that each tank uniquely leads to at most one tap through a simple path without any forks.
• Time Complexity (TC): O(n) as each node and edge is visited at most once.
• Space Complexity (SC): O(n) for storing graph connections and tracking visited states.
*/

/*
FINAL APPROACH:
The simulation/traversal approach is chosen because the graph structure guarantees simple linear paths from tanks to taps. It efficiently finds all valid connections and minimum diameters in linear time without complex max-flow algorithms.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Optimize standard I/O operations for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, p;
    cin >> n >> p;

    vector<int> next_house(n + 1, 0);
    vector<int> diameter(n + 1, 0);
    vector<int> in_degree(n + 1, 0);
    vector<int> out_degree(n + 1, 0);

    for (int i = 0; i < p; ++i) {
        int u, v, d;
        cin >> u >> v >> d;
        next_house[u] = v;
        diameter[u] = d;
        out_degree[u]++;
        in_degree[v]++;
    }

    vector<pair<int, pair<int, int>>> results;

    // Find all tanks (houses with outgoing pipe and no incoming pipe)
    for (int i = 1; i <= n; ++i) {
        if (in_degree[i] == 0 && out_degree[i] > 0) {
            int curr = i;
            int min_dia = 1e9;
            
            // Traverse the path to find the corresponding tap and minimum diameter
            while (next_house[curr] != 0) {
                min_dia = min(min_dia, diameter[curr]);
                curr = next_house[curr];
            }
            
            results.push_back({i, {curr, min_dia}});
        }
    }

    // Output the total number of tank-tap pairs
    cout << results.size() << "\n";

    // Output each pair ordered by the tank index
    for (auto& res : results) {
        cout << res.first << " " << res.second.first << " " << res.second.second << "\n";
    }

    return 0;
}
