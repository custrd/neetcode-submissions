class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";
        for(auto s: strs){
            int n = s.length();
            ans.append(to_string(n));
            ans.append("#");
            ans.append(s);
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int n = s.length();
        int i=0;
        string x = "";
        while(i<n){
            if(s[i]=='#'){
                int num = stoi(x);
                string str = s.substr(i+1, num);
                ans.push_back(str);
                i+=num+1;
                x="";
            }else{
                x+=s[i]; i++;
            }
        }
        return ans;
    }
};
