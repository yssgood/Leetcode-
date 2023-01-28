class Solution {
public:
    string minWindow(string s, string t) {
        map<char,int> hashMap; 
        map<char,int> trackMap; 
        int length = INT_MAX; 
        for(char& c : t) hashMap[c]++; 
        int left = 0, right = 0, letters = 0; 
        string answer = ""; 
        while(right < s.length()){ 
            if(hashMap.count(s[right])){
                trackMap[s[right]]++; 
                if(trackMap[s[right]] <= hashMap[s[right]]){
                    letters++; 
                }
            }
            if(letters >= t.length()){
                while(!hashMap.count(s[left]) || trackMap[s[left]] > hashMap[s[left]]){
                    trackMap[s[left]]--;
                    left++; 
                }
                if(right - left + 1 < length){
                    length = right - left + 1;  
                    answer = s.substr(left, length); 
                }
            }
            right++; 
        }
        return answer; 
    }
};
