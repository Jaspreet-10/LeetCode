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
    ListNode* insertionSortList(ListNode* head) {
        vector<int>v;
        ListNode* start=head;
        while(head!=NULL){
            v.push_back(head->val);
            head=head->next;
        }
        sort(v.begin(),v.end());
        head=start;
        for(int i=0;i<v.size();++i){
            head->val=v[i];
            head=head->next;
        }
        return start;
    }
};