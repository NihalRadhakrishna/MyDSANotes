// Array-based stack
// The end of the vector represents the top of the stack.
// Elements follow LIFO order: the last element pushed is removed first.
class myStack {
    public:
        int sz;
        vector<int> v;
    
        myStack(int n) {
            sz = n;
        }
        // Time complexity: O(1)
    
        bool isEmpty() {
            return v.empty();
        }
        // Time complexity: O(1)
    
        bool isFull() {
            return v.size() == sz;
        }
        // Time complexity: O(1)
    
        void push(int x) {
            if (!isFull()) {
                v.push_back(x);
            }
        }
        // Time complexity: O(1) amortized; O(n) if the vector reallocates
    
        void pop() {
            if (!isEmpty()) {
                v.pop_back();
            }
        }
        // Time complexity: O(1)
    
        int peek() {
            if (!isEmpty()) {
                return v.back();
            }
            return -1;
        }
        // Time complexity: O(1)
    };


// Overall space complexity: O(n), where n is the stack capacity