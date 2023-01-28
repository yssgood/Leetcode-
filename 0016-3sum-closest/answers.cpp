class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int result = nums[0] + nums[1] + nums[nums.size()-1];
        sort(nums.begin(), nums.end());
        //(-4,-1,1,2)
        for (int i = 0; i < nums.size()-2; ++i){
            int low = i+1;
            int high = nums.size()-1; 
            //sum = nums[i] + nums[low] + nums[high];
            while(low<high){
                int sum = nums[i] + nums[low] + nums[high];
                if (sum>target){
                    high--;
                }
                else{
                    low++;
                }
                if (abs(sum-target)< abs(result-target)){
                    result = sum;
                }
            }
        }
        return result;
    }
};
