class TrieNode {
public:
    TrieNode* children[52]; // 26 lowercase + 26 uppercase letters
    string word; // To store the word ending at this node
    
    TrieNode() : word("") {
        for(int i = 0; i < 52; i++) {
            children[i] = nullptr;
        }
    }
};

class Trie {
public:
    TrieNode* root;
    
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for(char c : word) {
            int index = charToIndex(c);
            if(node->children[index] == nullptr) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->word = word; // Mark the end of a word
    }

    int charToIndex(char c) {
        if(c >= 'a' && c <= 'z') return c - 'a';         // Lowercase letters (0-25)
        else return c - 'A' + 26;                         // Uppercase letters (26-51)
    }
};

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        Trie trie;
        trie.insert(word);
        
        int m = board.size();
        int n = board[0].size();
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if (dfs(board, i, j, trie.root, trie)) {
                    return true;
                }
            }
        }
        
        return false;
    }
    
    bool dfs(vector<vector<char>>& board, int cr, int cc, TrieNode* node, Trie& trie) {
        if(cr < 0 || cr >= board.size() || cc < 0 || cc >= board[0].size()) return false; // Out of bounds
        char c = board[cr][cc];
        if(c == '.' || node->children[trie.charToIndex(c)] == nullptr) return false; // Already visited or not in Trie
        
        node = node->children[trie.charToIndex(c)];
        if(node->word != "") { // Found the word
            return true;
        }
        
        // Mark the current cell as visited
        board[cr][cc] = '.';
        
        // Explore all 4 directions
        bool found = dfs(board, cr + 1, cc, node, trie) ||
                     dfs(board, cr - 1, cc, node, trie) ||
                     dfs(board, cr, cc + 1, node, trie) ||
                     dfs(board, cr, cc - 1, node, trie);
        
        // Restore the original value of the cell
        board[cr][cc] = c;
        
        return found;
    }
};
