class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        if (m == 0) return 0;
        int n = heightMap[0].size();
        if (n == 0) return 0;

       
        priority_queue<vector<int>, vector<vector<int>>, greater<>> minHeap;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

      
        for (int i = 0; i < m; ++i) {
            for (int j : {0, n - 1}) {
                minHeap.push({heightMap[i][j], i, j});
                visited[i][j] = true;
            }
        }
        for (int j = 1; j < n - 1; ++j) {
            for (int i : {0, m - 1}) {
                minHeap.push({heightMap[i][j], i, j});
                visited[i][j] = true;
            }
        }

        
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int waterTrapped = 0;

     
        while (!minHeap.empty()) {
            auto cell = minHeap.top();
            minHeap.pop();
            int height = cell[0], x = cell[1], y = cell[2];

            
            for (auto& dir : directions) {
                int nx = x + dir.first, ny = y + dir.second;
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    
                    waterTrapped += max(0, height - heightMap[nx][ny]);
                    
                    minHeap.push({max(height, heightMap[nx][ny]), nx, ny});
                }
            }
        }

        return waterTrapped;
    }
};