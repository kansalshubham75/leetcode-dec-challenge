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
    class info{
        public:
        int min_;
        int max_;
        bool isBst;
        info(int min_,int max_,bool isBst){
            this->min_=min_;
            this->max_=max_;
            this->isBst=isBst;
        }
    };
    info helper(TreeNode* root){
        int my_min=root->val,my_max=root->val,isBst=1;
        if(root->left){
            info ret=helper(root->left);
            isBst&=ret.isBst;
            if(ret.max_>=root->val)isBst=0;
            my_min=ret.min_;
        }
        if(root->right){
            info ret=helper(root->right);
            isBst&=ret.isBst;
            if(ret.min_<=root->val)isBst=0;
            my_max=ret.max_;
        }
        return info(my_min,my_max,isBst);
    }
    bool isValidBST(TreeNode* root) {
        if(!root)return 1;
        return helper(root).isBst;
    }
};