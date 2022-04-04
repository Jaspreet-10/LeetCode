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
    ListNode* swapNodes(ListNode* head, int k) {
        if(head == NULL) return NULL;
        vector<int>v;
        int  i = 0;
        ListNode *cur = head, *res = head;
        while(cur!=NULL){
            v.push_back(cur->val);
            cur = cur->next;
        }
        swap(v[k-1],v[v.size()-k]);
        while(head!=NULL){
            head->val = v[i];
            ++i;
            head = head->next;
        }
        return res;
    }
};