// Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.
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

// Approach 1
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* temp=head;
        ListNode* newhead=NULL;
        ListNode* tail=NULL;
        if(!head) return NULL;
        while(temp){
            if(temp->val!=val ){
                ListNode* curr=new ListNode(temp->val);
                if(!newhead){
                    newhead=curr;
                    tail=curr;
                }
                else{
                    tail->next=curr;
                    tail=tail->next;
                }
            }
            temp=temp->next;
        }
        return newhead;
        
        
    }
};

//Approach 2
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* newhead=new ListNode();
        newhead->next=head;
        ListNode* prev=newhead;
        if(!head) return NULL;
        while(prev->next){
            if(prev->next->val==val){
                prev->next=prev->next->next;
            }else{
                prev=prev->next;
            }
        }
        
        return newhead->next;  
    }
};