class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();   // no. of rows
        int n = mat[0].size();  // no. of columns
		
		// initializing distance matrix with INT_MAX value
        vector <vector <int>> dis (m, vector<int> (n, INT_MAX));
		
		// setting visited matrix with 0
        vector <vector <int>> vis (m, vector<int> (n, 0));
		
        queue <pair<int,int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
			// first finding zeros in the matrix and storing it in the queue for BFS
                if (mat[i][j] == 0) {
                    q.push({i,j});
                    dis[i][j] = 0;  // distance from itself will be zero
                    vis[i][j] = 1;  // marking as visited as it is pushed in the queue
                }
            }
        }
		// used in checking the neighbours
        int arry[] = {-1, 0, 1, 0 };  
        int arrx[] = { 0, 1, 0, -1}; 
        
        while (!q.empty()) {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();
            
			// calculation distance from nearest zero of
			// every neighbour inside the boundary
            for (int i = 0; i < 4; i++) {
                int dy = y + arry[i];
                int dx = x + arrx[i];
                
				// boundary condition check
                if (dy < m and dx < n and dy >= 0 and dx >= 0) {
					// if and only if current distance of neighbour is greater than 
					// current position's distance + 1
                    if (dis[dy][dx] > dis[y][x] + 1) {
                        dis[dy][dx] = dis[y][x] + 1;
						// it is not visited then add it to the queue and mark as visited
                        if (vis[dy][dx] == 0) {
                            q.push({dy, dx});
                            vis[dy][dx] = 1;
                        }
                    }
                }
            }
        } 
		// return distance matrix
        return dis;
    } 
};