class Solution {
    public int minFallingPathSum(int[][] matrix) {
        if(matrix.length == 1) return matrix[0][0]; 
        int min1_, min2_, min3_, answer = Integer.MAX_VALUE; 
        for(int i = 1; i < matrix.length; i++){
            for(int j = 0; j < matrix[i].length; j++){
                min1_ = (j - 1 >= 0) ? matrix[i][j] + matrix[i-1][j-1] : Integer.MAX_VALUE; 
                min2_ = (j + 1 <= matrix[i].length - 1) ? matrix[i][j] + matrix[i-1][j+1] : Integer.MAX_VALUE; 
                min3_ = matrix[i][j] + matrix[i-1][j]; 
                matrix[i][j] = Math.min(min3_,Math.min(min1_,min2_)); 
            }
        }
        
        for(int n : matrix[matrix.length-1]) answer = Math.min(answer, n);
       
        return answer; 
    }
}