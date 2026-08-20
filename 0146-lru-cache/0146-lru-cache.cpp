class LRUCache {
public:
    class Node {
      public:
      int key;
      int val;
      Node * next;
      Node * prev;
      Node(int _key, int _val) {
        key = _key;
        val = _val;
      }
    };
    int capacity;
    unordered_map<int, Node*>m;
    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);
    LRUCache(int capacity) {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }
    void deleteNode(Node* node){
        Node* temp = node->prev;
        temp->next = node->next;
        node->next->prev = temp;
        return ;
    }
    void addNode(Node* node){
        Node* temp = head->next;
        head->next = node;
        node->prev = head;
        node->next = temp;
        temp->prev = node;
        return ;
    }
    int get(int key) {
        if(m.find(key)==m.end()) return -1;
        deleteNode(m[key]);
        addNode(m[key]);
        return m[key]->val;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            m[key]->val = value;
            deleteNode(m[key]);
            addNode(m[key]);
            return;
        }
        if(m.size()>=capacity){
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        Node* newNode = new Node(key, value);
        m[key] = newNode;
        addNode(newNode);
        return ;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */