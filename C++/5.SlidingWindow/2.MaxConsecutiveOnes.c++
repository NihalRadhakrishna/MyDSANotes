// LeetCode Problem: 1004. Max Consecutive Ones III
// Problem Link: https://leetcode.com/problems/max-consecutive-ones-iii/


class Solution {
    public:
        // Sliding window: expand the right boundary and count zeros.
        // If the window contains more than k zeros, shrink it from the left.
        int longestOnes(vector<int>& nums, int k) {
            int n = nums.size();
            int l = 0;
            int curr = 0;
            int ans = 0;
            for(int r = 0; r<n; r++){
                if(nums[r] == 0){
                    curr+=1;
                }
                while(curr > k){
                    if(nums[l] == 0){
                        curr-=1;
                    }
                    l+=1;
                }
                ans = max(ans, r-l+1);
            }
            return ans;
        }
    };


// Time complexity: O(n)
// Space complexity: O(1)