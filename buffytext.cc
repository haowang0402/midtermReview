#include <string>
#include <cmath>
#include <vector>
using namespace std;

int buffyText(vector<string> texts, int M){
    int remainingSpace = 0;
    vector<int> dp;
    dp.push_back(0);
    for(string s: texts){
      if(s.size() < remainingSpace){
        dp.push_back(dp[dp.size()-2]+(int)pow(remainingSpace,3));
        remainingSpace = remainingSpace-s.size()-1;
      }
      else{
        dp.push_back(dp[dp.size()-2]+(int)pow(remainingSpace,3));
        remainingSpace = M - s.size();
      }
    }
    return dp[texts.size()];
}

int main(){
  vector<string> texts;
  texts.push_back("I");
  texts.push_back("love");
  texts.push_back("play");
  texts.push_back("TF");
  int a = buffyText(texts,7);
  printf("%d\n",a);
}
