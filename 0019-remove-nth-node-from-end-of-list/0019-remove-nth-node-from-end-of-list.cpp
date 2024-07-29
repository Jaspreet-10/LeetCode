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
        int cnt = 0;
        ListNode* node = head, *ans = head;
        if(!head) return ans;
        while(node!=NULL){
            ++cnt;
            node = node->next;
        }

        int rem = cnt - n - 1;
        while(head!=NULL && rem>0){
            --rem;
            head = head->next;
            cout<<head->val<<" ";
        }
        if(cnt == n){
            return ans->next;
        }
        else
        head->next = head->next->next;
        return ans;
    }
};