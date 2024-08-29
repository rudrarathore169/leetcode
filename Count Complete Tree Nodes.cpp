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
    void counting(TreeNode* root,int& ans){
        if(root==NULL){
            return;
        }
       else{
        ans++;
       }
        counting(root->left,ans);
        counting(root->right,ans);
    }
    int countNodes(TreeNode* root) {
        int ans=0;
        counting(root,ans);
        return ans;
    }
};