class Solution {
public:
    string minWindow(string s, string t) {
        map<char,int> forS, forT; 
        for(char& c : t) forT[c]++; 
        int start = 0, end = 0, count = 0, curr_count = INT_MAX, begin = 0; 
        while(end < s.length()){
            forS[s[end]]++; 
            if(forT.count(s[end]) && forT[s[end]]-- > 0) count++; 

            while(count == t.length()){
                //answer = curr_count >= s.substr(start,end - start + 1).length() ? s.substr(start,end - start + 1) : answer; 
                if(end - start < curr_count){
                    curr_count = end - start;
                    begin = start; 
                }
                forS[s[start]]--; 
                if(forT.count(s[start]) && forT[s[start]]++ == 0) count--; 
                start++; 
            }
            end++; 
        }
        return curr_count == INT_MAX ? "" : s.substr(begin,curr_count+1); 
    }
};



