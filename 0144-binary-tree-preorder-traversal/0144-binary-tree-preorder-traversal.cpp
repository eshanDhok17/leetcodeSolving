class Solution {
public:
    vector<int> v;
    void f(TreeNode* node) {
        if(!node) return ;
        v.push_back(node->val);
        f(node->left);
        f(node->right);
        return ;
    }
    vector<int> preorderTraversal(TreeNode* &root) {
        f(root);
        return v;
    }
};