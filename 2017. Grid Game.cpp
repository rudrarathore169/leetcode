class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
   long long totalTop = 0, totalBottom = 0;
        int m = grid[0].size();

        for (int i = 0; i < m; i++) {
            totalTop += grid[0][i];
        }

        long long result = LLONG_MAX;

       
        for (int i = 0; i < m; i++) {
            totalTop -= grid[0][i];
            result = min(result, max(totalTop, totalBottom));
            totalBottom += grid[1][i]; 
        }

        return result;
    }
};