class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> tree(n);
        for (auto& edge : edges) {
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }
        
        int maxComponentsCount = 0;

        
        function<long long(int, int)> dfs = [&](int node, int parent) {
            long long subtreeSum = values[node]; 
            for (int neighbor : tree[node]) {
                if (neighbor != parent) {
                    long long childSum = dfs(neighbor, node);
                    
                    if (childSum % k == 0) {
                        maxComponentsCount++;
                    } else {
                        subtreeSum += childSum;
                    }
                }
            }
            return subtreeSum;
        };

        
        long long totalSum = dfs(0, -1);

        
        if (totalSum % k == 0) {
            maxComponentsCount++;
        }

        return maxComponentsCount;
    }
};