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
        vector<int>v;
        if(head==NULL) return NULL;
        ListNode *temp=head;
        while(head!=NULL){
            v.push_back(head->val);
            head=head->next;
        }
        head=temp;
        int i=0,size=v.size()-1;
        while(head!=NULL){
            head->val=v[size-i];
            head=head->next;
            i++;
        }
        return temp;
    }
};