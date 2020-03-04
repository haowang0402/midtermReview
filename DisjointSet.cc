using namespace std;
#include <vector>
struct DisjointSet{
  vector<int> sets;
  vector<int> rank;
  DisjointSet(int v){
    for(int i = 0; i<v; i++){
      sets.push_back(i);
      rank.push_back(0);
    }
  }
  int find(int v){
    while(sets[v]!=v){
      v = sets[v];
      sets[v] = find(v);
    }
    return v;
  }
  bool connected(int v, int w){
    return find(v) == find(w);
  }
  void link(int v, int w){
    if(rank[v] >= rank[w]){
      sets[w] = v;
      rank[v]++;
    }
    else{
      sets[v] = w;
      rank[w] ++;
    }
  }

  void unify(int v, int w){
    link(find(v),find(w));
  }

};

int main(){
  DisjointSet* set = new DisjointSet(7);
  set->unify(0,1);
  set->unify(1,5);
  set->unify(5,6);
  for(int i = 0; i<set->sets.size();i++){
    printf("%d\n",set->sets[i]);
  }
}
