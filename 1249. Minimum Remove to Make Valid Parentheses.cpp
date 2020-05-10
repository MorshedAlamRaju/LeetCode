class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<int> idx;
        int l = 0, r = 0;
        for(int i = 0; s[i]; i++){
            l += (int)(s[i] == '(');
            r += (int)(s[i] == ')');
            if(r > l){
                idx.push_back(i);
                r--;
            }
        }
        sort(idx.begin(), idx.end());
        for(int i = idx.size() - 1; i >= 0; i--)s.erase(idx[i],1);
        l = 0, r = 0;
        idx.clear();
        cout << s << endl;
        for(int i = s.length() - 1; i >= 0; i--){
            l += (int)(s[i] == '(');
            r += (int)(s[i] == ')');
            if(l > r){
                idx.push_back(i);
                l--;
            }
        }
        sort(idx.begin(), idx.end());
        for(int i = idx.size() - 1; i >= 0; i--)s.erase(idx[i],1);
        return s;
    }
};