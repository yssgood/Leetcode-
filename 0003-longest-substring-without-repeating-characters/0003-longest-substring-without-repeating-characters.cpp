class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> hashMap; 
        int left = -1, right = 0, answer = 0;  
        while(right < s.length()){
            char c = s[right]; 
            if(hashMap.count(c) && hashMap[c] > left){
                left = hashMap[c]; 
            }
            answer = max(answer,right - left); 
            hashMap[c] = right; 
            right++; 
        }
        return answer;
    }
};