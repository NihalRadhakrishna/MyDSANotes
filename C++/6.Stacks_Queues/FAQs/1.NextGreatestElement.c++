// LeetCode Problem: 496. Next Greater Element I
// Problem Link: https://leetcode.com/problems/next-greater-element-i/


class Solution {
    public:
        // Traverse nums2 from right to left using a decreasing monotonic stack.
        // Remove values that cannot be the next greater element. The remaining
        // stack top is the nearest greater value to the right.
        vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
            unordered_map<int, int> mp;
            stack<int> st;
            for(int i = nums2.size()-1; i>=0; i--){
                while(!st.empty() && st.top() <= nums2[i]){
                    st.pop();
                }
                if(st.empty()){
                    mp[nums2[i]] = -1;
                }
                else{
                    mp[nums2[i]] = st.top();
                }
                st.push(nums2[i]);
    
            }
            vector<int> ans;
            for(int x: nums1){
                ans.push_back(mp[x]);
            }
            return ans;
        }
    };


// Time complexity: O(n + m)
// Space complexity: O(n), excluding the returned array
// Here, n is nums2.size() and m is nums1.size().