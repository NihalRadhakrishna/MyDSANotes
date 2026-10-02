// LeetCode Problem: 907. Sum of Subarray Minimums
// Problem Link: https://leetcode.com/problems/sum-of-subarray-minimums/


class Solution {
    public:
        // For every arr[i], find how many subarrays use it as their minimum.
        // Its contribution is arr[i] * left[i] * right[i].
        int sumSubarrayMins(vector<int>& arr) {
            int n = arr.size();
            vector<int> left(n), right(n);
            stack<int> st;
            for(int i = 0; i<n ;i++){
                // Use > on the left so an equal value remains as the boundary.
                // left[i] is the distance to the previous smaller-or-equal value.
                while(!st.empty() && arr[st.top()] > arr[i]){
                    st.pop();
                }
                left[i] = st.empty() ? i+1 : i-st.top();
                st.push(i);
            }
            while(!st.empty()){
                st.pop();
            }
    
            for(int i = n-1; i>=0; i--){
                // Use >= on the right so equal values are removed.
                // right[i] is the distance to the next strictly smaller value.
                // This asymmetric handling of duplicates assigns each subarray
                // to exactly one equal minimum instead of counting it twice.
                while(!st.empty() && arr[st.top()] >= arr[i]){
                    st.pop();
                }
                right[i] = st.empty() ? n-i: st.top()-i;
                st.push(i);
            }
            long long ans = 0;
            const int MOD = 1e9+7;
            for(int i = 0; i<n; i++){
                ans = (ans + (long long)arr[i] * left[i] * right[i])%MOD;
            }
            return ans;
        }
    };


// Time complexity: O(n), because each index is pushed and popped at most once
// Space complexity: O(n) for the stacks and distance arrays