// LeetCode Problem: 76. Minimum Window Substring
// Problem Link: https://leetcode.com/problems/minimum-window-substring/


class Solution {
    public:
        // Sliding window: expand the right boundary until the window contains
        // every character required by t, including duplicate occurrences.
        // Then shrink from the left to find the smallest valid window.
        string minWindow(string s, string t) {
            vector<int> need(128, 0);
            vector<int> window(128, 0);
    
            for (char c : t) {
                need[c]++;
            }
    
            int required = t.size();
            int curr = 0;
    
            int l = 0;
            int minLen = INT_MAX;
            int start = 0;
    
            for (int r = 0; r < s.size(); r++) {
    
                window[s[r]]++;
    
                if (window[s[r]] <= need[s[r]]) {
                    curr++;
                }
    
                while (curr == required) {
    
                    if (r - l + 1 < minLen) {
                        minLen = r - l + 1;
                        start = l;
                    }
    
                    window[s[l]]--;
    
                    if (window[s[l]] < need[s[l]]) {
                        curr--;
                    }
    
                    l++;
                }
            }
    
            if (minLen == INT_MAX) {
                return "";
            }
    
            return s.substr(start, minLen);
        }
    };


// Time complexity: O(|s| + |t|)
// Space complexity: O(1), because both frequency arrays have a fixed size of 128