class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& grid, vector<char>& tmp, set<vector<char>>& dSet, char d){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != 1) return; 
        grid[i][j] = 2; 
        
        tmp.push_back(d); 

        dfs(i + 1, j, grid, tmp, dSet, 'D'); 
        dfs(i -1, j , grid, tmp, dSet, 'U'); 
        dfs(i,j +1, grid, tmp, dSet, 'R'); 
        dfs(i,j -1, grid, tmp, dSet, 'L'); 

        tmp.push_back('X');
    }
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        set<vector<char>> dSet; 
        vector<char> tmp; 
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 1){
                    dfs(i,j,grid,tmp,dSet,'S'); 
                    dSet.insert(tmp); 
                    tmp.clear(); 
                }
            }
        }

        for(vector<char> t : dSet){
            for(char c : t){
                cout << c << ' '; 
            }
            cout << endl; 
        }
        return dSet.size(); 
    }
};
