class Solution {
    int dp[2501]; 
public:
    int dfs(vector<int>& nums, int index){
        int& ret = dp[index]; 
        if(ret != -1) return ret; 
        ret = 1; 
        for(int i = index+1; i < nums.size(); i++){
            if(nums[i] > nums[index]){
                ret = max(ret,1+dfs(nums,i)); 
            }
        }
        return ret; 
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int answer = INT_MIN; 
        memset(dp,-1,sizeof(dp)); 
        for(int i = 0; i < nums.size(); i++){
            answer = max(answer,dfs(nums,i)); 
        }
        return answer; 
    }
};
