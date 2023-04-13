class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        vector<vector<int>> answer; 
        for(vector<int>& v : intervals){
            int start = v[0], end = v[1]; 
            if(toBeRemoved[0] > start){
                answer.push_back({start,min(toBeRemoved[0],end)});
            }
            if(toBeRemoved[1] < end){
                answer.push_back({max(start,toBeRemoved[1]),end});
            }
        }
        return answer; 
    }
};
