//Recursive
void fillpreorder(Node* root,vector<int>& ans){
    if(root==NULL) return ;
    ans.push_back(root->data);
    fillpreorder(root->left,ans);
    fillpreorder(root->right,ans);
}
vector <int> preorder(Node* root)
{
  // Your code here
  //root left right
  vector<int> ans;
  fillpreorder(root,ans);
  return ans;
  
}

//Iterative
vector <int> preorder(Node* root)
{
  // Your code here
   vector<int> ans;
  if(root==NULL) return ans ;
  stack<Node*> st;
  st.push(root);
  while(!st.empty()){
      Node* temp=st.top();
      st.pop();
      ans.push_back(temp->data);
      if(temp->right){
          st.push(temp->right);
      }
      if(temp->left){
          st.push(temp->left);
      }
      
  }
  return ans;
  
}