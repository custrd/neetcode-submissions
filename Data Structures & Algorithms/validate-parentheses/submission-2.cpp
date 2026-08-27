class Solution {
public:
    bool isValid(string s) {
        vector<char> stk;
        for(auto c: s){
            if(c=='(' || c=='{' || c=='[') stk.push_back(c);
            else{
                if(stk.size()!=0){
                    char top = stk[stk.size()-1];
                    if(c==')' && top=='(') stk.pop_back();
                    else if(c=='}' && top=='{') stk.pop_back();
                    else if(c==']' && top=='[') stk.pop_back();
                    else stk.push_back(c);
                }
                else stk.push_back(c);
            }
        }
        if(stk.size()==0) return true;
        return false;
    }
};
