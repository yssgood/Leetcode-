class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> answer = new LinkedList<>(); 
        int left = 0, right = matrix[0].length-1, top = 0, bottom = matrix.length-1; 
        int dir = 1; 
        while(left <= right && top <= bottom){
            if(dir == 1){
                for(int i = left; i <= right; i++) answer.add(matrix[top][i]); 
                top++; 
                dir = 2; 
            }
            else if(dir == 2){
                for(int i = top; i <= bottom; i++) answer.add(matrix[i][right]);
                right--; 
                dir = 3; 
            }
            else if(dir == 3){
                for(int j = right; j >= left; j--) answer.add(matrix[bottom][j]); 
                bottom--; 
                dir = 4; 
            }
            else if(dir == 4){
                for(int i = bottom; i >= top; i--) answer.add(matrix[i][left]); 
                left++;  
                dir = 1; 
            }
        }
        return answer; 
    }
}