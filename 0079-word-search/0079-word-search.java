class Solution {
    boolean flag = false; 
    public boolean dfs(int i, int j, char[][] board, boolean[][] visited, String word, int index){
        if(i < 0 || i >= board.length || j < 0 || j >= board[0].length || visited[i][j] == true || board[i][j] != word.charAt(index)) return false; 
        if(index == word.length()-1) return true; 
        visited[i][j] = true; 
        
        flag = (dfs(i+1,j,board,visited,word,index+1) || dfs(i-1,j,board,visited,word,index+1) || dfs(i,j+1,board,visited,word,index+1) || dfs(i,j-1,board,visited,word,index+1)); 
        
        visited[i][j] = false; 
        
        return flag; 
    }
    public boolean exist(char[][] board, String word) {
        boolean[][] visited = new boolean[board.length][board[0].length]; 
        for(int i = 0; i < board.length; i++){
            for(int j = 0; j < board[0].length; j++){
                if(board[i][j] == word.charAt(0) && dfs(i,j,board,visited,word,0)){
                    return true; 
                }
            }
        }
        return false;  
    }
}