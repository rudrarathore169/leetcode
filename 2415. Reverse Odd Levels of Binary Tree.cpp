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
    TreeNode* reverseOddLevels(TreeNode* root) {
        int count=0;
        queue<TreeNode*>q;
        q.push(root);
        while(q.size()){
            vector<TreeNode*>rev;
            int n = q.size();
            for(int i=0;i<n;i++){
                if(count%2==0){
                    TreeNode* front = q.front();
                    q.pop();
                    if(front->left){
                        q.push(front->left);
                    }
                    if(front->right){
                        q.push(front->right);
                    }
                }
                else{
                    TreeNode* front = q.front();
                    q.pop();
                    rev.push_back(front);
                    if(front->left){
                        q.push(front->left);
                    }
                    if(front->right){
                        q.push(front->right);
                    }
                }
            }
            if(rev.size()){
                int s=0,e = rev.size()-1;
                while(s<=e){
                    swap(rev[s]->val,rev[e]->val);
                    s++;
                    e--;
                }
            }
            count++;
            rev.clear();
        }
        return root;
    }
};