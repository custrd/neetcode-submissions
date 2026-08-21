class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        unordered_set<int> s;
        sort(nums.begin(), nums.end());
        
        for(int start = 0; start<n; start++){
            if(start>0 && nums[start]==nums[start-1]) continue;
            for(int end = n-1; end>=start+1; end--){
                if(end<n-1 && nums[end]==nums[end+1]) continue;
                int target = 0-(nums[start]+nums[end]);
                int lo=start+1, hi=end-1;
                while(lo<=hi){
                    int mid = lo+(hi-lo)/2;
                    if(nums[mid]==target){
                        ans.push_back({nums[start], nums[end], nums[mid]});
                        break;
                    }else if(nums[mid]<target) lo = mid+1;
                    else hi = mid-1;
                }   
            }
        }   
        return ans;
    }
};



