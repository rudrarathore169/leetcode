class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> ans(n, vector<int>(m, -1));
        queue<pair<int, int>> q;

        // Step 1: Push all zero cells into the queue and mark them as distance 0
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j){
                if (mat[i][j] == 0) {
                    ans[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        // Step 2: BFS from all 0s
        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int dir = 0; dir < 4; ++dir) {
                int newX = x + dx[dir];
                int newY = y + dy[dir];

                if (newX >= 0 && newX < n && newY >= 0 && newY < m && ans[newX][newY] == -1) {
                    ans[newX][newY] = ans[x][y] + 1;
                    q.push({newX, newY});
                }
            }
        }

        return ans;
    }
};
