/*
=========================================================
Date        : 28-10-2026
Problem Name: C. Delete Two Elements
Platform    : Codeforces
Difficulty  : 1200
Tags        : Implementation, Math, Number Theory, Two Pointers

Problem Summary:
- Given an array of n integers, we find its mathematical mean k (sum / n).
- We need to find the number of pairs of indices (i, j) with i < j such that if both elements are removed, the mean of the remaining n - 2 elements remains equal to k.

Key Observation:
- Removing two elements with values a_i and a_j keeps the mean unchanged if and only if the sum of the removed elements equals 2 * k, or equivalently: a_i + a_j = (2 * sum) / n.
=========================================================
*/

/*
=========================================================
APPROACH EXPLANATION
=========================================================

1. Brute Force
   • Intuition: Iterate over all possible pairs of indices (i, j) with i < j, remove them, and check if the new mean matches the original.
   • Approach: Use nested loops to check every pair.
   • Why it Works: Directly simulates the problem statement.
   • Time Complexity (TC): O(n^2) per testcase.
   • Space Complexity (SC): O(1) auxiliary space.

2. Optimized (Frequency Map / Hashing)
   • Intuition: Instead of checking every pair, compute the target sum required for any two elements to sum to. Let target sum = 2 * sum / n. If (2 * sum) % n != 0, it's impossible to have an integer/exact mean match unless values align, but generally the required sum of the two elements must be exactly (2 * sum) / n.
   • Approach: 
     1. Calculate total sum of the array. Check if (2 * sum) % n == 0. If not, the sum of two removed elements can never be an integer value that satisfies the exact mean condition, so answer is 0.
     2. Let target = (2 * sum) / n.
     3. Count the frequency of each element using a frequency map or hash table.
     4. Iterate through unique elements. For each element x, look for its complement (target - x). Add frequency[x] * frequency[target - x] to the answer. Handle edge cases where x == target - x carefully using combination formula (count * (count - 1)) / 2.
   • Why it Works: Reduces the pair-search problem to a two-sum variant solvable in linear time using frequency counting.
   • Time Complexity (TC): O(n log n) due to map operations or O(n) using unordered_map.
   • Space Complexity (SC): O(n) to store element frequencies.

=========================================================
FINAL APPROACH CHOSEN
=========================================================
- The Optimized Frequency Map approach is chosen because n can be up to 2 * 10^5 across multiple test cases where sum of n <= 2 * 10^5. An O(n log n) or O(n) solution easily passes within the 2-second time limit, whereas O(n^2) would result in a Time Limit Exceeded (TLE).
*/

#include <iostream>
#include <vector>
#include <numeric>
#include <map>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    long long total_sum = 0;
    map<long long, long long> freq;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        total_sum += a[i];
        freq[a[i]]++;
    }

    // The condition for the mean of remaining (n - 2) elements to equal k (sum / n):
    // (total_sum - a_i - a_j) / (n - 2) = total_sum / n
    // Cross-multiplying gives: n * (total_sum - a_i - a_j) = (n - 2) * total_sum
    // n * total_sum - n * (a_i + a_j) = n * total_sum - 2 * total_sum
    // -n * (a_i + a_j) = -2 * total_sum
    // n * (a_i + a_j) = 2 * total_sum
    // a_i + a_j = (2 * total_sum) / n
    
    long long twice_sum = 2 * total_sum;
    if (twice_sum % n != 0) {
        cout << 0 << "\n";
        return;
    }

    long long target = twice_sum / n;
    long long count = 0;

    for (auto const& [val, freq_val] : freq) {
        long long complement = target - val;
        if (freq.find(complement) != freq.end()) {
            if (complement == val) {
                count += freq_val * (freq_val - 1) / 2;
            } else if (complement > val) {
                count += freq_val * freq[complement];
            }
        }
    }

    cout << count << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
