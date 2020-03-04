#include <vector>
#include <queue>
using namespace std;
struct Edge{
  int v;
  int u;
  double weight;
  Edge(int v, int u,double weight){
    this->v = v;
    this->u = u;
    this->weight = weight;
  }
};
struct Graph{
  int v;
  vector<vector<Edge*> > edges;
  Graph(int v){
    this->v = v;
    for(int i = 0; i<v; i++){
      vector<Edge*> a;
      this->edges.push_back(a);
    }
  }
  void addEdge(int v, int w, double weight){
    this->edges[v].push_back(new Edge(v,w,weight));
  }
};
struct DFS{
  vector<int> preorder;
  vector<int> postorder;
  vector<bool> visted;
  Graph* g;
  vector<int> connectComponents;
  DFS(Graph* g){
    for(int i = 0; i< g->v; i++){
      visted.push_back(false);
      connectComponents.push_back(-1);
    }
    this->g = g;
  }
  void dfs(){
    for(int i = 0; i<this->g->v; i++){
      if(!visted[i]){
        search(i,i);
      }
    }
  }
  void search(int v, int id){
    visted[v] = true;
    preorder.push_back(v);
    connectComponents[v] = id;
    for(int i = 0; i<g->edges[v].size(); i++){
      Edge* e = g->edges[v][i];
      if(visted[e->u] == false){
        search(e->u,id);
      }
    }
    postorder.push_back(v);
  }

  int getPostorder(int v){
    for(int i  = 0; i<this->postorder.size(); i++){
      if(this->postorder[i] == v){
        return i;
      }
    }
    return -1;
  }
  int getPreorder(int v){
    for(int i = 0; i<this->preorder.size();i++){
      if(this->preorder[i] == v){
        return i;
      }
    }
    return -1;
  }
  bool detectCycle(){
    for(int i = 0; i < this->g->v; i++){
      vector<Edge*> edges = this->g->edges[i];
      for(Edge* e: edges){
        int v = e->v;
        int u = e->u;
        if(getPostorder(v) < getPostorder(u)){
          return true;
        }
      }
    }
    return false;
  }
  vector<int> topologicalSort(){
    return postorder;
  }
};

struct BFS{
  Graph* g;
  vector<bool> marked;
  vector<Edge*> edgeTo;
  int s;
  BFS(Graph* g, int s){
    this->g = g;
    for(int i = 0; i<g->v; i++){
      marked.push_back(false);
      edgeTo.push_back(new Edge(i,i,0.0));
    }
    this->s = s;
  }

  void bfs(){
    queue<int> queue;
    queue.push(this->s);
    marked[s] = true;
    while(!queue.empty()){
      int v = queue.front();
      queue.pop();
      vector<Edge*> edges = g->edges[v];
      for(int i = 0; i<edges.size();i++){
        int w = edges[i]->u;
        if(!marked[w]){
          marked[w] = true;
          edgeTo[w] = edges[i];
          queue.push(w);
        }
      }
    }
  }
  vector<Edge*> shortestPath(int w){
    vector<Edge*> shortest;
    if(marked[w]){
      while(w!=s){
        shortest.push_back(edgeTo[w]);
        w = edgeTo[w]->v;
      }
      return shortest;
    }
    else{
      return shortest;
    }
  }
};

int main(){
  Graph* g = new Graph(7);
  g->addEdge(0,1,0);
  g->addEdge(0,2,0);
  g->addEdge(1,3,0);
  g->addEdge(1,4,0);
  g->addEdge(2,5,0);
  DFS* d = new DFS(g);
  BFS* b = new BFS(g,0);
  d->dfs();
  b->bfs();
  for(Edge* e: b->shortestPath(5)){
    printf("%d\n",e->v);
  }
}
