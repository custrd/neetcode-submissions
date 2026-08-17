class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        set<int> s;
        for(auto e: nums){
            s.insert(e);
        }
        int cur=1, ans=1;
        auto it = s.begin();
        it++;
        while(it!=s.end()){
            int x = *prev(it);
            if(*it == x+1){
                cur++;
            }else {
                ans = max(ans, cur);
                cur=1;
            }
            it++;
        }
        ans = max(ans, cur);
        return ans;
    }
};
