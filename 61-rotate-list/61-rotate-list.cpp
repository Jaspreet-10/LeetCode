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
    ListNode* rotateRight(ListNode* head, int d) {
        if(head==NULL) return NULL;
        ListNode* dummy=head;
        vector<int>v,vc;
        while(head!=NULL){
            v.push_back(head->val);
            vc.push_back(head->val);
            head=head->next;
        }
        int n=v.size();
        for(int i=0;i<n;++i){
            v[(i+d)%n]=vc[i];
        }
        head=dummy;
        int i=0;
        while(head!=NULL){
            head->val=v[i];
            head=head->next;
            i++;
        }
        return dummy;
    }
};