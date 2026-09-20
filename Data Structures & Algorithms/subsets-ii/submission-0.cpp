void solve(int i, vector<int> &nums, vector<vector<int>> &ans, vector<int> &subset){
    //base case
    if(i==nums.size()){
        ans.push_back(subset);
        return;
    }

    //include
    subset.push_back(nums[i]);
    solve(i+1, nums, ans, subset);

    //exclude
    while(i+1 < nums.size() && nums[i] == nums[i+1]){
        i++;
    }
    subset.pop_back();
    solve(i+1, nums, ans, subset);
}

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> subset;

        solve(0, nums, ans, subset);
        return ans;
    }
};
