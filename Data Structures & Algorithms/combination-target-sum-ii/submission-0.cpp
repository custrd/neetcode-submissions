void solve(int i, vector<int> &nums, int target, vector<vector<int>> &ans, vector<int> &subset, int &sum){
    //base case
    if(sum == target){
        ans.push_back(subset);
        return ;
    }
    if(i >= nums.size() || sum + nums[i] > target){
        return ;
    }

    //include 
    subset.push_back(nums[i]);
    sum += nums[i];
    solve(i+1, nums, target, ans, subset, sum);
    //backtrack
    subset.pop_back();
    sum -= nums[i];
    //skip duplicates
    while(i+1 < nums.size() && nums[i]==nums[i+1]){
        i++;
    }
    //exclude
    solve(i+1, nums, target, ans, subset, sum);
}

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        
        vector<vector<int>> ans;
        vector<int> subset;
        int sum = 0;

        //solving function
        solve(0, candidates, target, ans, subset, sum);

        return ans;
    }
};
