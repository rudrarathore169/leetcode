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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>result;
          map<int, map<int, vector<int>>>nodemap;
        queue<pair<TreeNode*,pair<int,int>>>q;

        if(root!=NULL){
            q.push(make_pair(root,make_pair(0,0)));
        }
        else{
            return result;
        }
        while(!q.empty()){
            pair<TreeNode*,pair<int,int>>node = q.front();
            q.pop();
            TreeNode* temp = node.first;
            int hd = node.second.first;
            int lvl= node.second.second;
            nodemap[hd][lvl].push_back(temp->val);
            if(temp->left){
                q.push(make_pair(temp->left, make_pair(hd - 1, lvl + 1)));
            }
            if (temp->right) {
                q.push(make_pair(temp->right, make_pair(hd + 1, lvl + 1)));
            }
            
        }
       for (auto p : nodemap) {
            vector<int> column;
            for (auto q : p.second) {
                // Sort the vector to satisfy the vertical order requirement
                sort(q.second.begin(), q.second.end());
                column.insert(column.end(), q.second.begin(), q.second.end());
            }
            result.push_back(column);
        }
    return result;
    }
};