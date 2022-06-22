//Recursive
class Solution {
  public:
    // Function to return a list containing the inorder traversal of the tree.
    void fillinorder(Node* root,vector<int>& ans){
    if(root==NULL) return ;
    fillinorder(root->left,ans);
    ans.push_back(root->data);
    fillinorder(root->right,ans);
}
    vector <int> inOrder(Node* root)
    {
      // Your code here
      //left root right
      vector<int> ans;
      fillinorder(root,ans);
      return ans;
      
    }
};