class Solution {
public:
    bool canJump(vector<int>& nums) {

        int last_len = 0;
        for(int i = 0; i < nums.size(); i++){
            if(i > last_len)break;
            if(i + nums[i] >= last_len)last_len = i + nums[i];
        }
        return last_len >= nums.size() - 1;


        /// Another approach using Queue Data Structure
        /*
        queue<int> q;
        int target = nums.size() - 1;
        int last_len = 0, mx_len = 0;
        bool pass = false;
        q.push(0);

        while(!q.empty() && !pass){
            int i = q.front();
            q.pop();
            int f = nums[i];
            mx_len = max(mx_len, i + f);
            if(mx_len >= target)pass = true;
            while(last_len < mx_len)q.push(++last_len);
            last_len = mx_len;
        }
        */

        //return pass;

    }
};
