int x, y, dp[109][109];
vector<vector<int>> path;

bool within_grid(int m, int n){
    return m >= 0 && m < x && n >= 0 && n < y;
}

int call(int m, int n){
    if(!within_grid(m,n))return 0;
    if(dp[m][n] != -1)return dp[m][n];
    int w1 = call(m, n + 1);
    int w2 = call(m + 1, n);
    return dp[m][n] = w1 + w2;
}


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        path = obstacleGrid;
        x = obstacleGrid.size();
        y = obstacleGrid[0].size();
        for(int i = 0; i < x; i++)
            for(int j = 0; j < y; j++)
                dp[i][j] = obstacleGrid[i][j] == 1 ? 0 : -1;
        dp[x - 1][y - 1] = (path[x-1][y-1] == 1)? 0 : 1;
        call(0,0);
        return dp[0][0];
    }
};
