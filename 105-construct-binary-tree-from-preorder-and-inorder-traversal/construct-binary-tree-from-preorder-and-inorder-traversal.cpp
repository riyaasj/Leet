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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int &p, int is, int ie){
        if(is < 0 || ie >= inorder.size() || is > ie){
            return NULL;
        }
        int val = preorder[p], i;
        for(i = is; i <= ie; i++){
            if(inorder[i] == val){
                break;
            }
        }
        p++;
        TreeNode* node = new TreeNode(val, build(preorder, inorder, p, is, i - 1), build(preorder, inorder, p, i + 1, ie));
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int p = 0;
        return build(preorder, inorder, p, 0, inorder.size() - 1);
    }
};