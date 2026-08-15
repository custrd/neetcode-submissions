class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";
        for(auto c: s){
            if(isalnum(c)) str+=c;
        }
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        int n= str.length();
        int lo=0, hi=n-1;
        while(lo<=hi){
            if(str[lo]!=str[hi]) return false;
            lo++; hi--;
        }
        return true;
    }
};
