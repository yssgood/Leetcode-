class Solution {
public:
    string rankTeams(vector<string>& votes) {
        map<char,vector<int>> hashMap; 
        string answer = votes[0]; 
        for(char& c : votes[0]){
            vector<int> tmp(votes[0].length(), 0);
            hashMap[c] = tmp; 
        }
        
        for(string& s : votes){
            for(int i = 0; i < s.length(); i++){
                hashMap[s[i]][i]++; 
            }
        }
        
        
        sort(answer.begin(), answer.end(), [&hashMap](char& a, char& b){
            if(hashMap[a] == hashMap[b]) return a < b; 
            return hashMap[a] > hashMap[b]; 
        });
        
        
        
        return answer;
    }
};