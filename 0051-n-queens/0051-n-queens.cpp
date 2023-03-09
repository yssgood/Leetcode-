class Solution {
    vector<pair<int,int>> dir = {{1,0},{1,1},{1,-1}}; 
void changePath(vector<vector<int>>& visited, int index, int i, bool makeTrue){
    int N = visited.size(); 
    int tmpX = index, tmpY = i; 
    for(int i = 0; i < N; i++){
        tmpX += dir[0].first;
        tmpY += dir[0].second; 
        
        if(tmpX < 0 || tmpX >= N || tmpY < 0 || tmpY >= N) continue;
        
        if(makeTrue) visited[tmpX][tmpY] += 1;
        if(!makeTrue) visited[tmpX][tmpY] -= 1; 
    }
    tmpX = index, tmpY = i; 
    for(int i = 0; i < N; i++){
        tmpX += dir[1].first;
        tmpY += dir[1].second; 
        
        if(tmpX < 0 || tmpX >= N || tmpY < 0 || tmpY >= N) continue;
        
        if(makeTrue) visited[tmpX][tmpY] += 1;
        if(!makeTrue) visited[tmpX][tmpY] -= 1; 
    }
    tmpX = index, tmpY = i; 
    for(int i = 0; i < N; i++){
        tmpX += dir[2].first;
        tmpY += dir[2].second; 
        
        if(tmpX < 0 || tmpX >= N || tmpY < 0 || tmpY >= N) continue;
        
        if(makeTrue) visited[tmpX][tmpY] += 1;
        if(!makeTrue) visited[tmpX][tmpY] -= 1; 
    }
}
public:
    void dfs(vector<vector<string>>& board, vector<vector<int>>& visited, int index, vector<vector<string>>& answer){
        if(index >= board.size()){
            vector<string> tmp; 
            for(vector<string>& v : board){
                string t = ""; 
                for(string& s : v){
                    if(s != "Q") t += '.';
                    else t += 'Q'; 
                }
                tmp.push_back(t); 
            }
            answer.push_back(tmp); 
            return; 
        }
        
        // for(int i = 0; i < visited.size(); i++){
        //     for(int j = 0; j < visited.size(); j++){
        //         cout << visited[i][j] << ' '; 
        //     }
        //     cout << endl; 
        // }
        // cout << endl; 
        
        for(int i = 0; i < board[0].size(); i++){
            if(!visited[index][i]){
                //visited[index][i] = true; 
                visited[index][i] += 1; 
                board[index][i] = 'Q'; 
                changePath(visited,index,i,true); 
                dfs(board,visited,index+1,answer); 
                //visited[index][i] = false; 
                visited[index][i] -= 1; 
                board[index][i] = '.'; 
                changePath(visited,index,i,false); 
                // cout << "AFTER:" << endl; 
                // for(int i = 0; i < visited.size(); i++){
                //     for(int j = 0; j < visited.size(); j++){
                //         cout << visited[i][j] << ' '; 
                //     }
                //     cout << endl; 
                // }
                // cout << endl; 
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> answer; 
        string s(1,'.'); 
        vector<vector<string>> board(n,vector<string>(n,s)); 
        vector<vector<int>> visited(n,vector<int>(n,0)); 
        
        dfs(board,visited,0,answer); 
        
        return answer; 
    };
};