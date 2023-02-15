class Solution {
    class Path{
        public int x; 
        public int y; 
        public int dist; 
        
        public Path(int x, int y, int dist){
            this.x = x; 
            this.y = y; 
            this.dist = dist; 
        }
    }
    int[][] dir = {{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}}; 
    public int shortestPathBinaryMatrix(int[][] grid) {
        if(grid[0][0] == 1) return -1; 
        Path path = new Path(0,0,-1); 
        boolean visited[][] = new boolean[grid.length][grid[0].length]; 
        visited[0][0] = true; 
        Queue<Path> q = new LinkedList<>(); 
        q.add(path); 
        
        while(!q.isEmpty()){
            int size = q.size(); 
            for(int i = 0; i < size; i++){
                Path first = q.poll(); 
                int x = first.x, y = first.y, dist = first.dist; 
                
                if(x == grid.length-1 && y == grid[0].length-1 && dist != -1){
                    return dist; 
                }
                
                for(int j = 0; j < 8; j++){
                    int nX = x + dir[j][0]; 
                    int nY = y + dir[j][1]; 
                    
                    if(nX < 0 || nX >= grid.length || nY < 0 || nY >= grid[0].length || visited[nX][nY] == true || grid[nX][nY] == 1) continue; 
                    if(dist == -1) dist = 1; 
                    visited[nX][nY] = true; 
                    q.add(new Path(nX,nY,dist+1)); 
                }
            }
        }

        return grid.length == 1 ? 1 : -1; 
    }
}