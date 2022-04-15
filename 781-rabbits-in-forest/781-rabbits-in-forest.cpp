class Solution {
public:
    int numRabbits(vector<int>& answers) {
       unordered_map<int,int>memo;
        for(int i = 0 ; i < answers.size() ; ++i){
            memo[answers[i]]++;
        }
        int totalRabbits=0;
        for(auto i : memo){
            double mulD=(1.0*i.second/(i.first+1));
            int mul=ceil(mulD);
            if(mul==0)
            {
                mul=1;
            }
            totalRabbits+=mul*(i.first+1);
        }
        return totalRabbits;
    }
};