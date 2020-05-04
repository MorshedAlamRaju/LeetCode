class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int l = 0, len = nums.size(), pos = 0;
        for(int i = 0; i < len; i++){
            if(val != nums[i]){
                nums[pos] = nums[i];
                pos++;
            }
        }
        while(nums.size() > pos)nums.pop_back();
        return pos;
    }
};
