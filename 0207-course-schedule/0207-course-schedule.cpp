class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adjL[numCourses];
        vector<int>inDegree(numCourses,0);
        queue<int>q;
        for(int i = 0 ; i < prerequisites.size() ; ++i){
            adjL[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        for(int i = 0 ; i < numCourses  ; ++i){
            for(int j = 0 ; j < adjL[i].size() ; ++j){
                inDegree[adjL[i][j]]++;
            }
        }
        for(int i = 0 ; i < inDegree.size() ; ++i){
            if(inDegree[i] == 0) q.push(i);
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it : adjL[node]){
                inDegree[it]--;
                if(inDegree[it] == 0)q.push(it);
            }
        }
        for(int i = 0 ; i < inDegree.size() ; ++i){
            if(inDegree[i]!=0) return false;
        }
        return true;
    }
};