class Solution {
public:
    bool detectCycle(int node, vector<int>&vis, vector<int>&visPath, 
    vector<vector<int>>&adjL, int parent){
        vis[node] = 1;
        visPath[node] = 1;
        for(auto it : adjL[node]){
            if(vis[it] == 0){
                if(detectCycle(it, vis, visPath, adjL, node)) return true;
            }
            else if(visPath[it]!=0) return true;
        }
        visPath[node] = 0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjL(numCourses);
        vector<int>vis(numCourses, 0);
        vector<int>visPath(numCourses, 0);
        int n = prerequisites.size();
        for(int i = 0 ; i < n ; ++i){
            adjL[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        for(int i = 0 ; i < numCourses ; ++i){
            if(vis[i] == 0){
                if(detectCycle(i, vis, visPath, adjL, -1)) return false;
            }
        }
        return true;
    }
};