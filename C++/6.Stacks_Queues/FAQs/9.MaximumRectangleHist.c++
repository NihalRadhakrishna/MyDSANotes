// LeetCode Problem: 84. Largest Rectangle in Histogram
// Problem Link: https://leetcode.com/problems/largest-rectangle-in-histogram/


class Solution {
    public:
        // Maintain indices of bars in increasing height order. When a smaller
        // bar is found, pop taller bars and calculate the largest rectangle
        // for which each popped bar is the limiting height.
        int largestRectangleArea(vector<int>& heights) {
            stack<int> st;
            int ans = 0;
            int n = heights.size();
    
            for (int i = 0; i <= n; i++) {
    
                // The extra height 0 at i == n flushes all remaining bars.
                int curr = (i == n) ? 0 : heights[i];
    
                while (!st.empty() && heights[st.top()] > curr) {
                    int h = heights[st.top()];
                    st.pop();
    
                    // After popping, i is the first smaller bar on the right,
                    // and left is the first smaller bar on the left.
                    int left = st.empty() ? -1 : st.top();
                    int width = i - left - 1;
    
                    ans = max(ans, h * width);
                }
    
                st.push(i);
            }
    
            return ans;
        }
    };


// Time complexity: O(n), because each index is pushed and popped at most once
// Space complexity: O(n) for the monotonic stack