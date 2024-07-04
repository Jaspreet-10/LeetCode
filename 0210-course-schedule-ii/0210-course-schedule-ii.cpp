class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adjList[numCourses];
        vector<int>inDegree(numCourses,0);
        vector<int>v;
        queue<int>q;
        for(int i = 0 ; i < prerequisites.size() ; ++i){
            adjList[prerequisites[i][1]].push_back(prerequisites[i][0]);
            inDegree[prerequisites[i][0]]++;
        }
        for(int i = 0 ; i < numCourses ; ++i){
            if(inDegree[i] == 0){
                // v.push_back(i);
                q.push(i);
                inDegree[i] = -1;
            }
        }

        while(!q.empty()){
            int node = q.front();
            v.push_back(node);
            q.pop();
            for(auto it : adjList[node]){
                inDegree[it]--;
                if(inDegree[it] == 0){
                    inDegree[it] = -1;
                    // v.push_back(it);
                    q.push(it);
                }
            }
        }
        for(int i = 0 ; i < numCourses ; ++i)
            if(inDegree[i]!=-1) return {};
        return v;
    }
};