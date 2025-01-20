class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<vector<int>> cost(m, vector<int>(n, INT_MAX));
    deque<pair<int, int>> dq;
    
    dq.push_front({0, 0});
    cost[0][0] = 0;
    
    while (!dq.empty()) {
        auto [x, y] = dq.front();
        dq.pop_front();
        
        for (int d = 1; d <= 4; ++d) {
            int nx = x + directions[d - 1][0];
            int ny = y + directions[d - 1][1];
            
            if (nx >= 0 && ny >= 0 && nx < m && ny < n) {
                int newCost = cost[x][y] + (grid[x][y] == d ? 0 : 1);
                if (newCost < cost[nx][ny]) {
                    cost[nx][ny] = newCost;
                    if (grid[x][y] == d) {
                        dq.push_front({nx, ny});  
                    } else {
                        dq.push_back({nx, ny});  
                    }
                }
            }
        }
    }
    
    return cost[m - 1][n - 1];
    }
};