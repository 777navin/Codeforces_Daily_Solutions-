/*
=========================================================
Date        : 27-08-2026
Problem Name: STL
Platform    : Codeforces
Difficulty  : 1500
Tags        : dfs and similar, expression parsing, strings

Problem Summary:
Reconstruct a valid nested type expression in language X-- consisting of 
"int" and "pair<type,type>" from a sequence of words without punctuation.
Output the formatted string if valid and unique, otherwise output "Error occurred".

Key Observation:
The grammar is strictly recursive: every "pair" must be followed by exactly two valid types, 
and every "int" represents a base type. The whole sequence must form exactly one complete type.
=========================================================
*/

/*
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
APPROACH 1: Recursive Parsing (DFS / Pre-order Traversal)
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

• Intuition:
  The tokens represent the pre-order traversal of a full binary syntax tree where 
  "pair" is an internal node (degree 2) and "int" is a leaf node (degree 0).

• Approach:
  - Read all words from input into a list/stream.
  - Define a recursive function `parse()` that consumes the next token:
    - If token is "int", append "int" to the result.
    - If token is "pair", append "pair<", recursively parse the first argument, 
      append ",", recursively parse the second argument, and append ">".
  - If we run out of tokens during recursion, or if leftover tokens remain after 
    parsing the root, the input is invalid.

• Why it Works:
  The strict binary structure allows deterministic parsing via recursive descent; 
  any mismatch in expected subtrees or leftover words directly flags invalidity.

• Time Complexity (TC): O(M) where M is the total number of words / characters (~10^5 tokens).
• Space Complexity (SC): O(M) for storing tokens, call stack, and resulting string.
*/

/*
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
FINAL APPROACH: Recursive Parsing with Fast I/O
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
• Why this approach is chosen:
  Recursive descent naturally models the type grammar and avoids manual stack management.
• Why it is better:
  It operates in linear time O(M) and requires minimal memory overhead while checking validity on the fly.
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool error_flag = false;
string result = "";

void parse() {
    string token;
    if (!(cin >> token)) {
        error_flag = true;
        return;
    }

    if (token == "pair") {
        result += "pair<";
        parse();
        result += ",";
        parse();
        result += ">";
    } else if (token == "int") {
        result += "int";
    } else {
        error_flag = true;
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    parse();

    string extra;
    // If an error occurred or there are extra tokens left, it's invalid
    if (error_flag || (cin >> extra)) {
        cout << "Error occurred\n";
    } else {
        cout << result << "\n";
    }

    return 0;
}
