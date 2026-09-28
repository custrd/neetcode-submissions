int dfs(int i, int j, int n, int m, vector<vector<int>> &dp){
    if(i>=n || j>=m) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(i==n-1 && j==m-1) return 1;
    int right = dfs(i, j+1, n, m, dp);
    int down = dfs(i+1, j, n, m, dp);

    dp[i][j] = right + down;
    return dp[i][j];
}

class Solution {
public:
    int uniquePaths(int n, int m) {
        vector<vector<int>> dp(n, vector<int> (m, -1));

        return dfs(0, 0, n, m, dp);
    }
};
