class Solution {
public:
    int findUniquePaths(int cr, int cc, int row, int col, vector<vector<int>>& dp, int prev, vector<vector<int>>& matrix) {
    // Check for out-of-bounds or non-increasing conditions
    if (cr < 0 || cc < 0 || cr >= row || cc >= col || matrix[cr][cc] <= prev) return 0;

    // If already computed, return the stored value
    if (dp[cr][cc] != -1) return dp[cr][cc];

    // Explore all four directions
    int down = findUniquePaths(cr + 1, cc, row, col, dp, matrix[cr][cc], matrix);
    int right = findUniquePaths(cr, cc + 1, row, col, dp, matrix[cr][cc], matrix);
    int up = findUniquePaths(cr - 1, cc, row, col, dp, matrix[cr][cc], matrix);
    int left = findUniquePaths(cr, cc - 1, row, col, dp, matrix[cr][cc], matrix);

    // Store the result in dp array
    dp[cr][cc] = 1 + max({down, right, up, left});

    return dp[cr][cc];
}

int longestIncreasingPath(vector<vector<int>>& matrix) {
    if (matrix.empty()) return 0;

    int row = matrix.size();
    int col = matrix[0].size();
    int maxi = 0;

    vector<vector<int>> dp(row, vector<int>(col, -1)); // Initialize dp array

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            // Compute the longest path starting from each cell
            maxi = max(maxi, findUniquePaths(i, j, row, col, dp, INT_MIN, matrix));
        }
    }

    return maxi;
    }
};