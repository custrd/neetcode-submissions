void solve(int i, vector<int> &nums, int target, vector<vector<int>> &ans, vector<int> &subset, int &sum){
    if(sum == target){
        ans.push_back(subset);
        return ;
    }
    if(i >= nums.size() || sum > target){
        return ;
    }

    //include & increment
    subset.push_back(nums[i]);
    sum += nums[i];
    solve(i, nums, target, ans, subset, sum);

    //exclude & increment
    subset.pop_back();
    sum -= nums[i];
    solve(i+1, nums, target, ans, subset, sum);
}

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> subset;

        int sum = 0;
        //solving function
        solve(0, nums, target, ans, subset, sum);

        return ans;
    }
};
