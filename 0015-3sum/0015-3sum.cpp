class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> answer; 
        sort(nums.begin(),nums.end()); 
        //for(auto& n : nums) cout << n << ' '; 
        for(int i = 0; i < nums.size()-2; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue; 
            int start = i + 1, end = nums.size()-1; 
            while(start < end){
                int total = nums[i] + nums[start] + nums[end]; 
                if(end < nums.size()-1 && nums[start] == nums[start-1] && nums[end] == nums[end+1]){
                    end--; 
                }
                
                else if(total == 0){
                    answer.push_back({nums[i],nums[start],nums[end]}); 
                    start++; 
                    end--; 
                }
                
                else if(total > 0){
                    end--; 
                }
                
                else{
                    start++; 
                }
                
            }
        }
        return answer; 
    }
};