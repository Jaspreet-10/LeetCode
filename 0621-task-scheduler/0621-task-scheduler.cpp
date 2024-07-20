class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int>pq;
        queue<pair<int,int>>q;
        vector<int>charCount(26,0);
        int intervals = 0;
        for(char ch : tasks){
            // cout<<ch-'A'<<" ";
            charCount[ch-'A']++;
        }
        for(int i = 0 ; i < 26 ; ++i){
            if(charCount[i]>0)
            pq.push(charCount[i]);
        }
        while(!pq.empty() or !q.empty()){
            intervals+=1;
            if(!pq.empty()){
            int val = pq.top();
            pq.pop();
            if(val>1)
            q.push({val-1,intervals+n});
            }
            if(!q.empty() && q.front().second == intervals){ 
                pq.push(q.front().first);
                q.pop();
            }
        }
        return intervals;
    }
};