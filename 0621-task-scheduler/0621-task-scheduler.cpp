class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int answer = 1; 
        sort(tasks.begin(), tasks.end()); 
        map<char,int> hashMap; 
        priority_queue<int, vector<int>, greater<int>> pq; 
        for(int i = 0; i < tasks.size(); i++){
            if(hashMap.count(tasks[i])){
                hashMap[tasks[i]] = hashMap[tasks[i]] + n + 1; 
                pq.push(hashMap[tasks[i]]); 
            } else{
                hashMap[tasks[i]] = 0; 
                pq.push(0); 
            }
        }

        while(!pq.empty()){
            int top = pq.top(); 
            if(answer > top){
                pq.pop(); 
                answer++;
            } else{
                answer++; 
            }
        }


        return answer -1; 
    }
};