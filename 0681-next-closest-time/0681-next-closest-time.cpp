class Solution {
public:
    string answer = ""; 
    int getMinute(string& time){
        int hh = stoi(time.substr(0,2)); 
        int mm = stoi(time.substr(3,2)); 
        
        return (hh * 60) + mm; 
    }
    
    void findClosest(vector<char>& digits, string& tmp, int startTime, int index, int& currTime){
        if(tmp.length() == 4){
            if(stoi(tmp.substr(0,2)) > 23 || stoi(tmp.substr(2)) > 59) return; 
            string someTmp = tmp.substr(0,2) + ":" + tmp.substr(2); 
            int tmpMinute = getMinute(someTmp); 
            
            if(tmpMinute > startTime){
                if(tmpMinute - startTime < currTime){
                    currTime = tmpMinute - startTime; 
                    answer = someTmp; 
                }
            } else if(tmpMinute < startTime){
                string day = "24:00"; 
                int dayMinute = getMinute(day); 
                if(tmpMinute + dayMinute < currTime){
                    currTime = tmpMinute + dayMinute; 
                    answer = someTmp; 
                }
            }
            
            
            return; 
        }
        
        for(int i = 0; i < digits.size(); i++){
            tmp += digits[i]; 
            findClosest(digits,tmp,startTime,i,currTime);  
            tmp.pop_back(); 
        }
    }
    
    string nextClosestTime(string time) {
        int startTime = getMinute(time); 
        vector<char> digits; 
        for(char& c : time){
            if(c != ':') digits.push_back(c); 
        }
        
        answer = time; 
        string tmp = ""; 

        int currTime = INT_MAX; 
        findClosest(digits,tmp,startTime,0,currTime); 
        
        
        return answer; 
    }
};