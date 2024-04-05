class Solution {
public:
    string makeGood(string s) {
        string answer = ""; 
        stack<char> charStack; 
        
        for(int i = 0; i < s.length(); i++){
            
            if(!charStack.empty() && tolower(charStack.top()) == tolower(s[i])){
                char a = charStack.top(), b = s[i]; 
                
                if(isupper(b) && islower(a) || islower(b) && isupper(a)){
                    charStack.pop(); 
                } else{
                    charStack.push(s[i]); 
                }
            } else{
                charStack.push(s[i]); 
            }
        }
        
        while(!charStack.empty()){
            answer += charStack.top();
            charStack.pop(); 
        }
        
        reverse(answer.begin(),answer.end());
        return answer; 
    }
};