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
        if (!head) return NULL;

    // Step 1: Create a copy of each node and store the mapping
    Node* temp = new Node(0);  // Dummy node to start the cloned list
    Node* cur = head;
    Node* res = temp;
    unordered_map<Node*, Node*> m;

    // Create a new node for each original node and store it in the map
    while (head != NULL) {
        temp->next = new Node(head->val); // Create a new node with the same value
        m[head] = temp->next;             // Map original node to the new node
        head = head->next;
        temp = temp->next;
    }

    // Step 2: Set up the random pointers using the map
    head = cur;
    temp = res->next;
    while (head != NULL) {
        temp->random = m[head->random]; // Use the map to set the correct random pointer
        temp = temp->next;
        head = head->next;
    }

    // Return the head of the newly copied list
    return res->next;
    }
};