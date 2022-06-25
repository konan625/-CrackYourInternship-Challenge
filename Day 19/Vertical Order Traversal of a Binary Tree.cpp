/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

 //best STRIVER
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,priority_queue <int, vector<int>, greater<int>>>> m;
        if(root==NULL) return {{}};
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push(make_pair(root,make_pair(0,0)));
        while(!q.empty()){
            int l=q.size();
            for(int i=0;i<l;i++){
                TreeNode* node=q.front().first;
                int vertical=q.front().second.first;
                int level=q.front().second.second;
                m[vertical][level].push(node->val);
                if(node->left){
                    q.push(make_pair(node->left,make_pair(vertical-1,level+1)));
                }
                if(node->right){
                    q.push(make_pair(node->right,make_pair(vertical+1,level+1)));
                }
                q.pop();
            }
        }
        vector<vector<int>> ans;
        for(auto it=m.begin();it!=m.end();it++){
            vector<int> temp;
            for(auto it2=it->second.begin();it2!=it->second.end();it2++){
                while((it2->second).size()!=0){
                    temp.push_back(it2->second.top());
                    it2->second.pop();
                }
            }
            ans.push_back(temp);
        }
        return ans;
        
    }
};