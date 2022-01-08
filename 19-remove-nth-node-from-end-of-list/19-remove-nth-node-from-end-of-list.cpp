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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL) return NULL;
        ListNode *start=head;
        int count=0;
        while(head!=NULL){
            count++;
            head=head->next;
        }
        if(count==n)
            return start->next;
        head=start;
        int rem=count-n;
        count=0;
        while(count<rem){
            count++;
            if(count<rem)
            head=head->next;
        }
        head->next=head->next->next;
        return start;
    }
};