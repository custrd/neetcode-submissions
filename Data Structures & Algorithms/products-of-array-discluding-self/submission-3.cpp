class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans, pre;
        vector<int> post(n);
        
        //building pre
        for(int i=0; i<n; i++){
            if(i==0) pre.push_back(nums[i]);
            else{
                int x = nums[i] * pre[i-1];
                pre.push_back(x);
            }
        }
        //building post
        for(int i=n-1; i>=0; i--){
            if(i==n-1) post[i]=nums[i];
            else{
                post[i] = post[i+1]*nums[i];
            }
        }

        pre.push_back(1);
        pre.insert(pre.begin(), 1);
        post.push_back(1);
        post.insert(post.begin(),1);

        for(int i=1; i<=n; i++){
            ans.push_back(pre[i-1]*post[i+1]);
        }

        return ans;
    }
};
