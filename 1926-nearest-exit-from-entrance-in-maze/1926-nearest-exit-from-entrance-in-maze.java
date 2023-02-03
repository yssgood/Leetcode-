class Solution {
    int[][] dir = {{0,1},{0,-1},{1,0},{-1,0}}; 
    public int nearestExit(char[][] maze, int[] entrance) {
        boolean[][] visited = new boolean[maze.length][maze[0].length]; 
        for(int i = 0; i < maze.length; i++){
            Arrays.fill(visited[i],false); 
        }
        
        Queue<int[]> q = new LinkedList<>(); 
        q.add(new int[]{entrance[0],entrance[1],0});
        visited[entrance[0]][entrance[1]] = true; 
        while(!q.isEmpty()){
            int size = q.size(); 
            for(int i = 0; i < size; i++){
                int[] first = q.poll(); 
                int x = first[0], y = first[1], dist = first[2]; 
                if(dist != 0 && (x == 0 || x == maze.length -1 || y == 0 || y == maze[0].length-1)) return dist; 
                for(int[] d : dir){
                    int nX = x + d[0];
                    int nY = y + d[1]; 
                    
                    if(nX < 0 || nY < 0 || nX >= maze.length || nY >= maze[0].length || maze[nX][nY] == '+' || visited[nX][nY] == true) continue; 
                    
                    visited[nX][nY] = true;
                    q.add(new int[]{nX,nY,dist +1}); 
                }
            }
        }
        return -1; 
    }
}