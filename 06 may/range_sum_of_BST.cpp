// Given the root node of a binary search tree and two integers low and high, return the sum of values of all nodes with a value in the inclusive range [low, high].
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
    //This solution is taking advantage of the tree being BST
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root==NULL){
            return 0;
        }
        int ans=root -> val >= low && root -> val <= high ? root -> val : 0;
        if(root->val > low){
            ans+= rangeSumBST(root->left,low,high);
        }
        if(root->val < high){
            ans+= rangeSumBST(root->right,low,high);
        }
        return ans;
        
    }
};