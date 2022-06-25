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

//Iterative
class Solution {
  public:
    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node* node) {
        // Your code here
        vector<int> ans;
        stack<Node*> st;
        while(true){
            if(node!=NULL){
                st.push(node);
                node=node->left;
            }
            else{
                if(st.empty()) break;
                node=st.top();
                st.pop();
                ans.push_back(node->data);
                node=node->right;
            }
        }
        return ans;
    }
};