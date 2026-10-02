// LeetCode Problem: 42. Trapping Rain Water
// Problem Link: https://leetcode.com/problems/trapping-rain-water/


class Solution {
    public:
        // Two-pointer approach: process the side with the smaller height.
        // If height[left] <= height[right], the right side is high enough to
        // form a boundary, so water at left depends only on leftMax.
        // Otherwise, water at right depends only on rightMax.
        int trap(vector<int>& height) {
            int left = 0;
            int right = height.size() - 1;
    
            int leftMax = 0;
            int rightMax = 0;
            int ans = 0;
    
            while(left <= right) {
    
                if(height[left] <= height[right]) {
    
                    if(height[left] >= leftMax)
                        leftMax = height[left];
                    else
                        ans += leftMax - height[left];
    
                    left++;
                }
                else {
    
                    if(height[right] >= rightMax)
                        rightMax = height[right];
                    else
                        ans += rightMax - height[right];
    
                    right--;
                }
            }
    
            return ans;
        }
    };


// Time complexity: O(n)
// Space complexity: O(1)