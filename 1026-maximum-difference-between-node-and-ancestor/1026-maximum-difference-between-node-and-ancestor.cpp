class Solution {
public:
    void dfs(TreeNode* root, int minn, int maxx, int &res) {
        if(!root) return ;
        minn = min(minn, root->val);
        maxx = max(maxx, root->val);
        res = max(res, max(abs(root->val-minn), abs(root->val-maxx)));
        dfs(root->left, minn, maxx, res);
        dfs(root->right, minn, maxx, res);
    }
    
    int maxAncestorDiff(TreeNode* root) {
        int res = -1e6;
        dfs(root, root->val, root->val, res);
        return res;
    }
};