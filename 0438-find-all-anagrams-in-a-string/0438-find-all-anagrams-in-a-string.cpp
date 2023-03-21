class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> answer; 
        unordered_map<char,int> s1; 
        unordered_map<char,int> p1; 
        for(char& c: p) p1[c]++; 
        for(int i = 0; i < p.length(); ++i){
            s1[s[i]]++; 
        }
        if(s1 == p1) answer.push_back(0); 
        for(int i = p.length(); i < s.length(); ++i){
            s1[s[i]]++; 
            s1[s[i-p.length()]]--; 
            if(s1[s[i-p.length()]] == 0) s1.erase(s[i-p.length()]); 
            if(s1 == p1) answer.push_back(i-p.length()+1); 
        }
        
        
        return answer; 
    }
};