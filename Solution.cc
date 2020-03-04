class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp;
        for(int i = 0; i <= cost.size(); i++){
            if(i == 0 || i == 1){
                dp.push_back(cost[i]);
            }
            else{
                if(dp[i-1] < dp[i-2]){
                    dp.push_back(dp[i-1]+cost[i]);
                }
                else{
                    dp.push_back(dp[i-2]+cost[i]);
                }
            }
        }
        if(dp.size() >= 2){
            if(dp[dp.size()-1] < dp[dp.size()-2]){
                return dp[dp.size()-1];
            }
            return dp[dp.size()-2];
        }
        else{
            return dp[0];
        }
    }
};
