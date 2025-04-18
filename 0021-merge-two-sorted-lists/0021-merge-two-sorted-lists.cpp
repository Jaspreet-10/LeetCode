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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head = new ListNode(0), *ans = head;
        while(list1!=NULL && list2!=NULL){
            if(list1->val < list2->val){
                head->next = new ListNode(list1->val);
                list1 = list1->next;
            }else{
                head->next = new ListNode(list2->val);
                list2 = list2->next;
            }
            head = head->next;
        }
        while(list1!=NULL){
            head->next = new ListNode(list1->val);
            list1 = list1->next;
            head = head->next;
        }
         while(list2!=NULL){
            head->next = new ListNode(list2->val);
            list2 = list2->next;
            head = head->next;
        }
        return ans->next;
    }
};