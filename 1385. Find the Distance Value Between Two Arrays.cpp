class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int cnt = 0;
        for(auto a : arr1){
            int add = 1;
            for(auto b : arr2)
                if(abs(a - b) <= d)
                    add = 0;
            cnt += add;
        }
        return cnt;
    }
};
