class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, 0);
        vector<int> result;

       
        function<bool(int)> dfs = [&](int node) {
            if (color[node] != 0) 
                return color[node] == 2; 
            
            color[node] = 1; 
            for (int neighbor : graph[node]) {
                if (color[neighbor] == 1 || !dfs(neighbor)) 
                    return false;
            }
            color[node] = 2; 
            return true;
        };

       
        for (int i = 0; i < n; i++) {
            if (dfs(i)) {
                result.push_back(i);
            }
        }

        return result;
    }
};
