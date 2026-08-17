class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        long long prod=1;
        int zero_count =0, flag1 = false;  //flag0 for checking if zero appeared or not and flag1 for non-zero int
        for(auto e: nums){
            if(e!=0){
                prod*=e;  //for non-zero int
                flag1 = true;
            }
            else{
                zero_count++;
            }
            
        }
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(zero_count){
                if(nums[i]!=0) ans.push_back(0);
                else if(nums[i]==0){
                    if(zero_count==1)ans.push_back(prod);
                    else ans.push_back(0);
                }
            }else{
                ans.push_back(prod/nums[i]);
            }
        }
        return ans;
    }
};
