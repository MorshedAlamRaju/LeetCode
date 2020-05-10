class Solution {
public:
    string rev_and_add(string s, string t){
        reverse(begin(s), end(s));
        reverse(begin(t), end(t));
        
        int slen = s.length(), tlen = t.length();
        while(slen < tlen)s += '0', slen++;
        while(tlen < slen) t += '0', tlen++;
        
        reverse(begin(s), end(s));
        reverse(begin(t), end(t));
        
        string res;
        int carry = 0;
        
        for(int i = slen - 1; i >= 0; i--){
            int d1 = s[i] - '0';
            int d2 = t[i] - '0';
            int sum = carry + d1 + d2;
            int add = sum % 10;
            res += (add + '0');
            carry = sum / 10;
        }
        
        while(carry)res += ((carry % 10) + '0'), carry /= 10;
        reverse(begin(res), end(res));
        return res;
        
    }
    
    string addStrings(string num1, string num2) {
        return rev_and_add(num1, num2);
    }
};