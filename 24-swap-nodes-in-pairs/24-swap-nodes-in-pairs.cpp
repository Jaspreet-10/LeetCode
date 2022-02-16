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
        if(head==NULL) return NULL;
        ListNode* res=head;
        while(head!=NULL and head->next!=NULL){
            swap(head->val,head->next->val);
            if(head->next->next!=NULL)
            head=head->next->next;
            else
                head=head->next;
        }
        return res;
    }
};