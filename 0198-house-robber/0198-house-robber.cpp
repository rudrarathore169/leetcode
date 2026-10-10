class Solution {
public:
    int solve(vector<int>& nums, vector<int>&dp, int k){
        if(k<0){
            return 0;
        }
        if(dp[k]!=-1){
            return dp[k];
        }

        int inc =  nums[k]+solve(nums,dp,k-2);
        int exc =  solve(nums,dp,k-1);
        dp[k]  = max(inc,exc);
        return dp[k];
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        int ans =  solve(nums,dp,nums.size()-1);
        return ans;
    }
};