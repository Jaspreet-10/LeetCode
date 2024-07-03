/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* clone(Node* node, unordered_map<Node*,Node*>&oldNode){
        if(oldNode.find(node)!=oldNode.end()) return oldNode[node];
        Node* copy = new Node(node->val);
        oldNode[node] = copy;
        for(auto it:node->neighbors){
            copy->neighbors.push_back(clone(it, oldNode));
        }
        return copy;
    }
    Node* cloneGraph(Node* node) {
       if(!node) return {};
       unordered_map<Node*,Node*>oldNode;
       return clone(node, oldNode);
    }
};