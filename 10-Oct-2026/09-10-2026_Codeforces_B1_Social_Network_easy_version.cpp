/*
=========================================================
Date        : 09-10-2026
Problem Name: B1. Social Network (easy version)
Platform    : Codeforces
Difficulty  : Easy (800)
Tags        : Data Structures, Implementation, Queues, Simulation

Problem Summary:
You receive a sequence of messages from friends, identified by unique IDs.
Your phone displays at most k most recent conversations.
If a message arrives from a friend whose chat is already displayed, nothing changes.
Otherwise, the new chat is placed at the top, and if the screen has k chats, the bottom one is removed.
You need to print the final list of displayed conversations from top to bottom.

Key Observation:
We need a dynamic container that maintains elements in order of insertion, allows efficient lookup 
to check presence, and maintains a maximum capacity of k by popping the oldest element when full.
=========================================================
*/

#include <iostream>
#include <vector>
#include <deque>
#include <unordered_set>
#include <algorithm>

using namespace std;

/*
---------------------------------------------------------
APPROACH 1: Queue + Set Simulation (Optimal)
---------------------------------------------------------
• Intuition:
  A deque (or queue) naturally tracks the order of conversations (newest at the front, 
  oldest at the back), while an unordered_set provides O(1) lookup to check if a friend's 
  conversation is currently displayed.

• Approach:
  Process each message ID one by one.
  If the ID is already in the set, skip it.
  If not:
    - If the deque size equals k, remove the oldest friend (back of deque) from both deque and set.
    - Push the new ID to the front of the deque and insert it into the set.
  Finally, print the size and elements of the deque in order.

• Why it Works:
  The deque maintains the sliding window of at most k most recent unique conversations in correct 
  order, and the hash set allows O(1) presence checks to prevent duplicate additions.

• Time Complexity (TC) : O(n) - Processing each message takes O(1) time on average using unordered_set.
• Space Complexity (SC): O(k) - At most k conversation IDs are stored in the deque and hash set.
---------------------------------------------------------
*/

/*
=========================================================
FINAL APPROACH CHOICE
=========================================================
• Approach 1 (Queue + Set) is chosen because it achieves optimal O(n) time complexity and O(k) space.
• It directly simulates the sliding window logic of length k using efficient STL containers (deque + hash set).
=========================================================
*/

void solve() {
    int n, k;
    if (!(cin >> n >> k)) return;

    deque<int> dq;
    unordered_set<int> present;

    for (int i = 0; i < n; ++i) {
        int id;
        cin >> id;

        // If conversation is already on the screen, do nothing
        if (present.count(id)) {
            continue;
        }

        // If screen is full, remove the oldest conversation
        if (dq.size() == k) {
            int oldest = dq.back();
            dq.pop_back();
            present.erase(oldest);
        }

        // Add the new conversation to the top
        dq.push_front(id);
        present.insert(id);
    }

    // Output the results
    cout << dq.size() << "\n";
    for (int i = 0; i < (int)dq.size(); ++i) {
        cout << dq[i] << (i + 1 == (int)dq.size() ? "" : " ");
    }
    cout << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
