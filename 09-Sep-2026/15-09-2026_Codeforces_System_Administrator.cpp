/*
=========================================================
Date        : 15-09-2026
Problem Name: System Administrator
Platform: Codeforces
Difficulty: 1700
Tags: Constructive Algorithms, Graphs

Problem Summary:
Connect n servers with exactly m direct two-way connections such that the system is fully connected.
The system must become disconnected (split into at least two components) if a specific server 'v' fails.

Key Observation:
Make 'v' an articulation point by isolating one node 'u' such that 'u' connects ONLY to 'v'.
The remaining nodes can form a dense clique with 'v' to absorb excess edges up to the maximum limit.
=========================================================

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
APPROACH EXPLANATION
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
1. Optimal Construction
• Intuition: To guarantee the graph disconnects when 'v' is removed, 'v' must act as a bridge. The simplest configuration is a single node 'u' connected solely to 'v', and a second component containing the rest of the nodes.
• Approach: 
  - Pick a node 'u' != 'v'.
  - Edge 1: Connect 'u' to 'v'.
  - Edges 2 to n-1: Connect 'v' to all remaining nodes (set B) to ensure initial connectivity.
  - Remaining Edges: Add edges between any pairs of nodes strictly within set B until we reach 'm' edges.
• Why it Works: This safely maximizes the possible edges by building a full clique of size n-1 (nodes in B + 'v'), allowing a maximum of 1 + (n-1)(n-2)/2 edges overall. If m is outside [n-1, max_edges], it's impossible.
• Time Complexity (TC): O(m), because we iterate and print exactly 'm' valid edges.
• Space Complexity (SC): O(n) to store the set of remaining vertices (set B).

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
FINAL APPROACH
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
• The Optimal Construction approach is chosen because constructive problems require a direct, deterministic build.
• It analytically checks feasibility in O(1) time and outputs the graph systematically without searching or backtracking, adhering perfectly to the constraints.
*/

#include <iostream>
#include <vector>

using namespace std;

void solve() {
    long long n, m, v;
    cin >> n >> m >> v;

    // A connected graph needs at least n-1 edges.
    // Max edges where removing 'v' disconnects the graph is when we have one isolated node 
    // attached to 'v', and a full clique for the remaining (n-1) nodes.
    long long max_edges = 1 + (n - 1) * (n - 2) / 2;
    
    if (m < n - 1 || m > max_edges) {
        cout << -1 << "\n";
        return;
    }

    // Pick 'u' to be the isolated node that connects only to 'v'
    long long u = (v == 1) ? 2 : 1;
    
    // Set B will hold all nodes except 'v' and 'u'
    vector<long long> B;
    for (long long i = 1; i <= n; ++i) {
        if (i != v && i != u) {
            B.push_back(i);
        }
    }

    // 1. Establish the required cut edge
    cout << u << " " << v << "\n";
    m--;

    // 2. Connect 'v' to everything in B to form the backbone (ensures graph is fully connected)
    for (long long x : B) {
        cout << v << " " << x << "\n";
        m--;
    }

    // 3. Add remaining edges by connecting pairs entirely within B
    for (size_t i = 0; i < B.size() && m > 0; ++i) {
        for (size_t j = i + 1; j < B.size() && m > 0; ++j) {
            cout << B[i] << " " << B[j] << "\n";
            m--;
        }
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    
    return 0;
}
