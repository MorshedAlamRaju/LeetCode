class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        int left = 0, right = len - 1, mid = 1;
        int trapped = 0;

        while(left < right){

            while(left < right && height[left] <= height[left + 1])left++;
            while(right > left && height[right] <= height[right - 1])right--;

            int go_right = left + 1;
            int mx = 0, idx = go_right;

            while(go_right <= right){
                if(height[go_right] >= height[left]){
                    idx = go_right;
                    mx = height[idx];
                    break;
                }
                else{
                    if(mx <= height[go_right]){
                        idx = go_right;
                        mx = height[go_right];
                    }
                }
                go_right++;
            }
            for(int i = left + 1; i < idx; i++){
                int min_height = min(mx, height[left]);
                trapped += abs(min_height - height[i]);
            }
            left = idx;
        }
        return trapped;
    }
};
