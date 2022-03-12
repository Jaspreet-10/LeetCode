/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL) return NULL;
        Node* res=new Node(0),*ans=res;
        unordered_map<Node*,Node*>m;
        Node* dummy=head,*randomC;
        while(dummy!=NULL){
            randomC=new Node(dummy->val);
            res->next=randomC;
            res=res->next;
            m[dummy]=randomC;
            dummy=dummy->next;
        }
        dummy=head;
        res=ans->next;
        while(dummy){
            res->random=m[dummy->random];
            dummy=dummy->next;
            res=res->next;
        }
        return ans->next;
    }
};