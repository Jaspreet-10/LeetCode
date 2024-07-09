class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>ch(26,0);
        for(int i = 0 ; i < tasks.size() ; ++i) ch[tasks[i] - 'A']++;
        sort(ch.rbegin(), ch.rend());
        int maxVal = ch[0]-1;
        int idle_slots = maxVal*n;
        for(int i = 1 ; i < 26 ; ++i){
            idle_slots-=min(ch[i],maxVal);
        }
        return idle_slots>0 ? idle_slots+tasks.size():tasks.size();
    }
};