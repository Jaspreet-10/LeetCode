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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL) return NULL;
        ListNode* result=head;
        int n=0;
        vector<int>v;
        while(head!=NULL){
            v.push_back(head->val);
            head=head->next;
            n++;
        }
        head=result;
        for(int i=0;i<=n-k;++i){
           reverse(v.begin()+i,v.begin()+i+k);
            i+=k-1;
        }
        int i=0;
        while(head!=NULL){
            head->val=v[i];
            i++;
            head=head->next;
        }
        return result;
    }
};