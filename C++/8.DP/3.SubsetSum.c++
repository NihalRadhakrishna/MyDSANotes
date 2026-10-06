class Solution {
    public:
        bool canPartition(vector<int>& nums) {
            int n = nums.size();
            int sum = 0;
            for(int i : nums){
                sum+=i;
            }
            if(sum%2) return false;
            sum = sum/2;
            vector<vector<int>> dp(n+1, vector<int>(sum+1, 0));
            dp[0][0] = 1;
            for(int i =1; i<=n; i++){
                for(int j = 0; j<=sum; j++){
                    if(j<nums[i-1]){
                        dp[i][j] = dp[i-1][j];
                    }
                    else{
                        dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]]; 
                    }
                }
            }
            return dp[n][sum];
        }
    };
    