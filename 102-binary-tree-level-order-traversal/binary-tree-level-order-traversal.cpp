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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL){
            return {};
        }
        vector<vector<int>> res;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            int t = q.size();
            vector<int> temp;
            while(t--){
                TreeNode *x = q.front();
                q.pop();
                temp.push_back(x->val);
                if(x->left) q.push(x->left);
                if(x->right) q.push(x->right);
            }
            res.push_back(temp);
        }
        return res;
    }
};