// LeetCode Problem: 1423. Maximum Points You Can Obtain from Cards
// Problem Link: https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/


class Solution {
    public:
        // Sliding-window approach
        int maxScore(vector<int>& cardPoints, int k) {
            int n = cardPoints.size();
            int ws = n - k;
    
            int total = 0;
            for(int x: cardPoints){
                total+=x;
            }
    
            if(ws == 0){
                return total;
            }
    
            int wsum = 0;
            for(int i = 0; i<ws; i++){
                wsum += cardPoints[i];
            }
            int minwindow = wsum;
            for(int i = ws; i<n; i++){
                wsum += cardPoints[i];
                wsum -= cardPoints[i-ws];
                minwindow = min(minwindow, wsum);
            }
    
            return total - minwindow;
        }

        // Recursive approach: at each step, choose either the leftmost
        // or rightmost card and return the better of the two choices.
        int solve(vector<int>& cardPoints, int left, int right, int k) {
            if(k == 0){
                return 0;
            }

            int takeLeft = cardPoints[left]
                + solve(cardPoints, left + 1, right, k - 1);
            int takeRight = cardPoints[right]
                + solve(cardPoints, left, right - 1, k - 1);

            return max(takeLeft, takeRight);
        }

        int maxScoreRecursive(vector<int>& cardPoints, int k) {
            return solve(cardPoints, 0, cardPoints.size() - 1, k);
        }
    };


// Sliding-window approach:
// Time complexity: O(n)
// Space complexity: O(1)

// Recursive approach:
// Time complexity: O(2^k)
// Space complexity: O(k) for the recursive call stack