// LeetCode Problem: 402. Remove K Digits
// Problem Link: https://leetcode.com/problems/remove-k-digits/


class Solution {
    public:
        // Maintain an increasing monotonic stack. When the current digit is
        // smaller than the stack top, removing the larger previous digit
        // produces the smallest possible number.
        string removeKdigits(string num, int k) {
            stack<char> st;
            int n = num.size();
            for(int i = 0; i<n; i++){
                while(!st.empty() && st.top() > num[i] && k>0){
                    st.pop();
                    k--;
                }
                st.push(num[i]);
            }

            // If digits are still left to remove, the number is already
            // non-decreasing, so remove the largest digits from the end.
            while(!st.empty() && k>0){
                st.pop();
                k--;
            }
            string ans = "";
            while(!st.empty()){
                ans += st.top();
                st.pop();
            }
            reverse(ans.begin(), ans.end());

            // Remove leading zeros from the final number.
            int pos = ans.find_first_not_of('0');
            if(pos == string::npos)
                return "0";
            
            
            return ans.substr(pos);
        }
    };


// Time complexity: O(n), because each digit is pushed and popped at most once
// Space complexity: O(n) for the stack and result string