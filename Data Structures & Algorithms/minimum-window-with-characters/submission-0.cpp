class Solution {
public:
    string minWindow(string s, string t) {
        if(s.length()<t.length()) return "";
        int n = s.length();
        int ans = -1;
        int min_len = INT_MAX;
        unordered_map<char, int> need, have;
        for(auto c: t) need[c]++;
        //now we have mapped count of every character in string t
        int left = 0, need_count = need.size(), have_count = 0;
        for(int right=0; right<n; right++){
            if(need.contains(s[right])){     //if char is present in t
                have[s[right]]++;
                if(have[s[right]]==need[s[right]]){
                    have_count++;
                }
                while(have_count==need_count){
                    if(right-left+1 < min_len){
                        min_len = right-left+1;
                        ans = left;
                    }
                    if(need.contains(s[left])){
                        have[s[left]]--;
                        if(have[s[left]]<need[s[left]]) have_count--;
                    }
                    left++;
                }

            }
        }
        if(ans == -1) return "";
        return s.substr(ans, min_len);
    }
};
