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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode *n = new TreeNode(val);
        if(root == NULL){
            return n;
        }
        TreeNode* x = root, *y;
        while(x != NULL){
            y = x;
            if(val > x->val){
                x = x->right;
            }
            else{
                x = x->left;
            }
        }
        if(val > y->val){
            y->right = n;
        }
        else{
            y->left = n;
        }
        return root;
    }
};