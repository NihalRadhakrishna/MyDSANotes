// LeetCode Problem: 277. Find the Celebrity
// Problem Link: https://leetcode.com/problems/find-the-celebrity/


class Solution {
    public:
        // Elimination approach: if candidate knows i, candidate cannot be the
        // celebrity, so i becomes the new candidate. Otherwise, i cannot be
        // the celebrity. This leaves only one possible candidate.
        int celebrity(vector<vector<int>>& mat) {
            int n = mat.size();
    
            int candidate = 0;
    
            // Find a possible celebrity
            for (int i = 1; i < n; i++) {
                if (mat[candidate][i] == 1) {
                    candidate = i;
                }
            }
    
            // Verify candidate
            for (int i = 0; i < n; i++) {
                if (i == candidate)
                    continue;
    
                // Celebrity knows nobody
                // Everyone must know celebrity
                if (mat[candidate][i] == 1 || mat[i][candidate] == 0)
                    return -1;
            }
    
            return candidate;
        }
    };


// Time complexity: O(n)
// Space complexity: O(1)