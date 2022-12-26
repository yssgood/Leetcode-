class Solution {
    public int deleteAndEarn(int[] nums) {
        int[] dp = new int[10002];
        List<Integer> container = Arrays.stream(nums).boxed().toList(); 
        int lastNum = Collections.max(container); 
        for(int i = 0; i < nums.length; i++){
            dp[nums[i]] += nums[i];
        }

        for(int i = 2; i <= lastNum; i++){
            dp[i] = Math.max(dp[i-1], dp[i-2] + dp[i]); 
        }
        return dp[lastNum]; 
    }
}