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
    ListNode* swapPairs(ListNode* head) {
        ListNode* start=head;
        int v=0;
        if(head==NULL) return NULL;
        while(head->next!=NULL and head->next->next!=NULL){
            swap(head->val,head->next->val);
            head=head->next->next;
        }
        if(head->next==NULL){
            return start;        
        }
        swap(head->val,head->next->val);
        return start;
    }
};