class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> answer; 
        vector<bool> pos(nums.size(),false); 
        int sum = 0; 
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] % 2 == 0){
                sum += nums[i]; 
                pos[i] = true; 
            }
        }
        
        for(vector<int>& v : queries){
            int add = v[0], index = v[1]; 
            int tmp = nums[index] + add; 
            if(abs(tmp) % 2 == 0 && !pos[index]){
                sum += tmp;
                pos[index] = true; 
            }
            else if(abs(tmp) % 2 == 0 && pos[index]){
                sum += add; 
            }
            else if(abs(tmp) % 2 == 1 && pos[index]){
                sum -= nums[index]; 
                pos[index] = false; 
            }
            answer.push_back(sum); 
            nums[index] = tmp; 
        }
        
        return answer; 
    }
};