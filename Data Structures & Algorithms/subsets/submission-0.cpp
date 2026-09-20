void solve(int i, vector<int> &nums, vector<vector<int>> &ans, vector<int> &subset){
    if(i==nums.size()){
        ans.push_back(subset);
        return;
    }

    //include
    subset.push_back(nums[i]);
    solve(i+1, nums, ans, subset);

    //exclude
    subset.pop_back();
    solve(i+1, nums, ans, subset);
}

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;

        solve(0, nums, ans, subset);
        return ans;
    }
};
