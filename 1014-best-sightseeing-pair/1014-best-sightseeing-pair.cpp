class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& val) {
        int n = val.size();
        vector<int> vec(n,0);
        vec[1] = val[0]+val[1]-1;
        int ans = vec[1];
        for(int i=2;i<n;i++){
            vec[i] = max(vec[i-1]-val[i-1]+val[i]-1,val[i-1]+val[i]-1);
            ans = max(vec[i],ans);
        }
        return ans;
    }
};