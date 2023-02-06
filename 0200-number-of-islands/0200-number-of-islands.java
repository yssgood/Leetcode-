class Solution {
    public static char[][] matrix; 
    public void dfs(int i, int j){
        if(i < 0 || i >= matrix.length || j < 0 || j >= matrix[0].length || matrix[i][j] == '0') return; 
        matrix[i][j] = '0'; 
        dfs(i+1,j);
        dfs(i-1,j);
        dfs(i,j+1);
        dfs(i,j-1); 
    }
    public int numIslands(char[][] grid) {
        int cnt = 0; 
        matrix = grid; 
        for(int i = 0; i < grid.length; i++){
            for(int j = 0; j < grid[i].length; j++){
                if(grid[i][j] == '1'){
                    cnt++; 
                    dfs(i,j); 
                }
            }
        }
        return cnt; 
    }
}