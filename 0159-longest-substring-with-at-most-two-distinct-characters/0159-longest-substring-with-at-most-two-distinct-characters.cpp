class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        map<char,int> hashMap; 
        int answer =  INT_MIN, start = 0, end = 0; 

        while(end < s.length()){
            hashMap[s[end]]++; 
            while(hashMap.size() > 2){
                hashMap[s[start]]--; 
                if(hashMap[s[start]] == 0) hashMap.erase(s[start]); 
                start++; 
            }

            if(hashMap.size() <= 2){
                answer = max(answer, end - start + 1); 
            }
            end++; 
        }

        return answer; 
    }
};