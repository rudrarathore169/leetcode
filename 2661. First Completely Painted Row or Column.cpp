class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
    int n = mat[0].size();

    unordered_map<int, pair<int, int>> cellToPosition;
    for (int r = 0; r < m; ++r) {
        for (int c = 0; c < n; ++c) {
            cellToPosition[mat[r][c]] = {r, c};
        }
    }

 
    vector<int> rowPainted(m, 0);
    vector<int> colPainted(n, 0);

    for (int i = 0; i < arr.size(); ++i) {
        int num = arr[i];
        auto [r, c] = cellToPosition[num];

        rowPainted[r]++;
        colPainted[c]++;

        if (rowPainted[r] == n || colPainted[c] == m) {
            return i;
        }
    }

    return -1; 
    }
};