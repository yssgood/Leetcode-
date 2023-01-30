class Solution {
    public int nthUglyNumber(int n) {
        if(n == 1) return 1; 
        int[] dp = new int[n]; 
        dp[0] = 1; 
        //int first =1, second = 1, third =1; 
        int first = 0, second = 0, third = 0; 
        for(int i = 1; i < n; i++){
            //int min_ = Math.min(first * 2, Math.min(second * 3, third * 5)); 
            int min_ = Math.min(dp[first] * 2, Math.min(dp[second] * 3, dp[third] * 5)); 
            dp[i] = min_; 
            // if(min_ % 2 == 0) first = dp[i]; 
            // if(min_ % 3 == 0) second = dp[i];
            // if(min_ % 5 == 0) third = dp[i]; 
            
            if(dp[i] == dp[first] * 2) first++; 
            if(dp[i] == dp[second] * 3) second++; 
            if(dp[i] == dp[third] * 5) third++; 

        }
        
        
        return dp[n-1]; 
    }
}

