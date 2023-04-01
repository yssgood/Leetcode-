class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if(intervals.size() == 0 || intervals.size() == 1) return true; 
        sort(intervals.begin(),intervals.end()); 
        int end = intervals[0][1]; 
        for(int i = 1; i < intervals.size(); i++){
            if(end > intervals[i][0]) return false; 
            end = intervals[i][1]; 
        }
        return true; 
    }
};
