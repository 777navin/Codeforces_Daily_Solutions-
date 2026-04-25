/*
Date: 25-04-2026
Problem Name: Cd and pwd commands (Problem 158C)
Platform: Codeforces
Difficulty: 1200 (Medium-Easy)
Tags: Implementation, Strings, Data Structures, Stack

Problem Summary:
Simulate a basic Unix-like directory system supporting two commands:
1. `pwd`: Print the absolute path of the current directory.
2. `cd <path>`: Change directory. Supports both absolute paths (starting with `/`) 
   and relative paths, as well as navigating up to the parent directory using `..`.

Methods to Solve:

1. Optimal Approach (Stack-based String Simulation):
   - Intuition: The directory structure naturally mimics a stack. Moving into a directory 
     is a `push` operation, and moving up (`..`) is a `pop` operation. 
   - Approach: 
     a. Maintain a `std::vector<std::string>` to represent the current absolute path (acting as a stack).
     b. On `pwd`, iterate through the vector and print each directory enclosed/preceded by `/`.
     c. On `cd`, first check if the path starts with `/`. If so, it's an absolute path, so clear the stack.
     d. Tokenize the path string using `/` as a delimiter. 
     e. For each token: if it's `..`, pop the stack; if it's empty, ignore; otherwise, push the directory name.
   - Dry Run (cd /home/vasya/../petya):
     - Starts with `/`: stack is cleared `[]`.
     - Token "home": stack becomes `["home"]`.
     - Token "vasya": stack becomes `["home", "vasya"]`.
     - Token "..": pop stack, becomes `["home"]`.
     - Token "petya": stack becomes `["home", "petya"]`.
     - `pwd` output: `/home/petya/`.
   - Time Complexity: O(N * L) where N is the number of commands and L is the max length of the path string. 
     String tokenization and stack operations are linear relative to the input length.
   - Space Complexity: O(L) to store the directory tokens in the stack.
   - Why better: This is the definitive and optimal way to solve path resolution problems.
   - When to use: Pathing simulations, URL resolutions, and filesystem traversals.

Comparison Table:
Method               | TC       | SC     | Best Use Case
---------------------|----------|--------|--------------------------
Stack Simulation     | O(N * L) | O(L)   | Standard filesystem logic 

Final Recommended Solution: Stack-based String Simulation.
*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;

    // The vector acts as a stack representing the current directory hierarchy
    vector<string> current_path;
    string command, path_arg;

    for (int i = 0; i < n; ++i) {
        cin >> command;
        
        if (command == "pwd") {
            cout << "/";
            for (const string& dir : current_path) {
                cout << dir << "/";
            }
            cout << "\n";
        } 
        else if (command == "cd") {
            cin >> path_arg;
            
            // If it's an absolute path, reset the directory tree to root
            if (path_arg[0] == '/') {
                current_path.clear();
            }
            
            // Tokenize the path string by '/'
            stringstream ss(path_arg);
            string token;
            
            while (getline(ss, token, '/')) {
                // Ignore empty tokens (caused by leading/trailing slashes or consecutive slashes)
                if (token.empty()) {
                    continue;
                }
                
                // ".." means go up one directory (pop the stack)
                if (token == "..") {
                    if (!current_path.empty()) {
                        current_path.pop_back();
                    }
                } 
                // Otherwise, move into the new directory (push onto the stack)
                else {
                    current_path.push_back(token);
                }
            }
        }
    }
}

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // Process the commands
    solve();
    
    return 0;
}
