bool checkValid(int idx, int val, int n, vector<int> &queens){
    for(int i=0; i<idx; i++){
        if(abs(idx-i) == abs(val-queens[i])) return false;
        if(i==idx || queens[i]==val) return false;
    }
    return true;
}

void solve(int idx, int val, int n, vector<int> &queens, vector<vector<string>> &res){
    if(idx==n){
        vector<string> vec;
        for(int i=0; i<n; i++){
            string str="";
            for(int j=0; j<n; j++){
                if(j==queens[i]) str+='Q';
                else str+='.';
            }
            vec.push_back(str);
        }
        res.push_back(vec);
        return ;
    }
    if(val==n) return ;

    if(checkValid(idx, val, n, queens)){
        queens[idx]=val;
        solve(idx+1, 0, n, queens, res);
        queens[idx]=-1;
    }

    return solve(idx, val+1, n, queens, res);
}

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<int> queens(n);

        solve(0, 0, n, queens, res);
        return res;
    }
};
