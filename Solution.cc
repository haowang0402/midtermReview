class Solution {
public:
    string longestPalindrome(string s) {
        bool dp[s.size()][s.size()];
        for(int i = 0; i<s.size();i++){
            dp[i][i] = true;
        }
        int index1 = 0;
        int index2 = 0;
        for(int i = 0; i<s.size()-1;i++){
            for(int j = i+1; j<s.size();j++){
                if(dp[i+1][j-1] && s.at(i) == s.at(j)){
                    dp[i][j] = true;
                    if(i - j > index1- index2){
                        index1 = i;
                        index2 = j;
                    }
                }
                   }
                   }
                   return s.substr(index1,index2-index1);
    }
};
