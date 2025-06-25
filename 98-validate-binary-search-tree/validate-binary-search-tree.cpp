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
    bool h(TreeNode* root, long largest, long smallest){
        if(root == NULL){
            return true;
        }
        if(root->val >= largest || root->val <= smallest){
            return false;
        }
        return h(root->left, root->val, smallest) && h(root->right, largest, root->val);
    }
    
    bool isValidBST(TreeNode* root) {
        return h(root, LONG_MAX, LONG_MIN);
    }
};