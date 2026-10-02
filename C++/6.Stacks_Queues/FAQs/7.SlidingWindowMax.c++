// LeetCode Problem: 239. Sliding Window Maximum
// Problem Link: https://leetcode.com/problems/sliding-window-maximum/


class Solution {
    public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            // Approach 1: Multiset
            // Keep all k window elements in descending order. The first
            // element is always the maximum.
            // Time complexity: O(n log k)
            // Space complexity: O(k), excluding the returned array
            // vector<int> ans;
            // multiset<int, greater<int>> s;
            // for(int i = 0; i<k; i++){
            //     s.insert(nums[i]);
            // }
            // ans.push_back(*s.begin());
            // for(int i = k; i<nums.size(); i++){
            //     s.erase(s.lower_bound(nums[i-k]));
            //     s.insert(nums[i]);
            //     ans.push_back(*s.begin());
            // }
            // return ans;

            // Approach 2: Monotonic deque
            // Store indices in decreasing order of their values. Remove an
            // index from the front when it leaves the window, and remove
            // smaller values from the back because they can never be maximum.
            vector<int> ans;
            deque<int> q;
            for(int i = 0; i<k; i++){
                while(!q.empty() && nums[q.back()] < nums[i]){
                    q.pop_back();
                }
                q.push_back(i);
            }
            ans.push_back(nums[q.front()]);
            for(int i = k; i<nums.size(); i++){
                if(q.front() == i-k){
                    q.pop_front();
                }
                while(!q.empty() && nums[q.back()] < nums[i]){
                    q.pop_back();
                }
                q.push_back(i);
                ans.push_back(nums[q.front()]);
            }
            return ans;
        }
    };


// Monotonic-deque time complexity: O(n)
// Monotonic-deque space complexity: O(k), excluding the returned array