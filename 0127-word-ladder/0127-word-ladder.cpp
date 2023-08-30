class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>>q;
        unordered_set<string>s(wordList.begin(),wordList.end());
        q.push({beginWord,1});
        while(!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            string temp = word;
            for(int i = 0 ; i < word.size() ; ++i){
                for(char ch = 'a' ; ch<='z' ; ++ch){
                    word[i] = ch;
                    if(s.find(word)!=s.end()){
                        if(endWord == word) return steps+1;
                        q.push({word,steps+1});
                        s.erase(word);
                    }
                }
                word = temp;
            }
        }
        return 0;
    }
};