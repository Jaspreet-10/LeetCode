/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
        unordered_map<ListNode*,int>m;
        ListNode*res=new ListNode();
    while(head1!=NULL||head2!=NULL){
            if(head1!=NULL){
                if(m[head1]==0)
                m[head1]++;
                else{
                    res=head1;
                    return res;
                }
                head1=head1->next;
            }
            if(head2!=NULL){
                if(m[head2]==0)
                    m[head2]++;
                else{
                    res=head2;
                    return res;
                }
                head2=head2->next;
            }
        }
    return NULL;
    }
};