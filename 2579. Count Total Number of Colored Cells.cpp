class Solution {
    public:
        long long coloredCells(int n) {
            long long ans=2ll*n*n - 2ll*n +1;
            return ans;
        }
    };