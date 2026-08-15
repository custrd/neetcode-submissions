class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;

        unordered_map<char, int> ms, mt;
        for(int i=0; i<s.length(); i++){
            ms[s[i]]++;
            mt[t[i]]++;
        }

        if(ms==mt) return true;
        else return false;
    }
};
