//Back-end complete function Template for C++

class Solution {
  public:
     int solve(vector<int>& cost,int n,vector<int>&dp){
        
        if(n==0||n==1){
            dp[n]=cost[n];
        }
        else if(dp[n]==-1){
           dp[n]=min(solve(cost,n-1,dp),solve(cost,n-2,dp))+cost[n];
        }
        return dp[n];
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        // Write your code here
        
        vector<int>dp(cost.size()+1);
        for(int i=0;i<dp.size();i++){
            dp[i]=-1;
        }
        int ans = min(solve(cost,cost.size()-1,dp),solve(cost,cost.size()-2,dp));
        return ans;
        
        
    }
};