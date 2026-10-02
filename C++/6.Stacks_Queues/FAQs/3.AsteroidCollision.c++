// LeetCode Problem: 735. Asteroid Collision
// Problem Link: https://leetcode.com/problems/asteroid-collision/


class Solution {
    public:
        // Use a stack to store surviving asteroids. A collision is possible
        // only when the stack top moves right and the current asteroid moves
        // left. Remove smaller asteroids until the collision is resolved.
        vector<int> asteroidCollision(vector<int>& asteroids) {
            vector<int> st;
    
            for (int x : asteroids) {
    
                // Current asteroid moving left
                while (!st.empty() && x < 0 && st.back() > 0 && 
                       st.back() < -x) {
                    st.pop_back();
                }
    
                // Both asteroids have same size -> both explode
                if (!st.empty() && x < 0 && st.back() == -x) {
                    st.pop_back();
                }
                // Current asteroid survives
                else if (st.empty() || x > 0 || st.back() < 0) {
                    st.push_back(x);
                }
            }
    
            return st;
        }
    };


// Time complexity: O(n), because each asteroid is pushed and popped at most once
// Space complexity: O(n) for the stack of surviving asteroids