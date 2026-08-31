class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = 9;
        vector<vector<unordered_set<int>>> box(3, vector<unordered_set<int>>(3));
        for(int i=0; i<n; i++){
            unordered_set<int> s_row, s_col;
            for(int j=0; j<n; j++){
                if(board[i][j]!='.'){
                    int num = (int)board[i][j];
                    if(s_row.contains(num)) return false;
                    s_row.insert(num);
                    if(box[i/3][j/3].contains(num)) return false;
                    box[i/3][j/3].insert(num);
                }
                if(board[j][i]!='.'){
                    int num = (int)board[j][i];
                    if(s_col.contains(num)) return false;
                    s_col.insert(num);
                }
            }
        }
        
        return true;
    }
};
