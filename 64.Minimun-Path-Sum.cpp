int m, n, dp[1009][1009];
vector<vector<int>> path;

bool valid(int x, int y){
    return x >= 0 && x < m && y >= 0 && y < n;
}

long long call(int x, int y){
    if(dp[x][y] != -1)return dp[x][y];
    long long cost = path[x][y];
    int f1 = -1, f2 = -1;
    if(valid(x, y + 1))f1 = call(x, y + 1);
    if(valid(x + 1, y))f2 = call(x + 1, y);
    if(f1 == -1 && f2 == -1)return cost;
    else if(f1 == -1 && f2 != -1) cost += f2;
    else if(f2 == -1 && f1 != -1) cost += f1;
    else cost += min(f1, f2);
    return dp[x][y] = cost;
}

class Solution {
public:
    long long minPathSum(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        memset(dp, -1, sizeof(dp));
        path = grid;
        int ans = call(0,0);
        return ans;
    }
};
