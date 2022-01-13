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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        vector<int>v;
        if(l1==NULL and l2==NULL) return NULL; 
        if(l1==NULL) return l2;
        ListNode *start=l1;
        while(l1!=NULL){
            v.push_back(l1->val);
            l1=l1->next;
        }
        while(l2!=NULL){
            v.push_back(l2->val);
            l2=l2->next;
        }
        l1=start;
        sort(v.begin(),v.end());
        int i=0;
        while(i<v.size()){
            if(l1->next==NULL and i!=v.size()-1){
                l1->next=new ListNode();
            }
            l1->val=v[i];
            l1=l1->next;
            i++;
        }
        return start;
    }
};