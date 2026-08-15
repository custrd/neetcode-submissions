class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans = {0,0};
        map<int, int> mp;
        for(int i=0; i<n; i++){
            auto it = mp.find(target-nums[i]);
            if(it!=mp.end()){
                ans[0]=it->second;
                ans[1]=i;
                return ans;
            }else mp[nums[i]] = i;
        }
        return ans;
    }
};
