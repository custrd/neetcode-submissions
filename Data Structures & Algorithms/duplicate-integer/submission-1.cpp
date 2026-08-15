class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for(auto e: nums){
            auto it= s.find(e);
            if(it!=s.end()) return true;
            else s.insert(e);
        }
        return false;
    }
};