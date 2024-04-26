class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        //if(s.empty() && t.empty()) return false; 

        if(s.length() > t.length()){
            return isOneEditDistance(t,s); 
        }

        for(int i = 0; i < s.length(); i++){
            if(s[i] != t[i]){
                if(s.length() == t.length()){ //replace 
                    return s.substr(i+1) == t.substr(i+1); 
                } else if(t.length() > s.length()) { //insert 
                    return s.substr(i) == t.substr(i+1); 
                } 
            }
        }


        return (s.length() + 1 == t.length()); 
    }
};