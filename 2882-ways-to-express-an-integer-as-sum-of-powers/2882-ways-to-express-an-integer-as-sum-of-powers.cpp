class Solution {
public:
    static const int MOD = 1e9 + 7;

    long long ipow(long long base, int exp) {
        long long res = 1;
        while (exp--) res *= base;
        return res;
    }

    int dfs(int rem, int curr, int x, vector<vector<int>>& dp) {
        if (rem == 0) return 1;   
        if (rem < 0 || curr == 0) return 0;

        if (dp[rem][curr] != -1) return dp[rem][curr]; 

        long long p = ipow(curr, x);

        int take = 0;
        if (p <= rem) take = dfs(rem - (int)p, curr - 1, x, dp);
        int skip = dfs(rem, curr - 1, x, dp);

        return dp[rem][curr] = (take + skip) % MOD;
    }

    int numberOfWays(int n, int x) {
        
        int maxNum = 0;
        while (ipow((long long)maxNum + 1, x) <= n) ++maxNum;

        vector<vector<int>> dp(n + 1, vector<int>(maxNum + 1, -1));
        return dfs(n, maxNum, x, dp);
    }
};
