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
    pair<TreeNode*,TreeNode*> helper(TreeNode* root){
        if(!root)return {NULL,NULL};
        if(!root->left && !root->right)return {root,root};
        auto left_ret=helper(root->left);
        auto right_ret=helper(root->right);
        TreeNode* left_tail=left_ret.second;
        TreeNode* right_tail=right_ret.second;
        root->left=left_ret.first;
        root->right=right_ret.first;
        if(left_tail){
            TreeNode* my_left=root->left;
            root->left=NULL;
            left_tail->right=root;
            TreeNode* tail=right_tail?right_tail:root;
            return {my_left,tail};
        }
        return {root,right_tail};
    }
    TreeNode* increasingBST(TreeNode* root) {
        return helper(root).first;
    }
};