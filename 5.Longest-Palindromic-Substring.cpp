string str;
int dp[1001][1001];

int call(int l, int r){
    if(r < l)return 0;
    if(dp[l][r] != -1)return dp[l][r];
    if(l == r)return dp[l][r] = (str[l] == str[r])? 1 : 0;

    int f1 = call(l + 1, r);
    int f2 = call(l, r - 1);
    int f3 = call(l + 1, r - 1);

    if(l + 1 < r && (f3 == (r - l - 1)))f3 += (str[l] == str[r])? 2 : 0;
    else if(l + 1 == r)f3 += (str[l] == str[r])? 2 : 0;

    f3 = max(f3, f2);
    f3 = max(f3, f1);
    return dp[l][r] = f3;
}

bool pal(string s){
    for(int i = 0, j = s.size() - 1; i < j; i++,j--)
        if(s[i] != s[j])return false;
    return true;
}

class Solution {
public:
    string longestPalindrome(string s) {
        str = s;
        memset(dp, -1, sizeof(dp));
        int len = call(0, s.length() - 1);

        str.clear();
        for(int i = 0; i < len; i++)str += s[i];

        if(pal(str))return str;
        for(int i = len; s[i]; i++){
            if(pal(str))return str;
            str.erase(0,1);
            str += s[i];
        }

        return str;
    }
};
