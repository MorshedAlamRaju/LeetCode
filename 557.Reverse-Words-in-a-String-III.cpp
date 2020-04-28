class Solution {
public:

    string Reverse(string s){
        reverse(s.begin(), s.end());
        return s;
    }

    bool Special(char c){
        return c == ' ' || c == '\t';
    }


    string reverseWords(string s) {
        string t, rev;
        for(int i = 0; s[i]; i++){

            if(Special(s[i])){
                rev += Reverse(t);
                rev += s[i];
                t.clear();
            }
            else t += s[i];
        }
        rev += Reverse(t);
        return rev;
    }
};
