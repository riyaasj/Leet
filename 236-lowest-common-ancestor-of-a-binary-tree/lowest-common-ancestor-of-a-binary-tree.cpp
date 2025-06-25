/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* search(TreeNode* root, int p, int q){
        if(root == NULL){
            return NULL;
        }
        if(root->val == p || root->val == q){
            return root;
        }
        TreeNode *a = search(root->left, p, q), *b = search(root->right, p, q);
        if(a == NULL && b == NULL){
            return NULL;
        }
        if(a != NULL && b != NULL){
            return root;
        }
        if(a != NULL){
            return a;
        }
        return b;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return search(root, p->val, q->val);
    }
};