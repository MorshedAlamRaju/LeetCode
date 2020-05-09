class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());
        int a[mx + 9];
        memset(a, 0, sizeof(a));
        for(auto x : nums)a[x]++;
        int missing;
        for(int i = 0; i <= mx; i++)
            if(a[i] == 0){
                missing = i;
                break;
            }
        return missing;
    }
};
