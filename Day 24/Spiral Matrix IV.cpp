You are given two integers m and n, which represent the dimensions of a matrix.

You are also given the head of a linked list of integers.

Generate an m x n matrix that contains the integers in the linked list presented in spiral order (clockwise), starting from the top-left of the matrix. If there are remaining empty spaces, fill them with -1.

Return the generated matrix.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        int left=0,right=n-1,top=0,bottom=m-1;
        vector<vector<int>> ans(m,vector<int>(n,-1));
        ListNode* temp=head;
        while(temp && top<=bottom && left<=right){
            //left to right
            for(int i=left; temp && i<=right;i++){
                ans[top][i]=temp->val;
                temp=temp->next;
            }
            top++;
            //right to bottom
            for(int i=top;temp && i<=bottom;i++){
                ans[i][right]=temp->val;
                temp=temp->next;
            }
            right--;
            if(top<=bottom){
            //right to left
            for(int i=right;temp && i>=left;i--){
                ans[bottom][i]=temp->val;
                temp=temp->next;
            }
            }
            bottom--;
            //bottom to top
            if(left<=right){
            for(int i=bottom;temp && i>=top;i--){
                ans[i][left]=temp->val;
                temp=temp->next;
            }
            }
            left++;
        }
        return ans;
        
    }
};