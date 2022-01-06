#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> &visList, vector<int> adjList[]){
  cout << node << " "; visList[node] = 1;
  for(auto it : adjList[node]){
    if(visList[it] == 0){
      dfs(it, visList, adjList);
    }
  }
}

int main(void){

  int N, E; cin >> N >> E;
  vector<int> adjList[N];
  vector<int> visList(N, 0);

  for(int i=0; i<E; i++){
    int u, v; cin >> u >> v;
    adjList[u].push_back(v);
    adjList[v].push_back(u);
  }

  for(int i=0; i<N; i++){
    if(!visList[i]){
      dfs(i, visList, adjList);
      cout << endl;
    }
  }

  return 0;
}