//O(N2)
class Solution {
  public:
    // Function to return the diameter of a Binary Tree.
    int height(Node* root){
        if(!root) return 0;
        return 1+max(height(root->left),height(root->right));
    }
    int diameter(Node* root) {
        // Your code here
        if(root==NULL) return 0;
        int lh=height(root->left);
        int rh=height(root->right);
        int ld=diameter(root->left);
        int rd=diameter(root->right);
        return max(ld,max(rd,1+lh+rh));
        
        
    }
};

//O(N)
class Solution {
  public:
    // Function to return the diameter of a Binary Tree.
    int height(Node* root,int& mx){
        if(!root) return 0;
        int lh=height(root->left,mx);
        int rh=height(root->right,mx);
        mx=max(mx,1+lh+rh);
        return 1+max(lh,rh);
    }
    int diameter(Node* root) {
        // Your code here
        int ans=0;
        height(root,ans);
        return ans;
    }
};