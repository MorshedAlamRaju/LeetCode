
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int max_area = 0;
        int len = height.size();
        while(l < r && r < len){
            max_area = max(max_area, min(height[l], height[r]) * (r - l));
            if(height[l] < height[r])l++;
            else if(height[r] < height[l])r--;
            else l++;
        }
        return max_area;
    }
};
