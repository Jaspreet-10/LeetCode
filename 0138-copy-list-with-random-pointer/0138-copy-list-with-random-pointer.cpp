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
        Node* temp = new Node(0), *cur = head, *res = temp;
        unordered_map<Node*,Node*>m;
        while(head!=NULL){
            temp->next = new Node(head->val);
            m[head] = temp->next;
            head = head->next;
            temp = temp->next;
        }
        head = cur;
        temp = res->next;
        while(head!=NULL){
            temp->random = m[head->random];
            temp = temp->next;
            head = head->next;
        }
        return res->next;
    }
};