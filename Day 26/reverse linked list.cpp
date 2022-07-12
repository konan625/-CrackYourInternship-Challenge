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
    ListNode* reverse(ListNode* head,ListNode* newhead){
        if(head==NULL) return newhead;
        ListNode* next=head->next;
        head->next=newhead;
        newhead=head;
        return reverse(next,newhead);
        
    }
    ListNode* reverseList(ListNode* head) {
        return reverse(head,NULL);
    }
};

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
    ListNode* reverseList(ListNode* head) {
        ListNode* curr=head;
        ListNode* next=NULL;
        ListNode* prev=NULL;
        
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            
            prev=curr;
            curr=next;
        }
        return prev;
        
    }
};