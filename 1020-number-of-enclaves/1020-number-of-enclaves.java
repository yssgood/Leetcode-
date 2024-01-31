class Solution {

    public void dfs(int i, int j, int[][] grid){
        if(i < 0 || j < 0 || i >= grid.length || j >= grid[i].length || grid[i][j] != 1) return;  

        grid[i][j] = 0; 

        dfs(i+1,j,grid);
        dfs(i-1,j,grid);
        dfs(i,j+1,grid);
        dfs(i,j-1,grid); 
    }
    public int numEnclaves(int[][] grid) {
        int answer = 0; 
        for(int i = 0; i < grid.length; i++){
            for(int j = 0; j< grid[i].length; j++){
                if(i == 0 || j == 0 || i == grid.length-1 || j == grid[i].length-1){
                    dfs(i,j,grid); 
                }
            }
        }

        for(int i = 0; i < grid.length; i++){
            for(int j = 0; j < grid[i].length; j++){
                if(grid[i][j] == 1){
                    answer++; 
                }
            }
        }

        return answer; 
    }
}