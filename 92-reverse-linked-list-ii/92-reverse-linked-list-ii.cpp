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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL) return NULL;
        ListNode* res=head;
        vector<int>v;
        while(head!=NULL){
            v.push_back(head->val);
            head=head->next;
        }
        head=res;
        int i=0;
        while(left<right){
            swap(v[left-1],v[right-1]);
            left++;
            right--;
        }
        while(head!=NULL){
            head->val=v[i];
            head=head->next;
            i++;
        }
        return res;
    }
};