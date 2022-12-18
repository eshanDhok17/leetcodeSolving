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
typedef long long ll;
class Solution {
public:
    ll ans = 0, tSum = 0;
    int maxProduct(TreeNode* root) {
        tSum = getSum(root);
        getSum(root);
        return ans % int(1e9+7);
    }
    int getSum(TreeNode* root) {
        if(!root) return 0;
        int sum = getSum(root->left) + getSum(root->right) + root->val;
        ans = max(ans, (tSum - sum) * sum);
        return sum;
    }
};