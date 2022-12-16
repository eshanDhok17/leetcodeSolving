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
private:
    bool check(TreeNode* &r, long mx, long mn) {
        if(!r) return true;
        if(r->val >= mx or r->val <= mn) return false;
        return check(r->left, r->val, mn) and check(r->right, mx, r->val);
    }
public:
    bool isValidBST(TreeNode* &root) {
        return check(root, LONG_MAX, LONG_MIN);
    }
};