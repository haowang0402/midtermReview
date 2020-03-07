#include <string>
#include <math.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;


void buffyText(vector<string> texts, int M){
  int extraspaces[texts.size()][texts.size()];
  int cost[texts.size()][texts.size()];
  int dp[texts.size()+1];
  int cut[texts.size()];
  for(int i = 0; i<texts.size();i++){
    extraspaces[i][i] = M -texts[i].size();
    for(int j = i+1 ; j<texts.size();j++){
      extraspaces[i][j] = extraspaces[i][j-1]-1-texts[j].size();
    }
  }
  for(int i = 0; i<texts.size();i++){
    for(int j = i; j<texts.size();j++){
      if(extraspaces[i][j] < 0){
        cost[i][j] = INFINITY;
      }
      else if(j == texts.size()-1 && extraspaces[i][j]>=0){
        cost[i][j] = 0;
      }
      else{
        cost[i][j] = pow(extraspaces[i][j],3);
      }
    }
  }
  for(int i = 1; i<=texts.size();i++){
    dp[i] = INFINITY;
    for(int j = max(1,i-M); j<=i;j++){
      if(cost[j-1][i-1] <= pow(M,3) && (dp[j-1] + cost[j-1][i-1] < dp[i])){
        dp[i] = dp[j-1]+cost[j-1][i-1];
        cut[i-1] = j-1;
      }
    }
  }
  int index = texts.size()-1;
  vector<vector<string> > ans;
  while(index >= 0){
    vector<string> b;
    int temp = index;
    index = cut[index];
    for(int i = index; i<=temp;i++){
      if(i == index){
        b.push_back(texts[i]);
      }
      else{
        b.push_back(" "+texts[i]);
      }
    }
    ans.push_back(b);
    index = index-1;
  }
  for(int i = ans.size()-1; i>=0;i--){
    for(string s: ans[i]){
      printf("%s",s.c_str() );
    }
    printf("\n");
  }
  printf("\n %d\n",dp[texts.size()]);
}

int main(){
  vector<string> texts;
  fstream file;
  string word, filename;
  filename = "buffyText.txt";
  file.open(filename.c_str());
  while (file >> word)
  {
      texts.push_back(word);
  }
  buffyText(texts,40);
  buffyText(texts,72);
}
