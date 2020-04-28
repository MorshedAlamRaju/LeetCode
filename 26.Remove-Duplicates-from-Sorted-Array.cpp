class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int len = nums.size();
        if(len == 0)return 0;
        int v = nums.front();
        int pos = 1, i = 1;

        while(i < len){
            while(i < len && v == nums[i])i++;
            if(i < len){
                v = nums[pos] = nums[i];
                pos++;
            }
            i++;
        }
        while(nums.size() > pos)nums.pop_back();
        return pos;
    }

};
