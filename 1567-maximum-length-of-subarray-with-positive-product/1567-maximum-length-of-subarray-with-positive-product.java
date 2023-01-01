class Solution {
    public int getMaxLen(int[] nums) {
        int[][] dp = new int[nums.length][2]; 
        if(nums[0] > 0) dp[0][0]++; 
        if(nums[0] < 0) dp[0][1]++; 
        
        int answer = dp[0][0]; 
        
        for(int i = 1; i < nums.length; i++){
            if(nums[i] != 0){
                if(nums[i] > 0){
                    dp[i][0] = dp[i-1][0] + 1; 
                    if(dp[i-1][1] > 0) dp[i][1] = 1+dp[i-1][1];
                }
                else{
                    if(dp[i-1][1] > 0) dp[i][0] = dp[i-1][1] + 1; 
                    dp[i][1] = dp[i-1][0] + 1; 
                }
            }
            answer = Math.max(answer,dp[i][0]); 
        }
        
        return answer; 
    }
}