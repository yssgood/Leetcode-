class Solution {
public:
    string removeStars(string s) {
        stack<char> charStack; 

        for(char& c : s){
            if(c == '*'){
                charStack.pop(); 
            } else{
                charStack.push(c); 
            }
        }

        string answer = ""; 
        while(!charStack.empty()){
            char c = charStack.top();
            charStack.pop();  
            answer += c; 
        }

        if(!answer.empty()) reverse(answer.begin(),answer.end()); 

        return answer; 
    }
};