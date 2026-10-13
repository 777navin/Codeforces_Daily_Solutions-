/*
=========================================================
Date        : 13-10-2026
Problem Name: NP-Hard Problem
Platform    : Codeforces
Difficulty  : 1500
Tags        : Graphs, DFS, BFS, Bipartite

Problem Summary:
- Given an undirected graph, find two disjoint vertex covers A and B.
- If no such partition exists, output -1.
- Each vertex can belong to at most one subset, or neither.

Key Observation:
- A set of vertices is a vertex cover if and only if its complement is an independent set.
- Since A and B are disjoint vertex covers and their complements are independent sets, the graph must be bipartite.
=========================================================
*/

/*
Approach 1: Breadth-First Search (BFS) / Depth-First Search (DFS) for Bipartite Check
• Intuition:
  - For both A and B to be vertex covers, every edge must have at least one endpoint in A and at least one endpoint in B.
  - This implies that if we partition the graph into two color sets (0 and 1), no two adjacent vertices can have the same color.
  - Thus, the graph must be bipartite, and we can color it using alternating colors.

• Approach:
  - Run BFS or DFS starting from all unvisited components to 2-color the graph.
  - If any odd-length cycle is detected (i.e., an edge connects two nodes of the same color), it is impossible; output -1.
  - Otherwise, collect all nodes of color 0 into set A and color 1 into set B.

• Why it Works:
  - 2-coloring guarantees that no two connected vertices share the same subset, fulfilling the vertex cover condition for both sets.

• Time Complexity (TC): O(n + m)
• Space Complexity (SC): O(n + m)
*/

/*
=========================================================
FINAL APPROACH SELECTION:
- BFS-based graph coloring is chosen because it easily checks if the graph is bipartite and efficiently partitions the nodes in linear time.
- It is optimal and handles disconnected components robustly.
=========================================================
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    // Optimize input/output operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> color(n + 1, -1);
    vector<int> setA, setB;

    // Traverse all components of the graph
    for (int i = 1; i <= n; ++i) {
        if (color[i] == -1) {
            queue<int> q;
            q.push(i);
            color[i] = 0;
            setA.push_back(i);

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v : adj[u]) {
                    if (color[v] == -1) {
                        color[v] = 1 - color[u];
                        if (color[v] == 0) {
                            setA.push_back(v);
                        } else {
                            setB.push_back(v);
                        }
                        q.push(v);
                    } else if (color[v] == color[u]) {
                        // Graph is not bipartite, impossible to split into two vertex covers
                        cout << -1 << "\n";
                        return 0;
                    }
                }
            }
        }
    }

    // Print results for Set A
    cout << setA.size() << "\n";
    for (int i = 0; i < setA.size(); ++i) {
        cout << setA[i] << (i == setA.size() - 1 ? "" : " ");
    }
    cout << "\n";

    // Print results for Set B
    cout << setB.size() << "\n";
    for (int i = 0; i < setB.size(); ++i) {
        cout << setB[i] << (i == setB.size() - 1 ? "" : " ");
    }
    cout << "\n";

    return 0;
}
