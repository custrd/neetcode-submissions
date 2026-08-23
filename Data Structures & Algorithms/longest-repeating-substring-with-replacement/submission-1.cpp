class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int left = 0, right = 0;
        int ans = 0, max_count = 0;
        unordered_map<char, int> mp;
        while(right < n){
            mp[s[right]]++;
            max_count = max(max_count, mp[s[right]]);
            if((right-left+1)-max_count > k){
                mp[s[left]]--;
                left++;
            }
            ans = max(ans, right-left+1);
            right++;
        }
        return ans;
    }
};