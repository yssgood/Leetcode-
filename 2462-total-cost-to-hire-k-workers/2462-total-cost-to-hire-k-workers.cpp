class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long answer = 0; 
        priority_queue<int, vector<int>, greater<int>> leftQ, rightQ; 

        int n = costs.size(); 
        if(n >= candidates * 2){
            for(int i = 0; i < candidates; i++){
                leftQ.push(costs[i]); 
                rightQ.push(costs[n - 1 - i]); 
            }
        } else{
            for(int i = 0; i < costs.size(); i++){
                leftQ.push(costs[i]); 
            }
        }

        int nextHead = candidates; 
        int nextTail = costs.size() - 1 - candidates; 
        int picked = 0; 
        //cout << leftQ.size() << ' ' << rightQ.size(); 
        while(picked < k){
            
            if(rightQ.empty() || !leftQ.empty() && leftQ.top() <= rightQ.top()){
                answer += leftQ.top();
                leftQ.pop(); 
                if(nextHead <= nextTail){
                    leftQ.push(costs[nextHead]); 
                    nextHead++; 
                }
            } else{
                answer += rightQ.top(); 
                rightQ.pop(); 
                if(nextTail >= nextHead){
                    rightQ.push(costs[nextTail]); 
                    nextTail--; 
                }
            }

            picked++;
        }

        return answer; 
    }
};