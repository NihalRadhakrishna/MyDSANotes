// LeetCode Problem: 904. Fruit Into Baskets
// Problem Link: https://leetcode.com/problems/fruit-into-baskets/


class Solution {
    public:
        // Sliding window: keep at most two distinct fruit types.
        // Shrink the window from the left whenever a third type is added.
        int totalFruit(vector<int>& fruits) {
            map<int, int> mp;
            int curr = 0;
            int l = 0;
            int ans = 0;
            for(int i = 0; i<fruits.size(); i++){
                mp[fruits[i]]++;
                curr++;
                if(mp.size() > 2){
                    while(mp.size() > 2){
                        mp[fruits[l]]--;
                        curr--;
                        if(mp[fruits[l]] == 0){
                            mp.erase(fruits[l]);
                        }
                        l++;
                    }
                }
                ans = max(ans, curr);
            }
            return ans;
        }
    };


// Time complexity: O(n)
// Space complexity: O(1), because the map stores at most three fruit types