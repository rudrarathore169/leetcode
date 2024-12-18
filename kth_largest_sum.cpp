/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
       priority_queue<long long, vector<long long>, greater<long long>> minHeap;
        queue<TreeNode*> q;
        q.push(root);

        // BFS traversal to compute level sums
        while (!q.empty()) {
            int n = q.size();
            long long levelSum = 0; // Use long long to avoid overflow for large values

            // Sum the values at the current level
            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();
                levelSum += node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            // Maintain a heap of the largest k sums
            minHeap.push(levelSum);
            if (minHeap.size() > k) {
                minHeap.pop(); // Remove the smallest element if heap size exceeds k
            }
        }

        
        return minHeap.size() == k ? minHeap.top() : -1; 
    }
};