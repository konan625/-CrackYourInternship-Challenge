Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.

A leaf is a node with no children.
class Solution {
public:
    bool helper(TreeNode* root,int currsum,int targetSum){
         if(root==NULL) {
             return false;
         }
        currsum+=root->val;
        if(!root->left && !root->right){
            return targetSum==currsum;
        }
        bool left=helper(root->left,currsum,targetSum);
        bool right=helper(root->right,currsum,targetSum);
        return left || right;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL)return false;
        return helper(root,0,targetSum); 
    }
};

//simpler code
bool hasPathSum(TreeNode *root, int sum) {
        if (root == NULL) return false;
        if (root->val == sum && root->left ==  NULL && root->right == NULL) return true;
        return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
    }