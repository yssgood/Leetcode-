class Solution {
    public static int[][] matrix; 
    public void dfs(int x, int y, int oldColor, int newColor){
        if(x < 0 || x >= matrix.length || y < 0 || y >= matrix[0].length || matrix[x][y] != oldColor) return; 
        matrix[x][y] = newColor; 
        dfs(x + 1, y, oldColor, newColor); 
        dfs(x - 1, y, oldColor, newColor); 
        dfs(x, y + 1, oldColor, newColor); 
        dfs(x, y -1, oldColor, newColor); 
    }
    public int[][] floodFill(int[][] image, int sr, int sc, int color) {
        matrix = image; 
        if(image[sr][sc] == color) return image; 
        dfs(sr,sc,image[sr][sc],color); 
        return matrix; 
    }
}
