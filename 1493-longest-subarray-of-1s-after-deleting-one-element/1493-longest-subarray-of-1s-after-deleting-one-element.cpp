class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int can_delete = 0; 
        int start = 0, end = 0; 
        int answer = 0; 

        while(end < nums.size()){
            if(can_delete >= 1 && nums[end] == 0){
                while(start < nums.size() && can_delete >= 1){
                    can_delete -= nums[start] == 0 ? 1 : 0; 
                    start++; 
                }
            }

            can_delete += nums[end] == 0 ? 1 : 0; 

            answer = max(answer, (end - start)); 
            end++; 
        }


        return answer; 
    }
};