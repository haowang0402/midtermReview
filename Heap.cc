using namespace std;
#include <vector>
#include <iostream>
struct IndexMinHeap{
  vector<int> pq;
  vector<int> qp;
  vector<double> keys;
  int size;
  IndexMinHeap(){
    pq.push_back(-1);
    qp.push_back(-1);
    keys.push_back(-1);
  }

  void add(double key){
    keys.push_back(key);
    pq.push_back(keys.size()-1);
    qp.push_back(keys.size()-1);
    swim(keys.size()-1);
    size++;
  }

  void swim(int index){
    while(index!= 1){
      if(keys[pq[index]] < keys[pq[index/2]]){
        exch(index,index/2);
      }
      index = index/2;
    }
  }

  void heapify(){
    for(int i = size/2; i>=1; i--){
      if(2*i+1 <= size){
        if(keys[pq[2*i+1]] < keys[pq[i]]){
          exch(2*i+1,i);
        }
        if(keys[pq[2*i]] < keys[pq[i]]){
          exch(2*i,i);
        }
      }
      else if(2*i <= size){
        if(keys[pq[2*i]] < keys[pq[i]]){
          exch(2*i,i);
        }
      }
    }
  }
  void changeVal(int key, double val){
    keys[key] = val;
    heapify();
  }
  void exch(int v, int w){
    int temp = pq[w];
    pq[w] = pq[v];
    pq[v] = temp;
    qp[pq[v]] = v;
    qp[pq[w]] = w;
  }

  void printHeap(){
    for(int i = 1; i<pq.size(); i++){
      printf("%d\n",pq[i]);
    }
  }

  int extractMin(){
    exch(1, size);
    int id = pq[size];
    qp[id] = -1;
    pq[size] = -1;
    size--;
    heapify();
    return id;

  }
};

int main(){
  IndexMinHeap* h = new IndexMinHeap();
  h->add(0.0);
  h->add(0.4);
  h->add(0.3);
  h->add(0.2);
  h->add(0.7);
  h->changeVal(2,0.1);
  printf("%d\n",h->extractMin());
  printf("%d\n",h->extractMin());
  printf("%d\n",h->extractMin());
  printf("%d\n",h->extractMin());
  printf("%d\n",h->extractMin());
}
