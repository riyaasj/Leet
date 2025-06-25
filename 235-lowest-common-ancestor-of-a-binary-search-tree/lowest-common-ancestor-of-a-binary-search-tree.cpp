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
    vector<TreeNode*> path(TreeNode* root, TreeNode* p){
        vector<TreeNode*> res;
        TreeNode *t = root;
        while(t->val != p->val){
            res.push_back(t);
            if(p->val < t->val){
                t = t->left;
            }
            else{
                t = t->right;
            }
        }
        res.push_back(p);
        return res;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> a = path(root, p), b = path(root, q);
        int i = 0;
        while(i < a.size() && i < b.size() && a[i] == b[i]){
            i++;
        }
        return a[i - 1];
    }
};