class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
           set<char> row,col;
           for(int j=0;j<9;j++){
            if(board[i][j]!='.'){
            if(row.find(board[i][j])!=row.end()) return 0;
            row.insert(board[i][j]);
            }
            if(board[j][i]!='.'){
                if(col.find(board[j][i])!=col.end()) return 0;
                col.insert(board[j][i]);
            }
           }    
        }
        for(int i=0;i<9;i+=3){
            for(int j=0;j<9;j+=3){
                set<char> st;
                for(int k=i;k<(i+3);k++){
                    for(int p=j;p<(j+3);p++){
                        if(board[k][p]!='.'){
                            if(st.find(board[k][p])!=st.end()) return 0;
                            st.insert(board[k][p]);
                        }
                    }
                }
            }
        }
        return 1;
    }
};