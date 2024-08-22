class Solution {
public:
    bool searchWord(int index, int cr, int cc, int m, int n, vector<vector<char>>& board, 
    string word, char temp){
        if(word.size() == index) return true;
        if(index>=word.size() || cr<0 || cc<0 || cr>=m ||cc >=n || 
        board[cr][cc] == '.' || board[cr][cc]!=word[index]) return false;
        if(word[index] == board[cr][cc]){
            temp = board[cr][cc];
            board[cr][cc] = '.';
            if(searchWord(index+1, cr+1, cc, m, n, board, word, temp)) return true;
            if(searchWord(index+1, cr-1, cc, m, n, board, word, temp)) return true;
            if(searchWord(index+1, cr, cc+1, m, n, board, word, temp)) return true;
            if(searchWord(index+1, cr, cc-1, m, n, board, word, temp)) return true;
            board[cr][cc] = temp;
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        char temp;
        for(int i = 0 ; i < board.size() ; ++i){
            for(int j = 0 ; j < board[i].size() ; ++j){
                if(searchWord(0, i, j, board.size(), board[0].size(), board, word, temp))
                    return true;
            }
        }
        return false;
    }
};