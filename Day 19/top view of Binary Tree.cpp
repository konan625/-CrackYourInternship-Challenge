class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        if(root==NULL) return {};
        queue<pair<Node*,int>> q;
        map<int,int> m;
        q.push(make_pair(root,0));
        while(!q.empty()){
            Node* node=q.front().first;
            int col=q.front().second;
            if(m[col]==0){
                m[col]=node->data;
            }
            if(node->left){
                q.push(make_pair(node->left,col-1));
            }
            if(node->right){
                q.push(make_pair(node->right,col+1));
            }
            q.pop();
        }
        vector<int> ans;
        for(auto it=m.begin();it!=m.end();it++){
            ans.push_back(it->second);
        }
        return ans;
    }

};