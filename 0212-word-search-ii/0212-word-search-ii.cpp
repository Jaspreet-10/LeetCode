#include <vector>
#include <string>

using namespace std;

// Trie Node structure
struct Node{
    Node* links[26];
    bool flag = false;

    bool containsKey(char ch){
        return links[ch-'a'] != nullptr;
    }
    
    void put(Node* node, char ch){
        links[ch-'a'] = node;
    }
    
    Node* get(char ch){
        return links[ch-'a'];
    }
    
    void setEnd(){
        flag = true;
    }
    
    void unsetEnd(){
        flag = false;
    }
    
    bool isEnd(){
        return flag;
    }
};

// Trie structure
class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }

    // Insert a word into the Trie
    void insert(string word) {
        Node* node = root;
        for(char ch : word){
            if(!node->containsKey(ch)){
                node->put(new Node(), ch);
            }
            node = node->get(ch);
        }
        node->setEnd();
    }

    Node* getRoot() {
        return root;
    }
};

// Solution class using Trie
class Solution {
private:
    // Directions: down, up, right, left
    vector<pair<int, int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    
    // DFS search function
    void searchWord(int row, int col, vector<vector<char>>& board, Node* node, string currentWord, vector<string>& ans){
        // Boundary checks and current character check
        if(row < 0 || col < 0 || row >= board.size() || col >= board[0].size() || board[row][col] == '.' || !node->containsKey(board[row][col]))
            return;
        
        char ch = board[row][col];
        node = node->get(ch);
        currentWord += ch;
        
        // If current node marks the end of a word, add to answer and mark as found
        if(node->isEnd()){
            ans.push_back(currentWord);
            node->unsetEnd(); // Prevent duplicate additions
        }
        
        // Mark the current cell as visited
        board[row][col] = '.';
        
        // Explore all four directions
        for(auto &dir : directions){
            int newRow = row + dir.first;
            int newCol = col + dir.second;
            searchWord(newRow, newCol, board, node, currentWord, ans);
        }
        
        // Restore the current cell's character
        board[row][col] = ch;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // Initialize Trie and insert all words
        Trie trie;
        for(const string &word : words){
            trie.insert(word);
        }
        
        vector<string> ans;
        Node* root = trie.getRoot();
        
        // Iterate over each cell in the board to start DFS
        for(int i = 0; i < board.size(); ++i){
            for(int j = 0; j < board[0].size(); ++j){
                searchWord(i, j, board, root, "", ans);
            }
        }
        
        return ans;
    }
};
