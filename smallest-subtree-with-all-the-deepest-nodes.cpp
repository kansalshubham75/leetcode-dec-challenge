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
    pair<int,TreeNode*> helper(TreeNode* root){
        if(!root)return {0,NULL};
        auto left_depth=helper(root->left);
        auto right_depth=helper(root->right);
        int my_depth=max(left_depth.first,right_depth.first)+1;
        TreeNode* ret=NULL;
        if(left_depth.first==right_depth.first){
            ret=root;
        }else ret=left_depth>right_depth?left_depth.second:right_depth.second;
        return {my_depth,ret};
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return helper(root).second;
        
    }
};