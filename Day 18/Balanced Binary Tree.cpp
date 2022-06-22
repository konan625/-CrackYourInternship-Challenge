Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the left and right subtrees of every node differ in height by no more than 1.

//Brute O(N2)
class Solution {
public:
    int height(TreeNode *root){
    if(root==NULL){
        return 0;
    }
    return 1+max(height(root->left),height(root->right));
}
    bool isBalanced(TreeNode* root) {
            bool ans=false;;
            if(root==NULL){
                return true;
            }
            int hl=height(root->left);
            int hr=height(root->right);
            bool left=isBalanced(root->left);
            bool right=isBalanced(root->right);
            if(abs(hl-hr)<=1 && left && right){
                ans=true;
            }
            return ans;
        
    }
};

//Optimised O(N)
class Solution {
public:
    int height(TreeNode* root){
        if(root==NULL) return 0;
        int l=height(root->left);
        int r=height(root->right);
        if(l==-1 || r==-1) return -1;
        if(abs(l-r)>1) return -1;
        return 1+max(l, r);
    }
    bool isBalanced(TreeNode* root) {
        return height(root)!=-1;
        
    }
};