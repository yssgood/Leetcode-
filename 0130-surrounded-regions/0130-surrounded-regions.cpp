class Solution {

public:
    void dfs(vector<vector<char>>& board, int i, int j){
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] == 'X' || board[i][j] == 'I') return; 

        board[i][j] = 'I'; 

        dfs(board,i+1,j); 
        dfs(board,i-1,j); 
        dfs(board,i,j+1);
        dfs(board,i,j-1); 
    }
public:
    void solve(vector<vector<char>>& board) {
        bool flag = false; 
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                if(board[i][j] != 'X' && (i == 0 || j == 0 || i == board.size()-1 || j == board[0].size()-1)){
                    board[i][j] = 'Z'; 
                }
            }
        }

        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                if(board[i][j] == 'Z'){
                    dfs(board,i,j); 
                }
            }
        }

        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                if(board[i][j] == 'O') board[i][j] = 'X'; 
                if(board[i][j] == 'I') board[i][j] = 'O'; 
            }
        }
    }
};