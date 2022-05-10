// You are given the heads of two sorted linked lists list1 and list2.

// Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

// Return the head of the merged linked list.
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
    ListNode* mergeTwoLists(ListNode* h1, ListNode* h2) {
        //null cases
        if(!h1 && !h2) return NULL;
        if(!h1) return h2;
        if(!h2) return h1;
        ListNode* fh=NULL;
        ListNode* ft=NULL;
        if(h1->val<h2->val){
            fh=h1;
            ft=h1;
            h1=h1->next;
        }
        else{
            fh=h2;
            ft=h2;
            h2=h2->next;
        }
        while(h1 && h2){
            if(h1->val<h2->val){
            ft->next=h1;
            ft=h1;
            h1=h1->next;
            }
         else{
            ft->next=h2;
            ft=h2;
            h2=h2->next;
        }
        }
        while(h1){
            ft->next=h1;
            ft=h1;
            h1=h1->next;
            
        }
        while(h2){
            ft->next=h2;
            ft=h2;
            h2=h2->next;
            
        }
        return fh;
        
    }
};