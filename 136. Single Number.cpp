class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int> m;
        for(auto x : nums)m[x]++;
        int missing;
        for(auto  x : m){
            if(x.second == 1){
                missing = x.first;
                break;
            }
        }
        return missing;
    }
};
