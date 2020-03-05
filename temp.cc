class Solution {
public:
    int uniquePaths(int m, int n) {
        int numsOfPaths[m][n];
        numsOfPaths[0][0] = 1;
        for(int i = 0; i<m;i++){
            for(int j = 0; j<n; j++){
                if(i != 0 && j!=0){
                    numsOfPaths[i][j] = 0;
                }
                if(i-1>=0){
                    numsOfPaths[i][j] += numsOfPaths[i-1][j];
                }
                if(j-1>=0){
                    numsOfPaths[i][j] += numsOfPaths[i][j-1];
                }
            }
        }
        return numsOfPaths[m-1][n-1];
    }
};
