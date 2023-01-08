class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hashMap;
        for(int i = 0; i < nums.size(); i++){
            int find = target - nums[i]; 
            if(hashMap.count(find)){
                return {hashMap[find],i};
            }
            hashMap[nums[i]] = i; 
        }
        return {0,0}; 
    }
};