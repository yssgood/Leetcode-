class Solution {
public:
    string longestPalindrome(string s) {

        string answer = "";
        int mid;
        int len;
        int best_len = 0; 
        int n = s.length();
        for (mid=0; mid < n; mid++){
            for (int x = 0; mid-x >= 0 && mid+x <n; x++){
                if (s[mid-x] != s[mid+x]){
                    break; 
                }
                len = 2*x +1;
                if (len>best_len){
                    best_len = len; 
                    answer = s.substr(mid-x,len);
                }
            }
        }
        for (mid = 0; mid < n-1; mid++){
            for (int x = 1; mid-x+1 >=0 && mid+x < n; x++){
                if (s[mid-x+1]!=s[mid+x]){
                    break;
                }
                len = 2*x;
                if (len>best_len){
                    best_len = len; 
                    answer = s.substr(mid-x+1,len);
                }
            }
        }
        return answer; 
    }
};
