#include <string>
#include <cmath>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int buffyText(vector<string> texts, int M){
    int remainingSpace = 0;
    vector<int> dp;
    dp.push_back(0);
    for(string s: texts){
      if(s.size() < remainingSpace){
        dp.push_back(dp[dp.size()-1]);
        remainingSpace = remainingSpace-s.size();
        printf(" %s",s.c_str() );
      }
      else{
        if(dp.size()!=1){
          printf("\n");
        }
        dp.push_back(dp[dp.size()-2]+(int)pow(remainingSpace,3));
        remainingSpace = M - s.size();
        printf("%s",s.c_str());
      }
    }
    return dp[texts.size()];
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
  int a = buffyText(texts,40);
  printf("%d\n",a );
  int b = buffyText(texts,72);
  printf("%d\n",b );
}
