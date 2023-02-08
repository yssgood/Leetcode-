class Solution {
    public boolean flag = true; 
    public void dfs(int x, int y, int[][] matrix1, int[][] matrix2){
        if(x < 0 || x >= matrix2.length || y < 0 || y >= matrix2[0].length || matrix2[x][y] != 1) return; 
        if(matrix1[x][y] == 0) flag = false; 
        matrix2[x][y] = 2; 
        dfs(x + 1, y, matrix1, matrix2);
        dfs(x - 1, y, matrix1, matrix2); 
        dfs(x, y + 1, matrix1, matrix2); 
        dfs(x, y - 1, matrix1, matrix2); 
    }
    public int countSubIslands(int[][] grid1, int[][] grid2) {
        int cnt = 0;  
        for(int i = 0; i < grid2.length; i++){
            for(int j = 0; j < grid2[i].length; j++){
                if(grid2[i][j] == 1){
                    flag = true; 
                    dfs(i,j,grid1,grid2); 
                    if(flag) cnt++;  
                }
            }
        }
        
        
        
        
        return cnt; 
    }
}
