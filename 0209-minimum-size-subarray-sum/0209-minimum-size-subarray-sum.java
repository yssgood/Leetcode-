class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        
        int start = 0, end = 0, tmp = 0, answer = Integer.MAX_VALUE; 
        while(end < nums.length){
            tmp += nums[end]; 
            while(tmp >= target){
                answer = Math.min(answer,end - start + 1); 
                tmp -= nums[start]; 
                start++; 
            }
            end++; 
        }
        return answer == Integer.MAX_VALUE ? 0 : answer; 
    }
}