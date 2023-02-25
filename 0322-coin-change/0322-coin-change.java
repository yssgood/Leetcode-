class Solution {
    public int coinChange(int[] coins, int amount) {
        int[] dp = new int[amount+1]; 
        //Arrays.fill(dp,Integer.MAX_VALUE - 1); 
        for(int i = 0; i <= amount; i++) dp[i] = Integer.MAX_VALUE -1; 
        // for(int i = 0; i < coins.length; i++){
        //     dp[coins[i]] = 1; 
        // }
        dp[0] = 0; 
        for(int i = 0; i < coins.length; i++){
            for(int j = coins[i]; j <= amount; j++){
                if(j == coins[i]){
                    dp[j] = 1; 
                    continue; 
                }
                dp[j] = Math.min(dp[j], dp[j - coins[i]] + 1); 
            }
        }
        
        if(dp[amount] == Integer.MAX_VALUE - 1) return -1; 
        return dp[amount]; 
    }
}
