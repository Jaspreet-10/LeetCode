class Solution {
public:
    map<vector<int>, int>v;
    void printPermutations(int index, int n, vector<vector<int>>&answer,
     unordered_map<int,int>&m, vector<int>&temp){
        if(index>=(n+1)){
            // if(v[temp] == 0)
            answer.push_back(temp);
            // v[temp]++;
            return ;
        }

        for(int i = 1 ; i<=n ; ++i){
            if(temp.size() == 0){
                temp.push_back(i);
                m[i]++;
                printPermutations(index+1, n, answer, m, temp);
                temp.pop_back();
                m[i] = 0;
            }
            else if(m[i] == 0 && ((temp[temp.size()-1]%2 == 0 && i%2!=0) || 
                (temp[temp.size()-1]%2 != 0 && i%2==0))){
                temp.push_back(i);
                m[i]++;
                printPermutations(index+1, n, answer, m, temp);
                temp.pop_back();
                m[i] = 0;
            }
        }
        return ;
     }
    vector<vector<int>> permute(int n) {
        vector<vector<int>>answer;
        unordered_map<int, int>m;
        vector<int>temp;
        printPermutations(1, n, answer, m, temp);
        sort(answer.begin(), answer.end());
        return answer;
    }
};