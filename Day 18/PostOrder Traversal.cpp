//Recursive
void fillpostorder(Node* root,vector<int>& ans){
    if(root==NULL) return;
    fillpostorder(root->left,ans);
    fillpostorder(root->right,ans);
    ans.push_back(root->data);
    
}
vector <int> postOrder(Node* root)
{
  // Your code here
  //left right root
  vector<int> ans;
  fillpostorder(root,ans);
  return ans;
}