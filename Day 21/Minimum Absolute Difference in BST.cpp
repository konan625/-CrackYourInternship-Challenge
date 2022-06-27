Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two different nodes in the tree.
class Solution {
public:
    void inorder(TreeNode* root,vector<int>& traversal){
        if(root==NULL) return;
        inorder(root->left,traversal);
        traversal.push_back(root->val);
        inorder(root->right,traversal);
    }
    int getMinimumDifference(TreeNode* root) {
        vector<int> traverse;
        inorder(root,traverse);
        int mn=INT_MAX;
        for(int i=0;i<traverse.size()-1;i++){
            mn=min(mn,abs(traverse[i]-traverse[i+1]));
        }
        return mn;
        
    }
};

//Simpler code
class Solution {
public:
    int prev=-1;
    int ans=INT_MAX;
    int getMinimumDifference(TreeNode* root) {
        if(root==NULL) return 0;
        getMinimumDifference(root->left);
        if(prev!=-1){
            ans=min(ans,root->val - prev);
        }
        prev=root->val;
        getMinimumDifference(root->right);
        return ans;
        
    }
};