// Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.

// For example, the following two linked lists begin to intersect at node c1:
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //Brute O(n2)
 //Optimal O(n)
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* h1=headA;
        ListNode* h2=headB;
        while(h1!=h2){
            h1=h1->next;
            h2=h2->next;
            if(h1==h2) return h1;
            if(!h1) h1=headB;
            if(!h2) h2=headA;
            
        }
        return h1; 
        
    }
};