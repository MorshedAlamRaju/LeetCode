class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)return false;
        string str, rts;
        x = abs(x);
        while(x){
            str += (x % 10) + '0';
            x /= 10;
        }
        rts = str;
        reverse(rts.begin(), rts.end());
        return rts == str;

    }
};
