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
    int dfs(TreeNode *node , int m){
        int r = 0;
        if(node == NULL){
            return 0;
        }
        if(node->val >= m){
            r = 1;
        }
        int t = max(m, node->val);
        return dfs(node->left, t) + dfs(node->right, t) + r;
    }
    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }
};