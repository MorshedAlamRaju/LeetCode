class Solution {
public:
    int myAtoi(string str) {

        if(str.empty())return 0;
        int st = 0; char sign = '+';
        long long num = 0;
        while(st < str.size() && str[st] == ' ')st++;
        if(st < str.size() && str[st] == '+' || str[st] == '-')
                sign = str[st++];

        while(st < str.size() && isdigit(str[st])){
            num = num * 10 + (str[st++] - '0');
            if(num > INT_MAX)break;
        }

        if(num > INT_MAX){
            if(sign == '+')
                return INT_MAX;
            else return INT_MIN;
        }
        num = sign == '+' ? num : -num;
        return num;

    }
};
