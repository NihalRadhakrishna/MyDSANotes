// LeetCode Problem: 503. Next Greater Element II
// Problem Link: https://leetcode.com/problems/next-greater-element-ii/


class Solution {
    public:
        // Traverse the array twice from right to left to simulate a circular
        // array. The modulo operator maps each index back into the array.
        // A decreasing monotonic stack keeps possible next greater elements.
        vector<int> nextGreaterElements(vector<int>& nums) {
            int n = nums.size();
            stack<int> st;
            vector<int> ans(n,-1);
            for(int i = 2*n-1; i>=0; i--){
                int curr = nums[i%n];
                while(!st.empty() && st.top() <= curr){
                    st.pop();
                }
                if(i < n && !st.empty()){
                    ans[i] = st.top();
                }
                st.push(curr);
            }
            return ans;
        }
    };


// Time complexity: O(n), because each value is pushed and popped at most twice
// Space complexity: O(n), excluding the returned array