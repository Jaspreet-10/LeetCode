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
        unordered_map<Node*, Node*>m;
        Node* temp = new Node(0), *cur = head, *res = temp;
        while(cur!=NULL){
           temp->next = new Node(cur->val);
           m[cur] = temp->next;
           cur = cur->next;
           temp = temp->next;
        }
        cur = head;
        temp = res->next;
        while(cur!=NULL){
          temp->random = m[cur->random];
          cur = cur->next;
          temp = temp->next;
        }
        return res->next;
    }
};