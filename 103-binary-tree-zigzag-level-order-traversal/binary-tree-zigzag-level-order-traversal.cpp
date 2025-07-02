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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL) return{};

        vector<vector<int>> res;
        int d = 0;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            int s = q.size();
            vector<int> temp;
            while(s--){
                TreeNode *x = q.front();
                temp.push_back(x->val);
                q.pop();
                if(x->left) q.push(x->left);
                if(x->right) q.push(x->right);
            }
            if(d){
                reverse(temp.begin(), temp.end());
            }
            d = 1 - d;
            res.push_back(temp);
        }
        return res;
    }   
};