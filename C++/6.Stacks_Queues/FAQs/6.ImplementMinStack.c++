// LeetCode Problem: 155. Min Stack
// Problem Link: https://leetcode.com/problems/min-stack/


// Each stack entry stores {value, minimum value up to this position}.
// This allows top() and getMin() to both run in constant time.
class MinStack {
    public:
        stack<pair<int, int>> st;
        MinStack() {
            
        }
        // Time complexity: O(1)
        
        void push(int value) {
            int curr_min = st.empty() ? INT_MAX : st.top().second;
            st.push({value, min(curr_min, value)});
        }
        // Time complexity: O(1)
        
        void pop() {
            st.pop();
        }
        // Time complexity: O(1)
        
        int top() {
            return st.top().first;
        }
        // Time complexity: O(1)
        
        int getMin() {
            return st.top().second;
        }
        // Time complexity: O(1)
    };

    // Overall space complexity: O(n), with one pair stored per element
    
    /**
     * Your MinStack object will be instantiated and called as such:
     * MinStack* obj = new MinStack();
     * obj->push(value);
     * obj->pop();
     * int param_3 = obj->top();
     * int param_4 = obj->getMin();
     */