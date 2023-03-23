class Solution {
public:
    void dfs(int n, int k, string s, vector<int>& answer){
        if(s.length() == n){
            answer.push_back(stoi(s));
            return; 
        }
        for(int i = 0; i < 10; i++){
            if(i == 0 && s.empty() || !s.empty() && abs((s[s.length()-1] - '0') - i) != k) continue; 
            s += (i + '0'); 
            dfs(n,k,s,answer);
            s.pop_back(); 
        }
    }
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> answer; 
        dfs(n,k,"",answer); 
        return answer; 
    }
};