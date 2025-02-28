class Solution {
    public:
        int lenLongestFibSubseq(vector<int>& arr) {
            int n=arr.size(), ans=0;
            vector<vector<int>> dp(n+1,vector<int>(n+1,2));
            for(int i=0; i<n; i++)
            {
                int start=0, end=i-1;
                while(start<end)
                {
                    int sum=arr[start]+arr[end];
                    if(sum>arr[i]) end--;
                    else if(sum<arr[i]) start++;
                    else
                    {
                        dp[end][i]=1+dp[start][end];
                        ans=max(ans,dp[end][i]);
                        start++; end--;
                    }
                }
            }
            return ans>2?ans:0;
        }
    };