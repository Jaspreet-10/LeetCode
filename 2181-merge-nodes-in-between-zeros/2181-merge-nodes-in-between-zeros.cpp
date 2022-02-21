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
    ListNode* mergeNodes(ListNode* head) {
        if(head==NULL) return NULL;
        int sum=0;
        ListNode* res=new ListNode(0),*prev=NULL,*dummy=res;
        while(head!=NULL){
            if(head->val==0 and head->next!=NULL){
                while(head->next!=NULL and head->next->val!=0){
                    sum+=head->val;
                    head=head->next;
                }
                sum+=head->val;
                res->next=new ListNode(sum);
                sum=0;
                res=res->next;
            }
            head=head->next;
        }
        return dummy->next;;
    }
};