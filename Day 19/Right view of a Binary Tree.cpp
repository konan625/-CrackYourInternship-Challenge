class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    vector<vector<int>> levelordertraversal(Node* root){
    if(root==NULL) return {};
    queue<Node*> q;
    q.push(root);
    vector<vector<int>> ans;
    while(!q.empty()){
        vector<int> c;
        int l=q.size();
        for(int i=0;i<l;i++){
            Node* node=q.front();
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
            c.push_back(node->data);
            q.pop();
        }
        ans.push_back(c);
    }
    return ans;
}
    vector<int> rightView(Node *root)
    {
       // Your Code here
       vector<vector<int>> v=levelordertraversal(root);
       vector<int> ans;
       for(int i=0;i<v.size();i++){
           int j=v[i].size();
           ans.push_back(v[i][j-1]);
       }
       return ans;
    }
};