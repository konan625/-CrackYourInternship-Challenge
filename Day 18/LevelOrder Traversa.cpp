class Solution
{
    public:
    //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* node)
    {
      //Your code here
      queue<Node*> q;
      q.push(node);
      vector<int> ans;
      while(!q.empty()){ //O(height of tree) so O(1)
          int l=q.size();
          for(int i=0;i<l;i++){ // TC: O(n) cz we are traversing each and every node , SC: O(N)
              Node* temp=q.front();
              if(temp->left) q.push(temp->left);
              if(temp->right) q.push(temp->right);
              ans.push_back(temp->data);
              q.pop();
          }
      }
      return ans;
    }
};