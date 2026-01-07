#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const long long MOD = 1000000007;

    void sums(TreeNode* head, long long& k) {
        if (head == NULL) return;

        sums(head->left, k);
        k += head->val;
        sums(head->right, k);
    }

  
    long long dfs(TreeNode* node, long long total, long long& ans) {
        if (!node) return 0;

        long long sub = dfs(node->left, total, ans)
                      + dfs(node->right, total, ans)
                      + node->val;

        ans = max(ans, sub * (total - sub));  
        return sub;
    }
   
    int maxProduct(TreeNode* root) {
        long long total = 0;
        sums(root, total);         

        long long ans = 0;
        dfs(root, total, ans);     
        return (int)(ans % MOD);    
    }
};
