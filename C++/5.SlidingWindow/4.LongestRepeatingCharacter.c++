// LeetCode Problem: 424. Longest Repeating Character Replacement
// Problem Link: https://leetcode.com/problems/longest-repeating-character-replacement/


class Solution {
    public:
        // Sliding window: window size - highest character frequency gives
        // the number of replacements needed to make the window uniform.
        // Shrink the window whenever more than k replacements are required.
        int characterReplacement(string s, int k) {
            unordered_map<char, int> freq;
    
            int l = 0;
            int maxFreq = 0;
            int ans = 0;
    
            for (int r = 0; r < s.size(); r++) {
    
                freq[s[r]]++;
    
                maxFreq = max(maxFreq, freq[s[r]]);
    
                // Characters that need to be replaced
                int changes = (r - l + 1) - maxFreq;
    
                while (changes > k) {
                    freq[s[l]]--;
                    l++;
    
                    changes = (r - l + 1) - maxFreq;
                }
    
                ans = max(ans, r - l + 1);
            }
    
            return ans;
        }
    };


// Time complexity: O(n)
// Space complexity: O(1), because the alphabet contains only 26 letters