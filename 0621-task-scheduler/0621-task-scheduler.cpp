class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int>pq;
        queue<pair<int,int>>q;
        int total_time = 0, time = 0;
        vector<int>v(26,0);
        for(int i = 0 ; i < tasks.size() ; ++i) v[tasks[i]-'A']++;
        for(int i = 0 ; i < v.size() ; ++i){
            if(v[i]>0) pq.push(v[i]);
        }
        while(!pq.empty() or !q.empty()){
            total_time+=1;
           if(!pq.empty()){
            int val = pq.top();
            pq.pop();
            if(val>1)
            q.push({val-1,total_time+n});
            }
            if(!q.empty() && q.front().second == total_time){
                pq.push(q.front().first);
                q.pop();
            }
        }
        return total_time;
    }
};