int dp[109][109];
int x, y;

bool valid(int i, int j){
    return i >= 1 && i <= x && j > 0 && j <= y;
}

int call(int l, int r){
    if(!valid(l,r))return 0;
    if(dp[l][r] != 0)return dp[l][r];
    int w1 = call(l + 1, r);
    int w2 = call(l, r + 1);
    return dp[l][r] = w1 + w2;

}

class Solution {
public:
    int uniquePaths(int m, int n) {
        x = m, y = n;
        memset(dp, 0, sizeof(dp));
        dp[m][n] = 1;
        call(1, 1);
        return dp[1][1];
    }
};
