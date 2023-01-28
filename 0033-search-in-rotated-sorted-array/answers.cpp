class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int mid, left=0, right=nums.size();
        
        int start = nums[0];
        int pivot = 0;
        
        if(nums.size()<3){
            for(int i=0; i<nums.size();i++)
            {
                if(target == nums[i])
                    return i;
            }
            return -1;
        }
        
        
        while(left<right){
            mid=left+(right-left)/2;
            
            if(nums[mid]>=start){
                left=mid+1;
            }
            else if(nums[mid]<start){
                right=mid;
            }
            
        }
        pivot =left;

        
        if(start>target){
            left = pivot;
            right = nums.size();
        } else{
            right = pivot;
            left = 0;
        }
        
        while(left<=right){
            mid=left+(right-left)/2;
            
            if(nums[mid]<target){
                left=mid+1;
            }
            else if(nums[mid]>target){
                right=mid-1;
            }
            else if(target == nums[mid]){
                return mid;
            }
        }
        return -1;
    }
};
