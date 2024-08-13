struct Node {
    Node* links[26];
    bool flag = false;
    
    bool containsKey(char ch) {
        return links[ch - 'a'] != nullptr;
    }
    
    void put(Node* node, char ch) {
        links[ch - 'a'] = node;
    }
    
    Node* get(char ch) {
        return links[ch - 'a'];
    }
    
    void setEnd() {
        flag = true;
    }
    
    bool isEnd() {
        return flag;
    }
};
class WordDictionary {
    private:
    Node* root;
    
    bool searchWord(Node* node, const string &word, int index) {
        if (index == word.length()) {
            return node->isEnd();
        }
        
        char ch = word[index];
        if (ch == '.') {
            for (int i = 0; i < 26; i++) {
                if (node->links[i] != nullptr && searchWord(node->links[i], word, index + 1)) {
                    return true;
                }
            }
            return false;
        } else {
            if (!node->containsKey(ch)) {
                return false;
            }
            return searchWord(node->get(ch), word, index + 1);
        }
    }
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->containsKey(word[i])) {
                node->put(new Node(), word[i]);
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        return searchWord(root, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */