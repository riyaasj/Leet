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
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *t = root;
        while(t){
            if(p->val < t->val && q->val < t->val){
                t = t->left;
            }
            else if(p->val > t->val && q->val > t->val){
                t = t->right;
            }
            else{
                return t;
            }
        }
        return NULL;
    }
};