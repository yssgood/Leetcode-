class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        sort(slots1.begin(),slots1.end()); 
        sort(slots2.begin(),slots2.end()); 
        int i = 0, j = 0; 
        while(i < slots1.size() && j < slots2.size()){
            // int start1 = slots1[i][0], end1 = slots1[i][1]; 
            // int start2 = slots2[j][0], end2 = slots2[j][1]; 
            // if(start1 + duration < start2) i++; 
            // else if(start2 + duration < start1) j++; 
            // else{
            //     if(start1 + duration <= end2 && start2 + duration <= end1) return {max(start1,start2), max(start1,start2) + duration}; 
            //     i++;
            //     j++; 
            // }
            int start = max(slots1[i][0],slots2[j][0]); 
            int end = min(slots1[i][1],slots2[j][1]); 

            if(end - start >= duration) return {start, start + duration}; 

            if(slots1[i][1] < slots2[j][1]) i++; 
            else j++; 

        }
        return {}; 
    }
};
