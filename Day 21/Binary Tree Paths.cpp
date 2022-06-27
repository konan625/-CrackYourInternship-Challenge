Given the root of a binary tree, return all root-to-leaf paths in any order.

A leaf is a node with no children
class Solution {
public:
    void helper(TreeNode* root,string s,vector<string>& ans){
        if(!root) return ;
        if(!root->left && !root->right){
            s+=to_string(root->val);
            ans.push_back(s);
            return;
        }
        s+=(to_string(root->val));
        s+="->";
        if(root->left){
            helper(root->left,s,ans);
        }
        if(root->right){
            helper(root->right,s,ans);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        helper(root,"",ans);
        return ans;
    }
};