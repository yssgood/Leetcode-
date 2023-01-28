class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = prices[0]; 
        int answer = INT_MIN; 
        for(int i = 1; i < prices.size(); i++){
            answer = max(answer, prices[i] - min_price);
            min_price = min(min_price, prices[i]); 
        }
        return answer < 0 ? 0 : answer; 
    }
};
