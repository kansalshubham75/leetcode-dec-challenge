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
    int helper(TreeNode* node,vector<int>& curr){
        if(!node)return 0;
        if(!node->left && !node->right){
            curr[node->val]++;
            int odd=0,even=0;
            for(int i:curr){
                if(i && i%2)odd++;
                else if(i && i%2==0)even++;
            }
            curr[node->val]--;
            return odd<=1;
        }
        curr[node->val]++;
        int l=helper(node->left,curr);
        int r=helper(node->right,curr);
        curr[node->val]--;
        return l+r;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> curr(10,0);
        return helper(root,curr);
    }
};