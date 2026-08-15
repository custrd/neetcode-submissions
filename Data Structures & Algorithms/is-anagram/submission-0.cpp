class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> ms, mt;
        
        for(int i=0; i<s.length(); i++){
            ms[s[i]]++;
        }
        for(int i=0; i<t.length(); i++){
            mt[t[i]]++;
        }

        for(auto p: ms){
            char key = p.first;
            int count = p.second;
            auto it = mt.find(key);
            if(it==mt.end() || it->second != count){
                return false;
            }
        }

        for(auto p: mt){
            char key = p.first;
            int count = p.second;
            auto it = ms.find(key);
            if(it==ms.end() || it->second != count){
                return false;
            }
        }

        return true;
    }
};