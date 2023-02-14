class Solution {
    public int minimumEffortPath(int[][] heights) {
        int[][] matrix = new int[heights.length][heights[0].length];
        for(int i = 0; i < heights.length; i++){
            Arrays.fill(matrix[i],Integer.MAX_VALUE); 
        }
        
        matrix[0][0] = 0; 
        int[][] dir = new int[][]{{0,1},{0,-1},{1,0},{-1,0}}; 
        Queue<int[]> q = new LinkedList<>(); 
        q.add(new int[]{0,0,Integer.MIN_VALUE}); 
        while(!q.isEmpty()){
            int size = q.size(); 
            for(int i = 0; i < size; i++){
                int[] first = q.poll(); 
                int x = first[0], y = first[1], dist = first[2]; 
                
                for(int j = 0; j < 4; j++){
                    int nX = x + dir[j][0]; 
                    int nY = y + dir[j][1]; 
                    
                    if(nX < 0 || nX >= heights.length || nY < 0 || nY >= heights[0].length) continue; 
                    // System.out.print(heights[nX][nY]); 
                    // System.out.println(Math.abs(heights[nX][nY] - heights[x][y]));
                    int nDist = Math.max(dist,Math.abs(heights[nX][nY] - heights[x][y]));
                    if(nDist < matrix[nX][nY]){
                        matrix[nX][nY] = nDist; 
                        q.add(new int[]{nX,nY,nDist}); 
                    }
                }
            }
        }
        
        // for(int i = 0; i < heights.length; i++){
        //     for(int j = 0; j < heights[0].length; j++){
        //         System.out.print(matrix[i][j]); 
        //         System.out.print(' '); 
        //     }
        //     System.out.println(); 
        // }
        return matrix[heights.length-1][heights[0].length-1]; 
    }
}