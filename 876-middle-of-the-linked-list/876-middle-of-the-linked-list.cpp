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
    ListNode* middleNode(ListNode* head) {
        if(head==NULL) return NULL;
        int count=0,mid=0;
        ListNode* start=head;
        while(head!=NULL){
            count++;
            head=head->next;
        }
        mid=count/2;
        count=0;
        head=start;
        while(count<mid){
            count++;
            head=head->next;
        }
        return head;
    }
};