class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        map<int, vector<int>> mp;
        int n = nums.size();
        int cur = 1;
        for(int i=0; i<n-1; i++){
            if(nums[i+1]==nums[i]) cur++;
            else{
                mp[cur].push_back(nums[i]);
                cur=1;
            }
        }
        
        mp[cur].push_back(nums[n-1]);
        
        vector<int> ans;
        auto it = prev(mp.end());
        while(true){
            vector<int> t = it->second;
            int s = t.size();
            if(s<=k){ 
                for(int i=0; i<s; i++){
                    ans.push_back(t[i]);
                }
                k-=s;
                if(k==0) return ans;
            }else{
                for(int i=0; i<k; i++){
                    ans.push_back(t[i]);
                }
                return ans;
            }
            it--;
        }
        return ans;
    }
};
