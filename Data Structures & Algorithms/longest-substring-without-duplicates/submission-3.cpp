class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int left = 0, right = 0;
        int ans = 0, cur = 0;
        unordered_map<char, int> mp; 
        while(right <= n-1){
            // string str = s.substr(left, (right-left));
            char key = s[right];
            if(mp.find(key) == mp.end()){
                cur++;
                mp[s[right]]++;
            }else{
                while(mp.find(key)!=mp.end()){  //the key is present in the map
                    mp.erase(s[left]);
                    
                    left++;
                    // cur=0;
                }
                mp[key]++;
                cur = right-left+1;
                
            }
            ans = max(ans, cur);
            right++;
        }
        ans = max(ans, cur);
        return ans;
    }
};
