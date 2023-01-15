class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        reverse(nums.begin(),nums.end()); 
        int start = 0, end = (k%nums.size())-1;
        while(start <= end) swap(nums[start++],nums[end--]); 
        reverse(nums.begin()+(k%nums.size()),nums.end()); 
        
        //for(int& n: nums) cout << n << ' '; 
    }
};